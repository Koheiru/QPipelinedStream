#include "QHttpRequest.h"

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
QHttpRequest::QHttpRequest()
	: QHttpMessage()
	, m_method(QHttpMethod::UNKNOWN)
	, m_uri()
{
}

QHttpRequest::QHttpRequest(QHttpVersion::Version version, QHttpMethod::Method method, const QString& uri)
	: QHttpMessage()
	, m_method(method)
	, m_uri(QUrl(uri))
{
	setVersion(version);
}

QHttpRequest::QHttpRequest(QHttpVersion::Version version, QHttpMethod::Method method, const QUrl& uri)
	: QHttpMessage()
	, m_method(method)
	, m_uri(uri)
{
	setVersion(version);
}

QHttpRequest::~QHttpRequest()
{
}

void QHttpRequest::setMethod(QHttpMethod::Method method)
{
	m_method = method;
}

QHttpMethod::Method QHttpRequest::method() const
{
	return m_method;
}

void QHttpRequest::setUri(const QUrl& uri)
{
	m_uri = uri;
}

QUrl QHttpRequest::uri() const
{
	return m_uri;
}

