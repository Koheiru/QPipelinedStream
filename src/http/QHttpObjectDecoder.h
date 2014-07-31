#pragma once

#include "../QStreamDecoder.h"
#include "QHttpObject.h"
#include <QtCore/QString>
#include <QtCore/QScopedPointer>


namespace QPipelinedStream
{

class QHttpMessage;
class QHttpObjectDecoderPrivate;

class QHttpObjectDecoder: public QStreamDecoder<QHttpObject>
{
public:
	QHttpObjectDecoder();
	virtual ~QHttpObjectDecoder();

public:
	void decode(QIODevice& input, QList<QHttpObject*>& output) override;
	void reset() override;

protected:
	virtual QHttpMessage* decodeInitLine(const QString& initLine) const = 0;
	virtual bool canContainsContent(QHttpMessage* message) const { return true; }

private:
	Q_DECLARE_PRIVATE(QHttpObjectDecoder);
	QScopedPointer<QHttpObjectDecoderPrivate> d_ptr;
};

} //namespace QPipelinedStream
