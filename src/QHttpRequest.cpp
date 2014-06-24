#include "QHttpRequest.h"

#include <QtCore/QMap>
#include <QtCore/QSharedData>

//=======================================================
//              Class QHttpRequestPrivate
//=======================================================
namespace QPipelinedStream
{

class QHttpRequestPrivate: public QSharedData
{
public:
	QHttpRequestPrivate();
	QHttpRequestPrivate(const QHttpRequestPrivate& other);
	virtual ~QHttpRequestPrivate();

public:
	QHttpMethod::Method method;
	QUrl uri;

};

//-------------------------------------------------------

QHttpRequestPrivate::QHttpRequestPrivate()
	: method(QHttpMethod::UNKNOWN)
	, uri("")
{
}

QHttpRequestPrivate::QHttpRequestPrivate(const QHttpRequestPrivate& other)
	: method(other.method)
	, uri(other.uri)
{
}

QHttpRequestPrivate::~QHttpRequestPrivate()
{
}

}


//=======================================================
//                 Class QHttpRequest
//=======================================================
using namespace QPipelinedStream;
using namespace QHttpVersion;
using namespace QHttpMethod;

QHttpRequest::QHttpRequest()
	: QHttpMessage()
	, d_ptr(new QHttpRequestPrivate)
{
}

QHttpRequest::QHttpRequest(Version version, Method method, const QString& uri)
	: QHttpMessage(version)
	, d_ptr(new QHttpRequestPrivate)
{
	setMethod(method);
	setUri(QUrl(uri));
}

QHttpRequest::QHttpRequest(Version version, Method method, const QUrl& uri)
	: QHttpMessage(version)
	, d_ptr(new QHttpRequestPrivate)
{
	setMethod(method);
	setUri(uri);
}

QHttpRequest::~QHttpRequest()
{
}

QHttpRequest::QHttpRequest(const QHttpRequest& other)
	: QHttpMessage(static_cast<const QHttpMessage&>(other))
	, d_ptr(other.d_ptr)
{
}

QHttpRequest& QHttpRequest::operator=(const QHttpRequest& other)
{
	if (&other != this)
	{
		d_ptr = other.d_ptr;
	}
	return *this;
}

Method QHttpRequest::method() const
{
	return d_ptr->method;
}

void QHttpRequest::setMethod(Method method)
{
	d_ptr->method = method;
}

QUrl QHttpRequest::uri() const
{
	return d_ptr->uri;
}

void QHttpRequest::setUri(const QUrl& uri)
{
	d_ptr->uri = uri;
}











