#pragma once

#include "QHttpMessage.h"
#include "QHttpStatus.h"


namespace QPipelinedStream
{

class QHttpResponse: public virtual QHttpMessage
{
public:
	QHttpResponse();
	QHttpResponse(QHttpVersion::Version version, QHttpStatus::Status status);
	QHttpResponse(QHttpVersion::Version version, QHttpStatus::Status status, const QString& reason);
	virtual ~QHttpResponse();

public:
	void setStatus(QHttpStatus::Status status);
	QHttpStatus::Status status() const;

	void setReason(const QString& reason);
	QString reason() const;

private:
	QHttpStatus::Status m_status;
	QString m_reason;
};

} //namespace QPipelinedStream
