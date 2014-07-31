#include "QHttpResponse.h"

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
QHttpResponse::QHttpResponse()
	: QHttpMessage()
	, m_status(QHttpStatus::UNKNOWN)
{

}

QHttpResponse::QHttpResponse(QHttpVersion::Version version, QHttpStatus::Status status)
	: QHttpMessage()
	, m_status(status)
	, m_reason(QHttpStatus::toString(status))
{
	setVersion(version);
}

QHttpResponse::QHttpResponse(QHttpVersion::Version version, QHttpStatus::Status status, const QString& reason)
	: QHttpMessage()
	, m_status(status)
	, m_reason(reason.isEmpty() ? QHttpStatus::toString(status) : reason)
{
	setVersion(version);
}

QHttpResponse::~QHttpResponse() 
{
}

void QHttpResponse::setStatus(QHttpStatus::Status status)
{
	m_status = status;
}

QHttpStatus::Status QHttpResponse::status() const
{
	return m_status;
}

void QHttpResponse::setReason(const QString& reason)
{
	m_reason = reason;
}

QString QHttpResponse::reason() const
{
	return m_reason;
}

