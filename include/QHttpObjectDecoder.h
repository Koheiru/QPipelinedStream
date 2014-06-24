#pragma once

#include "QStreamHandler.h"

namespace QPipelinedStream
{

class QHttpObjectDecoder : public QStreamHandler
{
public:
	QHttpObjectDecoder();
	virtual ~QHttpObjectDecoder();

public:
	void onOpened(QStream* stream) override;
	void onClosed(QStream* stream) override;
	void onErrorOccured(QStream* stream) override;
	void onDataRead(QStream* stream, QByteArray& data, QList<Object>& out) override;
	void onDataWrite(QStream* stream, QByteArray& data, QList<Object>& out) override;

};

}

/*
#include <QtCore/QList>
#include <QtCore/QString>

#include "QStreamHandler.h"

namespace QPipelinedStream
{

class QHttpMessage;
class QHttpObjectDecoderImpl;

class QHttpObjectDecoder: public QStreamHandler
{
public:
	QHttpObjectDecoder();
	virtual ~QHttpObjectDecoder();
	
public:
	void onOpened(QStream* stream) override;
	void onClosed(QStream* stream) override;
	void onErrorOccured(QStream* stream) override;
	void onDataRead(QStream* stream, QByteArray& data, QList<Object>& out) override;
	void onDataWrite(QStream* stream, QByteArray& data, QList<Object>& out) override;

protected:
	virtual QHttpMessage* createMessage(const QStringList& initialLineParts) = 0;

private:
	QHttpObjectDecoderImpl* m_impl;

};

}
*/
