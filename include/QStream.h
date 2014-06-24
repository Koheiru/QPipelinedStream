#pragma once

#include "QStreamHandler.h"

namespace QPipelinedStream
{

class QStream
{
public:
	virtual ~QStream() {}
	
public:
	virtual void setHandler(QStreamHandlerPtr handler) = 0;
	virtual QStreamHandlerPtr handler() const = 0;
	
	virtual void open() = 0;
	virtual void close() = 0;
	virtual bool isOpened() const = 0;
	
	virtual bool waitForOpened(uint msecs = 5000) = 0;
	virtual bool waitForClosed(uint msecs = 5000) = 0;

	virtual void write(const QByteArray& data) = 0;
	virtual void writeAndFlush(const QByteArray& data) = 0;
	virtual void flush() = 0;
	
};

}
