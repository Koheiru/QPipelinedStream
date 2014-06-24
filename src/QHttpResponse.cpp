#include "QHttpResponse.h"

#include <QtCore/QSharedData>

//=======================================================
//              Class QHttpResponsePrivate
//=======================================================
namespace QPipelinedStream
{

class QHttpResponsePrivate: public QSharedData
{
public:
	QHttpResponsePrivate();
	QHttpResponsePrivate(const QHttpResponsePrivate& other);
	virtual ~QHttpResponsePrivate();

public:
	QHttpStatus::Status status;

};

//-------------------------------------------------------

QHttpResponsePrivate::QHttpResponsePrivate()
	: status(QHttpStatus::UNKNOWN)
{
}

QHttpResponsePrivate::QHttpResponsePrivate(const QHttpResponsePrivate& other)
	: status(other.status)
{
}

QHttpResponsePrivate::~QHttpResponsePrivate()
{
}

}


//=======================================================
//                 Class QHttpResponse
//=======================================================
using namespace QPipelinedStream;
using namespace QHttpVersion;
using namespace QHttpStatus;

QHttpResponse::QHttpResponse()
	: QHttpMessage()
	, d_ptr(new QHttpResponsePrivate)
{
}

QHttpResponse::QHttpResponse(Version version, Status status)
	: QHttpMessage(version)
	, d_ptr(new QHttpResponsePrivate)
{
	setStatus(status);
}

QHttpResponse::~QHttpResponse()
{
}

QHttpResponse::QHttpResponse(const QHttpResponse& other)
	: QHttpMessage(static_cast<const QHttpMessage&>(other))
	, d_ptr(other.d_ptr)
{
}

QHttpResponse& QHttpResponse::operator=(const QHttpResponse& other)
{
	if (&other != this)
	{
		d_ptr = other.d_ptr;
	}
	return *this;
}

Status QHttpResponse::status() const
{
	return d_ptr->status;
}

void QHttpResponse::setStatus(Status status)
{
	d_ptr->status = status;
}



