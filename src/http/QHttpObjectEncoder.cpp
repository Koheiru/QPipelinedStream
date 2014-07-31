#include "QHttpObjectEncoder.h"

#include "QHttpMessage.h"
#include "QHttpContent.h"
#include "QHttpTrailer.h"
#include <QtCore/QTextStream>

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
class QPipelinedStream::QHttpObjectEncoderPrivate
{
public:

public:
	QHttpObjectEncoder* q_ptr;
};


//-----------------------------------------------------------------------------
QHttpObjectEncoder::QHttpObjectEncoder()
	: QStreamEncoder<QHttpObject>()
	, d_ptr(new QHttpObjectEncoderPrivate)
{
	d_ptr->q_ptr = this;
}

QHttpObjectEncoder::~QHttpObjectEncoder()
{
}

void QHttpObjectEncoder::encode(QIODevice& input, QList<QHttpObject*>& output)
{
	Q_ASSERT(!"Not supported yet");
}

void QHttpObjectEncoder::reset()
{
	Q_ASSERT(!"Not supported yet");
}
