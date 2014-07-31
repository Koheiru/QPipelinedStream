#pragma once

#include "QHttpMessage.h"
#include "QHttpContent.h"
#include "QHttpTrailer.h"


namespace QPipelinedStream
{

class QFullHttpMessage: public virtual QHttpMessage,
						public QHttpContent,
						public QHttpTrailer
{
public:
	QFullHttpMessage();
	QFullHttpMessage(QHttpVersion::Version version);
	virtual ~QFullHttpMessage();

};

} //namespace QPipelinedStream
