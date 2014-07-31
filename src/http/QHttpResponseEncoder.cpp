#include "QHttpResponseEncoder.h"

#include "QHttpVersion.h"
#include "QHttpStatus.h"
#include "QHttpResponse.h"

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
QHttpResponseEncoder::QHttpResponseEncoder()
	: QHttpObjectEncoder()
{
}

QHttpResponseEncoder::~QHttpResponseEncoder()
{
}

QString QHttpResponseEncoder::encodeInitLine(const QHttpMessage* message) const
{
	const QHttpResponse* response = dynamic_cast<const QHttpResponse*>(message);
	Q_ASSERT(response != 0);

	return QString();
}
