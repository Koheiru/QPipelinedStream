#include "QHttpResponseDecoder.h"

#include "QHttpVersion.h"
#include "QHttpStatus.h"
#include "QHttpResponse.h"
#include <QtCore/QStringList>

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
QHttpResponseDecoder::QHttpResponseDecoder()
	: QHttpObjectDecoder()
{
}

QHttpResponseDecoder::~QHttpResponseDecoder()
{
}

QHttpMessage* QHttpResponseDecoder::decodeInitLine(const QString& initLine) const
{
	const QStringList parts = initLine.split(' ', QString::SkipEmptyParts);
	if (parts.size() != 3)
	{
		return nullptr;
	}

	const QString versionName = parts.at(0);
	QHttpVersion::Version version = QHttpVersion::fromString(versionName);
	if (version == QHttpVersion::UNKNOWN)
	{
		return nullptr;
	}

	const QString statusCode = parts.at(1);
	QHttpStatus::Status status = QHttpStatus::fromString(statusCode);
	if (status == QHttpStatus::UNKNOWN)
	{
		return nullptr;
	}

	const QString statusName = parts.at(2);
	Q_UNUSED(statusName);

	return new QHttpResponse(version, status);
}

bool QHttpResponseDecoder::canContainsContent(QHttpMessage* message) const
{
	//! See: http://www.w3.org/Protocols/rfc2616/rfc2616-sec4.html#sec4.4

	QHttpResponse* response = dynamic_cast<QHttpResponse*>(message);
	Q_ASSERT(response != 0);
	
	const int code = (int)response->status();
	if (code == 204 || code == 205 || code == 304)
	{
		return false;
	}
	if (code > 99 && code < 200)
	{
		//! But with exception: Hixie 76 websocket handshake response.
		return (code == 101 && !response->isHeaderSet(QHttpHeader::Stuff::SEC_WEBSOCKET_ACCEPT));
	}

	return true;
}

