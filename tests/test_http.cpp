#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtTest/QTest>

#include "QStream.h"
#include "QHttpObjectDecoder.h"
#include "QHttpRequest.h"

using namespace QPipelinedStream;


//=======================================================
//                 Class QTestStream
//=======================================================

class QTestStream: public QStream
{
public:
	QTestStream();
	virtual ~QTestStream();

public:
	void setHandler(QStreamHandlerPtr handler) override;
	QStreamHandlerPtr handler() const override;

	void open() override;
	void close() override;
	bool isOpened() const override;

	bool waitForOpened(uint msecs = 5000) override;
	bool waitForClosed(uint msecs = 5000) override;

	void write(const QByteArray& data) override;
	void writeAndFlush(const QByteArray& data) override;
	void flush() override;

public:
	QHttpObject* m_sentObject;
	QHttpObject* m_receivedObject;

private:
	QStreamHandlerPtr m_handler;
};

//-------------------------------------------------------

QTestStream::QTestStream()
	: m_handler(nullptr)
	, m_sentObject(nullptr)
	, m_receivedObject(nullptr)
{
}

QTestStream::~QTestStream()
{
}

void QTestStream::setHandler(QStreamHandlerPtr handler)
{
	m_handler = handler;
}

QStreamHandlerPtr QTestStream::handler() const
{
	return m_handler;
}

void QTestStream::open()
{
}

void QTestStream::close()
{
}

bool QTestStream::isOpened() const
{
	return true;
}

bool QTestStream::waitForOpened(uint msecs)
{
	return true;
}

bool QTestStream::waitForClosed(uint msecs)
{
	return true;
}

void QTestStream::write(const QByteArray& data)
{
	//QVERIFY(false);
	m_sentObject = new QHttpRequest(QHttpVersion::HTTP_1_1, QHttpMethod::GET, "/example");
}

void QTestStream::writeAndFlush(const QByteArray& data)
{
	write(data);
	flush();
}

void QTestStream::flush()
{
}


//=======================================================
//                     Class Test
//=======================================================

class Test: public QObject
{
	Q_OBJECT;

public:
	Test() {}
	virtual ~Test() {}
	
private Q_SLOTS:
	void testRequestEncoder();
	
};

void Test::testRequestEncoder()
{
	QTestStream stream;

	QStreamHandlerPtr handler(new QHttpObjectDecoder);
	stream.setHandler(handler);

	stream.open();
	QVERIFY(stream.waitForOpened());

	QByteArray requestRaw = "GET /example HTTP/1.1\r\nHost: example.com\r\nAccept: text/html\r\nConnection: close\r\n\r\n";
	stream.writeAndFlush(requestRaw);

	QHttpObject* httpObject = stream.m_sentObject;
	QVERIFY(httpObject != 0);

	QHttpMessage* httpMessage = dynamic_cast<QHttpMessage*>(httpObject);
	QVERIFY(httpMessage != 0);
	QVERIFY(httpMessage->version() == QHttpVersion::HTTP_1_1);

	QHttpRequest* httpRequest = dynamic_cast<QHttpRequest*>(httpMessage);
	QVERIFY(httpRequest != 0);
	QVERIFY(httpRequest->method() == QHttpMethod::GET);
	QVERIFY(httpRequest->uri().path() == "/example");

	QVERIFY(stream.waitForClosed());
}


QTEST_MAIN(Test)
#include "test_http.moc"
