#pragma once

#include "QHttpObjectEncoder.h"


namespace QPipelinedStream
{

class QHttpResponseEncoder: public QHttpObjectEncoder
{
public:
	QHttpResponseEncoder();
	virtual ~QHttpResponseEncoder();

protected:
	QString encodeInitLine(const QHttpMessage* message) const override;

};

}
