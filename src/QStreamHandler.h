#pragma once

#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QtCore/QSharedPointer>

namespace QPipelinedStream
{

class QStream;

class StreamObject
{
public:
	virtual ~StreamObject() {}
};

typedef QList<StreamObject*> StreamObjectList;

/*
template <typename T>
class StreamObjectW : public T, public StreamObject
{};
*/


class QStreamHandler
{
public:
	virtual ~QStreamHandler() {}
	
public:
	virtual void onOpened(QStream* stream) = 0;
	virtual void onClosed(QStream* stream) = 0;
	virtual void onErrorOccured(QStream* stream) = 0;
	virtual void onDataRead(QStream* stream, const QByteArray& data, StreamObjectList& out) = 0;
	virtual void onDataWrite(QStream* stream, const StreamObject& object, QByteArray& out) = 0;
	
};

typedef QSharedPointer<QStreamHandler> QStreamHandlerPtr;

}
