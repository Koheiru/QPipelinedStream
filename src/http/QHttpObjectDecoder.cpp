#include "QHttpObjectDecoder.h"

#include "QHttpMessage.h"
#include "QHttpContent.h"
#include "QHttpTrailer.h"
#include <QtCore/QTextStream>

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
static bool isChunkedEncoding(const QHttpMessage* message)
{
	const QString encoding = message->header(QHttpHeader::TRANSFER_ENCODING);
	return encoding.contains(QHttpHeader::Stuff::CHUNKED);
}

static bool isStreamEncoding(const QHttpMessage* message)
{
	return (!message->isHeaderSet(QHttpHeader::CONTENT_LENGTH) /*&& !isChunkedEncoding(message)*/);
}

//-----------------------------------------------------------------------------
enum DecoderState
{
	DecodeInitLine,
	DecodeHeaders,
	DecodeFixedContent,
	DecodeChunkedContent,
	DecodeStreamedContent,
};


//-----------------------------------------------------------------------------
class QPipelinedStream::QHttpObjectDecoderPrivate
{
public:
	void decode(QIODevice& input, QList<QHttpObject*>& output);
	void decodeInitLine(QIODevice& input, QList<QHttpObject*>& output);
	void decodeHeaders(QIODevice& input, QList<QHttpObject*>& output);
	void decodeFixedContent(QIODevice& input, QList<QHttpObject*>& output);
	void decodeChunkedContent(QIODevice& input, QList<QHttpObject*>& output);
	void decodeStreamedContent(QIODevice& input, QList<QHttpObject*>& output);
	void decodeTrailer(QIODevice& input, QList<QHttpObject*>& output);

public:
	QHttpObjectDecoder* q_ptr;
	DecoderState  m_state;
	QHttpMessage* m_message;
	qint64 m_contentSize;
};

void QHttpObjectDecoderPrivate::decode(QIODevice& input, QList<QHttpObject*>& output)
{
	switch (m_state)
	{
		case DecodeInitLine: decodeInitLine(input, output);	break;
		case DecodeHeaders:	 decodeHeaders(input, output); break;
		case DecodeFixedContent:    decodeFixedContent(input, output); break;
		case DecodeChunkedContent:  decodeChunkedContent(input, output); break;
		case DecodeStreamedContent: decodeStreamedContent(input, output); break;
		default: Q_ASSERT(!"Unknown decoder state.");
	}
}

void QHttpObjectDecoderPrivate::decodeInitLine(QIODevice& input, QList<QHttpObject*>& output)
{
	//! TODO: reimplement for using raw QIODevice calling because QTextStream
	// corrupt the QIODevice::pos result and call of the QTextStream::pos is
	// very expensive (see docs).

	QTextStream stream(&input);
	stream.seek(input.pos());
	while (true)
	{
		const quint64 pos = stream.pos();
		const QString line = stream.readLine();
		if (stream.status() != QTextStream::Ok || stream.pos() == pos)
		{
			stream.seek(pos);
			return;
		}

		if (!line.isEmpty())
		{
			m_message = q_ptr->decodeInitLine(line);
			m_state = DecodeHeaders;
			return;
		}
	}
}

void QHttpObjectDecoderPrivate::decodeHeaders(QIODevice& input, QList<QHttpObject*>& output)
{
	//! TODO: reimplement for using raw QIODevice calling because this code
	// include extra string convertions QString <=> QByteArray.

	QTextStream stream(&input);
	stream.seek(input.pos());
	while (true)
	{
		const quint64 pos = stream.pos();
		const QString line = stream.readLine();
		if (stream.status() != QTextStream::Ok || stream.pos() == pos)
		{
			stream.seek(pos);
			return;
		}

		if (line.isEmpty())
		{
			output.append(m_message);

			if (!q_ptr->canContainsContent(m_message))
			{
				output.append(new QHttpTrailer);
				q_ptr->reset();
				return;
			}

			if (isChunkedEncoding(m_message))
			{
				m_state = DecodeChunkedContent;
				return;
			}

			if (isStreamEncoding(m_message))
			{
				m_state = DecodeStreamedContent;
				return;
			}

			const QString length = m_message->header(QHttpHeader::CONTENT_LENGTH);
			m_contentSize = length.toLongLong();
			if (m_contentSize == 0)
			{
				output.append(new QHttpTrailer);
				q_ptr->reset();
				return;
			}

			m_state = DecodeFixedContent;
			return;
		}

		const QString header = line.section(':', 0, 0).trimmed();
		QByteArray value = line.section(':', 1, -1).trimmed().toUtf8();

		Q_ASSERT(!header.isEmpty());
		if (header.isEmpty())
		{
			continue;
		}

		if (m_message->isHeaderSet(header))
		{
			value = m_message->header(header) + ", " + value;
		}
		m_message->setHeader(header, value);
	}
}

void QHttpObjectDecoderPrivate::decodeFixedContent(QIODevice& input, QList<QHttpObject*>& output)
{
	const QByteArray data = input.read(m_contentSize);
	output.append(new QHttpContent(data));
	
	m_contentSize -= data.size();
	if (m_contentSize == 0)
	{
		output.append(new QHttpTrailer);
		q_ptr->reset();
	}
}

void QHttpObjectDecoderPrivate::decodeChunkedContent(QIODevice& input, QList<QHttpObject*>& output)
{
	if (m_contentSize == 0)
	{
		QTextStream stream(&input);
		stream.seek(input.pos());

		QString line = stream.readLine();
		m_contentSize = line.toLongLong();
		if (m_contentSize == 0)
		{
			decodeTrailer(input, output);
			q_ptr->reset();
			return;
		}
	}

	const QByteArray data = input.read(m_contentSize);
	output.append(new QHttpContent(data));

	m_contentSize -= data.size();
	if (m_contentSize != 0)
	{
		return;
	}

	//! Skip data while not '\r\n'.
	QTextStream stream(&input);
	stream.seek(input.pos());
	stream.readLine();
}

void QHttpObjectDecoderPrivate::decodeStreamedContent(QIODevice& input, QList<QHttpObject*>& output)
{
	const QByteArray data = input.readAll();
	output.append(new QHttpContent(data));

	if (!input.isOpen())
	{
		output.append(new QHttpTrailer);
		q_ptr->reset();
	}
}

void QHttpObjectDecoderPrivate::decodeTrailer(QIODevice& input, QList<QHttpObject*>& output)
{
	output.append(new QHttpTrailer);
}


//-----------------------------------------------------------------------------
QHttpObjectDecoder::QHttpObjectDecoder()
	: QStreamDecoder<QHttpObject>()
	, d_ptr(new QHttpObjectDecoderPrivate)
{
	d_ptr->q_ptr = this;
	d_ptr->m_state = DecodeInitLine;
}

QHttpObjectDecoder::~QHttpObjectDecoder()
{
}

void QHttpObjectDecoder::decode(QIODevice& input, QList<QHttpObject*>& output)
{
	for (;;)
	{
		qint64 pos = input.pos();
		d_ptr->decode(input, output);
		if (input.pos() == pos)
		{
			break;
		}
	}
}

void QHttpObjectDecoder::reset()
{
	d_ptr->m_state = DecodeInitLine;
	d_ptr->m_message = nullptr;
	d_ptr->m_contentSize = 0;
}
