#include "QFullHttpResponse.h"

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
QFullHttpResponse::QFullHttpResponse()
	: QFullHttpMessage()
	, QHttpResponse()
{
}

QFullHttpResponse::QFullHttpResponse(QHttpVersion::Version version, QHttpStatus::Status status)
	: QFullHttpMessage()
	, QHttpResponse()
{
	setVersion(version);
	setStatus(status);
}

QFullHttpResponse::~QFullHttpResponse()
{
}

