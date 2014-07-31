#include "QFullHttpRequest.h"

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
QFullHttpRequest::QFullHttpRequest()
	: QFullHttpMessage()
	, QHttpRequest()
{
}

QFullHttpRequest::QFullHttpRequest(QHttpVersion::Version version, QHttpMethod::Method method, const QString& uri)
	: QFullHttpMessage()
	, QHttpRequest()
{
	setVersion(version);
	setMethod(method);
	setUri(QUrl(uri));
}

QFullHttpRequest::QFullHttpRequest(QHttpVersion::Version version, QHttpMethod::Method method, const QUrl& uri)
	: QFullHttpMessage()
	, QHttpRequest()
{
	setVersion(version);
	setMethod(method);
	setUri(uri);
}

QFullHttpRequest::~QFullHttpRequest()
{
}


