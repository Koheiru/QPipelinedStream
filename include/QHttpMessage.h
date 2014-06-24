#pragma once

#include <QtCore/QString>
#include <QtCore/QSharedDataPointer>

#include "QHttpObject.h"
#include "QHttpVersion.h"
#include "QHttpHeader.h"


namespace QPipelinedStream
{

class QHttpMessagePrivate;

class QHttpMessage: public QHttpObject
{
public:
	QHttpMessage();
	QHttpMessage(QHttpVersion::Version version);
	virtual ~QHttpMessage();

public:
	QHttpMessage(const QHttpMessage& other);
	QHttpMessage& operator=(const QHttpMessage& other);

public:
	QHttpVersion::Version version() const;
	void setVersion(QHttpVersion::Version version);

public:
	bool isHeaderSet(const QString& header) const;
	bool isHeaderSet(QHttpHeader::Header header) const;
	
	QString header(const QString& header, const QString& defaultValue = QString()) const;
	QString header(QHttpHeader::Header header, const QString& defaultValue = QString()) const;

	void setHeader(const QString& header, const QString& value);
	void setHeader(QHttpHeader::Header header, const QString& value);

	void removeHeader(const QString& header);
	void removeHeader(QHttpHeader::Header header);

private:
	QSharedDataPointer<QHttpMessagePrivate> d_ptr;

};

}
