#pragma once

#include "../QStreamEncoder.h"
#include "QHttpObject.h"
#include <QtCore/QString>
#include <QtCore/QScopedPointer>


namespace QPipelinedStream
{

class QHttpMessage;
class QHttpObjectEncoderPrivate;

class QHttpObjectEncoder: public QStreamEncoder<QHttpObject>
{
public:
	QHttpObjectEncoder();
	virtual ~QHttpObjectEncoder();

public:
	void encode(QHttpObject* input, QIODevice& output) override;
	void reset() override;

protected:
	virtual QString encodeInitLine(const QHttpMessage* message) const = 0;

private:
	Q_DECLARE_PRIVATE(QHttpObjectEncoder);
	QScopedPointer<QHttpObjectEncoderPrivate> d_ptr;
};

} //namespace QPipelinedStream
