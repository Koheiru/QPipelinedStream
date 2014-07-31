#pragma once

#include "QHttpObjectEncoder.h"


namespace QPipelinedStream
{

class QHttpRequestEncoder: public QHttpObjectEncoder
{
public:
	QHttpRequestEncoder();
	virtual ~QHttpRequestEncoder();

protected:
	QString encodeInitLine(const QHttpMessage* message) const override;

};

}
