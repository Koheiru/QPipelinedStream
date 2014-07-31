#include "QFullHttpMessage.h"

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
QFullHttpMessage::QFullHttpMessage()
	: QHttpMessage()
	, QHttpContent()
	, QHttpTrailer()
{
}

QFullHttpMessage::QFullHttpMessage(QHttpVersion::Version version)
	: QHttpMessage()
	, QHttpContent()
	, QHttpTrailer()
{
	setVersion(version);
}

QFullHttpMessage::~QFullHttpMessage()
{
}

