#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QThread>
#include <QtCore/QMetaObject>
#include <QtCore/QByteArray>
#include <QtNetwork/QTcpSocket>
#include <QtNetwork/QUdpSocket>
#include <QtTest/QTest>

#include <QTcpStream.h>
#include <QStreamHandler.h>

using namespace QPipelinedStream;


//=======================================================
//                  Class TestHandler
//=======================================================

class TestHandler: public QStreamHandler
{
public:
	TestHandler();
	virtual ~TestHandler();
	
public:
	void onOpened(QStream* stream) override;
	void onClosed(QStream* stream) override;
	void onErrorOccured(QStream* stream) override;
	void onDataRead(QStream* stream, QByteArray& data) override;
	void onDataWrite(QStream* stream, QByteArray& data) override;
	
private:
	const char* request = "GET /ip HTTP/1.1 \r\nHost: httpbin.org \r\nAccept: text/html \r\n\r\n";

};

//-------------------------------------------------------

TestHandler::TestHandler()
	: QStreamHandler()
{
}

TestHandler::~TestHandler()
{
}

void TestHandler::onOpened(QStream* stream)
{
	QVERIFY(stream != 0);
	
	stream->writeAndFlush(QByteArray(request));
}

void TestHandler::onClosed(QStream* stream)
{
	QVERIFY(stream != 0);
}

void TestHandler::onErrorOccured(QStream* stream)
{
	QVERIFY(stream != 0);
	QFAIL("TestHandler::onErrorOccured");
}

void TestHandler::onDataRead(QStream* stream, QByteArray& data)
{
	QVERIFY(stream != 0);
	
	const QString receivedData(data);
	QVERIFY(receivedData.startsWith("HTTP/1.1"));
}

void TestHandler::onDataWrite(QStream* stream, QByteArray& data)
{
	QVERIFY(stream != 0);
	
	const QString sendingData(data);
	const QString originalData(request);
	QCOMPARE(sendingData, originalData);
}


//=======================================================
//                      Class Test
//=======================================================

class Test: public QObject
{
	Q_OBJECT;
	
private Q_SLOTS:
	void simple();
	
};

void Test::simple()
{
	QTcpStream stream;
	stream.setOption(QAbstractSocket::LowDelayOption, 0);
	stream.setOption(QAbstractSocket::KeepAliveOption, 0);

	QStreamHandlerPtr handler(new TestHandler());
	stream.setHandler(handler);

	stream.open("httpbin.org", 80);
	QVERIFY(stream.waitForOpened());
	QVERIFY(stream.waitForClosed());
}


QTEST_MAIN(Test)
#include "test.moc"
