#pragma once

#include "QFullHttpMessage.h"
#include "QHttpResponse.h"


namespace QPipelinedStream
{

class QFullHttpResponse: public QFullHttpMessage, 
						 public QHttpResponse
{
public:
	QFullHttpResponse();
	QFullHttpResponse(QHttpVersion::Version version, QHttpStatus::Status status);
	virtual ~QFullHttpResponse();

};

} //namespace QPipelinedStream
