#include "QHttpRequestEncoder.h"

#include "QHttpVersion.h"
#include "QHttpMethod.h"
#include "QHttpRequest.h"

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
QHttpRequestEncoder::QHttpRequestEncoder()
	: QHttpObjectEncoder()
{
}

QHttpRequestEncoder::~QHttpRequestEncoder()
{
}

QString QHttpRequestEncoder::encodeInitLine(const QHttpMessage* message) const
{
	const QHttpRequest* request = dynamic_cast<const QHttpRequest*>(message);
	Q_ASSERT(request != 0);

	return QString();
}

