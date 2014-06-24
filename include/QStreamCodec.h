#pragma once

#include <QtCore/QByteArray>
#include <QtCore/QSharedPointer>

namespace QPipelinedStream
{

class QStream;

class QStreamHandler
{
public:
	virtual ~QStreamHandler() {}
	
public:
	virtual void onOpened(QStream* stream) = 0;
	virtual void onClosed(QStream* stream) = 0;
	virtual void onErrorOccured(QStream* stream) = 0;
	virtual void onDataRead(QStream* stream, QByteArray& data) = 0;
	virtual void onDataWrite(QStream* stream, QByteArray& data) = 0;
	
};

typedef QSharedPointer<QStreamHandler> QStreamHandlerPtr;

}