#pragma once

#include "QHttpObjectDecoder.h"


namespace QPipelinedStream
{

class QHttpRequestDecoder: public QHttpObjectDecoder
{
public:
	QHttpRequestDecoder();
	virtual ~QHttpRequestDecoder();

protected:
	QHttpMessage* decodeInitLine(const QString& initLine) const override;

};

}
