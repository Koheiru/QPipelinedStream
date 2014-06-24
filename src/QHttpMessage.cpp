#include "QHttpMessage.h"

#include <QtCore/QMap>
#include <QtCore/QSharedData>

//=======================================================
//              Class QHttpMessagePrivate
//=======================================================
namespace QPipelinedStream
{

class QHttpMessagePrivate: public QSharedData
{
public:
	QHttpMessagePrivate();
	QHttpMessagePrivate(const QHttpMessagePrivate& other);
	virtual ~QHttpMessagePrivate();

public:
	QMap<QString, QString> headers;
	QHttpVersion::Version version;

};

//-------------------------------------------------------

QHttpMessagePrivate::QHttpMessagePrivate()
	: headers()
	, version(QHttpVersion::UNKNOWN)
{
}

QHttpMessagePrivate::QHttpMessagePrivate(const QHttpMessagePrivate& other)
	: headers(other.headers)
	, version(other.version)
{
}

QHttpMessagePrivate::~QHttpMessagePrivate()
{
}

}


//=======================================================
//                 Class QHttpMessage
//=======================================================
using namespace QPipelinedStream;
using namespace QHttpVersion;
using namespace QHttpHeader;

QHttpMessage::QHttpMessage()
	: QHttpObject()
	, d_ptr(new QHttpMessagePrivate)
{
}

QHttpMessage::QHttpMessage(QHttpVersion::Version version)
	: QHttpObject()
	, d_ptr(new QHttpMessagePrivate)
{
	setVersion(version);
}

QHttpMessage::~QHttpMessage()
{
}

QHttpMessage::QHttpMessage(const QHttpMessage& other)
	: QHttpObject()
	, d_ptr(other.d_ptr)
{
}

QHttpMessage& QHttpMessage::operator=(const QHttpMessage& other)
{
	if (&other != this)
	{
		d_ptr = other.d_ptr;
	}
	return *this;
}

Version QHttpMessage::version() const
{
	return d_ptr->version;
}

void QHttpMessage::setVersion(Version version)
{
	d_ptr->version = version;
}

bool QHttpMessage::isHeaderSet(const QString& header) const
{
	return d_ptr->headers.contains(header);
}

bool QHttpMessage::isHeaderSet(Header header) const
{
	return isHeaderSet(toString(header));
}

QString QHttpMessage::header(const QString& header, const QString& defaultValue) const
{
	return d_ptr->headers.value(header, defaultValue);
}

QString QHttpMessage::header(Header header, const QString& defaultValue) const
{
	return this->header(toString(header), defaultValue);
}

void QHttpMessage::setHeader(const QString& header, const QString& value)
{
	d_ptr->headers[header] = value;
}

void QHttpMessage::setHeader(Header header, const QString& value)
{
	setHeader(toString(header), value);
}

void QHttpMessage::removeHeader(const QString& header)
{
	d_ptr->headers.remove(header);
}

void QHttpMessage::removeHeader(QHttpHeader::Header header)
{
	removeHeader(toString(header));
}

