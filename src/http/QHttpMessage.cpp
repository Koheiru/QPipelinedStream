#include "QHttpMessage.h"

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
QHttpMessage::QHttpMessage()
	: QHttpObject()
	, QHttpHeaders()
	, m_version(QHttpVersion::UNKNOWN)
{
}

QHttpMessage::QHttpMessage(QHttpVersion::Version version)
	: QHttpObject()
	, QHttpHeaders()
	, m_version(version)
{
}

QHttpMessage::~QHttpMessage()
{
}

QHttpVersion::Version QHttpMessage::version() const
{
	return m_version;
}

void QHttpMessage::setVersion(QHttpVersion::Version version)
{
	m_version = version;
}

