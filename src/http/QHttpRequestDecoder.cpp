#include "QHttpRequestDecoder.h"

#include "QHttpVersion.h"
#include "QHttpMethod.h"
#include "QHttpRequest.h"
#include <QtCore/QStringList>

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
QHttpRequestDecoder::QHttpRequestDecoder()
	: QHttpObjectDecoder()
{
}

QHttpRequestDecoder::~QHttpRequestDecoder()
{
}

QHttpMessage* QHttpRequestDecoder::decodeInitLine(const QString& initLine) const
{
	const QStringList parts = initLine.split(' ', QString::SkipEmptyParts);
	if (parts.size() != 3)
	{
		return nullptr;
	}

	const QString methodName = parts.at(0);
	QHttpMethod::Method method = QHttpMethod::fromString(methodName);
	if (method == QHttpMethod::UNKNOWN)
	{
		return nullptr;
	}

	const QString uri = parts.at(1);
	if (uri.isEmpty())
	{
		return nullptr;
	}

	const QString versionName = parts.at(2);
	QHttpVersion::Version version = QHttpVersion::fromString(versionName);
	if (version == QHttpVersion::UNKNOWN)
	{
		return nullptr;
	}

	return new QHttpRequest(version, method, uri);
}
