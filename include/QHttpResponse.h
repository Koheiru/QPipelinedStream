#pragma once

#include <QtCore/QSharedDataPointer>

#include "QHttpMessage.h"
#include "QHttpStatus.h"
#include "QHttpVersion.h"


namespace QPipelinedStream
{

class QHttpResponsePrivate;

class QHttpResponse: public QHttpMessage
{
public:
	QHttpResponse();
	QHttpResponse(QHttpVersion::Version version, QHttpStatus::Status status);
	virtual ~QHttpResponse();

public:
	QHttpResponse(const QHttpResponse& other);
	QHttpResponse& operator=(const QHttpResponse& other);

public:
	QHttpStatus::Status status() const;
	void setStatus(QHttpStatus::Status status);

private:
	QSharedDataPointer<QHttpResponsePrivate> d_ptr;

};

}
