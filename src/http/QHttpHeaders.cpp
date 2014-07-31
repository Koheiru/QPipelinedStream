#include "QHttpHeaders.h"

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
QHttpHeaders::QHttpHeaders()
	: QHttpObject()
	, m_headers()
{
}

QHttpHeaders::QHttpHeaders(QMap<QString, QByteArray> headersValues)
	: QHttpObject()
	, m_headers(headersValues)
{
}

QHttpHeaders::~QHttpHeaders()
{
}

QList<QString> QHttpHeaders::headers() const
{
	return m_headers.uniqueKeys();
}

QMap<QString, QByteArray> QHttpHeaders::headersValues() const
{
	return m_headers;
}

bool QHttpHeaders::isHeaderSet(const QString& header) const
{
	return m_headers.contains(header);
}

bool QHttpHeaders::isHeaderSet(QHttpHeader::Header header) const
{
	return isHeaderSet(toString(header));
}

QByteArray QHttpHeaders::header(const QString& header, const QByteArray& defaultValue) const
{
	return m_headers.value(header, defaultValue);
}

QByteArray QHttpHeaders::header(QHttpHeader::Header header, const QByteArray& defaultValue) const
{
	return this->header(toString(header), defaultValue);
}

void QHttpHeaders::setHeader(const QString& header, const QByteArray& value)
{
	m_headers[header] = value;
}

void QHttpHeaders::setHeader(QHttpHeader::Header header, const QByteArray& value)
{
	setHeader(toString(header), value);
}

void QHttpHeaders::removeHeader(const QString& header)
{
	m_headers.remove(header);
}

void QHttpHeaders::removeHeader(QHttpHeader::Header header)
{
	removeHeader(toString(header));
}


