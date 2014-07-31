#pragma once

#include "QHttpObjectDecoder.h"


namespace QPipelinedStream
{

class QHttpResponseDecoder: public QHttpObjectDecoder
{
public:
	QHttpResponseDecoder();
	virtual ~QHttpResponseDecoder();

protected:
	QHttpMessage* decodeInitLine(const QString& initLine) const override;
	bool canContainsContent(QHttpMessage* message) const override;

};

}
