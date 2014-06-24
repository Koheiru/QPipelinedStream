#include "QHttpObjectDecoder.h"

using namespace QPipelinedStream;


//=======================================================
//            Class QHttpObjectDecoder
//=======================================================
QHttpObjectDecoder::QHttpObjectDecoder()
	: QStreamHandler()
{
}

QHttpObjectDecoder::~QHttpObjectDecoder()
{
}

void QHttpObjectDecoder::onOpened(QStream* stream)
{
}

void QHttpObjectDecoder::onClosed(QStream* stream)
{
}

void QHttpObjectDecoder::onErrorOccured(QStream* stream)
{
}

void QHttpObjectDecoder::onDataRead(QStream* stream, QByteArray& data, QList<Object>& out)
{
}

void QHttpObjectDecoder::onDataWrite(QStream* stream, QByteArray& data, QList<Object>& out)
{
}



/*
using namespace QPipelinedStream;


//-------------------------------------------------------
enum ParseState
{
	ParseStartLine,
	ParseMessageHeader,
	ParseMessageBody,
	ParseTailingHeader,
};


//=======================================================
//            Class QHttpRequestDecoderImpl
//=======================================================
class QHttpObjectDecoderImpl
{
public:
	QHttpObjectDecoderImpl() : state(ParseStartLine) {}
	~QHttpObjectDecoderImpl() {}

public:
	void parseStartLine(QByteArray& data, QList<Object>& out);
	void parseMessageHeader(QByteArray& data, QList<Object>& out);
	void parseMessageBody(QByteArray& data, QList<Object>& out);
	void parseTailingHeader(QByteArray& data, QList<Object>& out);

public:
	ParseState state;

};

//-------------------------------------------------------

void QHttpObjectDecoderImpl::parseStartLine(QByteArray& data, QList<Object>& out)
{
	QStringList partsList;

	int partBegin = 0;
	int partEnd = 1;
	while (partEnd < data.size() && !(data[partEnd - 1] == '\r' && data[partEnd] == '\n'))
	{
		if (data[partEnd - 1] == ' ')
		{
			const char* str = data.constData() + partBegin;
			const int length = partEnd - partBegin - 1;
			const QString part = QString::fromUtf8(str, length);
			partsList.append(part);

			partBegin = partEnd;
		}
		++partEnd;
	}

	const char* str = data.constData() + partBegin;
	const int length = partEnd - partBegin - 1;
	const QString part = QString::fromUtf8(str, length);
	partsList.append(part);

	const int remaind = data.size() - partEnd - 1;
	data = data.right(remaind);

	QHttpMessage* message = createMessage(partsList);
	if (!message)
	{
		return;
	}

	state = ParseMessageHeader;
	out.append(message);
}

void QHttpObjectDecoderImpl::parseMessageHeader(QByteArray& data, QList<Object>& out)
{
}

void QHttpObjectDecoderImpl::parseMessageBody(QByteArray& data, QList<Object>& out)
{
}

void QHttpObjectDecoderImpl::parseTailingHeader(QByteArray& data, QList<Object>& out)
{
}


//=======================================================
//              Class QHttpRequestDecoder
//=======================================================
QHttpObjectDecoder::QHttpObjectDecoder()
	: QStreamHandler()
	, m_impl(new QHttpObjectDecoderImpl);
{
}

QHttpObjectDecoder::~QHttpObjectDecoder()
{
	delete m_impl;
}

void QHttpObjectDecoder::onOpened(QStream* stream)
{
}

void QHttpObjectDecoder::onClosed(QStream* stream)
{
}

void QHttpObjectDecoder::onErrorOccured(QStream* stream)
{
}

void QHttpObjectDecoder::onDataRead(QStream* stream, QByteArray& data, QList<Object>& out)
{
	if (m_impl->state == ParseStartLine)          { m_impl->parseStartLine(data, out); }
	else if (m_impl->state == ParseMessageHeader) { m_impl->parseMessageHeader(data, out); }
	else if (m_impl->state == ParseMessageBody)   { m_impl->parseMessageBody(data, out); }
	else if (m_impl->state == ParseTailingHeader) { m_impl->parseTailingHeader(data, out); }
}

void QHttpObjectDecoder::onDataWrite(QStream* stream, QByteArray& data, QList<Object>& out)
{
}

*/
	