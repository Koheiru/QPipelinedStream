#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QByteArray>
#include <QtCore/QBuffer>
#include <QtTest/QTest>

#include "../src/QStream.h"
#include "../src/http/QHttpObject.h"
#include "../src/http/QHttpContent.h"
#include "../src/http/QHttpTrailer.h"
#include "../src/http/QHttpMessage.h"
#include "../src/http/QHttpRequest.h"
#include "../src/http/QHttpResponse.h"
#include "../src/http/QFullHttpMessage.h"
#include "../src/http/QFullHttpRequest.h"
#include "../src/http/QFullHttpResponse.h"
#include "../src/http/QHttpRequestDecoder.h"

using namespace QPipelinedStream;


//-----------------------------------------------------------------------------
class HttpTest: public QObject
{
	Q_OBJECT;

public:
	HttpTest() {}
	virtual ~HttpTest() {}
	
private Q_SLOTS:
	void testClasses();
	void testRequestDecoder();
	void testRequestEncoder();
};


//-----------------------------------------------------------------------------
void HttpTest::testClasses()
{
	//QVERIFY(false);
	{
		QHttpContent httpContent(QByteArray("content_1"));

		QHttpObject* httpObject = static_cast<QHttpObject*>(&httpContent);

		QVERIFY(dynamic_cast<QHttpContent*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpContent*>(httpObject)->content() == QByteArray("content_1"));

		dynamic_cast<QHttpContent*>(httpObject)->setContent(QByteArray("content_2"));
		QVERIFY(httpContent.content() == QByteArray("content_2"));
	}
	
	{
		QHttpTrailer httpTrailer;
		httpTrailer.setHeader(QHttpHeader::LOCATION, QByteArray("Earth"));

		QHttpObject* httpObject = static_cast<QHttpObject*>(&httpTrailer);

		QVERIFY(dynamic_cast<QHttpTrailer*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpTrailer*>(httpObject)->header(QHttpHeader::LOCATION) == QByteArray("Earth"));

		dynamic_cast<QHttpTrailer*>(httpObject)->setHeader("Custom", QByteArray("custom"));
		QVERIFY(httpTrailer.header("Custom") == QByteArray("custom"));
	}

	{
		QHttpMessage httpMessage(QHttpVersion::HTTP_1_1);
		httpMessage.setHeader(QHttpHeader::LOCATION, QByteArray("Earth"));

		QHttpObject* httpObject = static_cast<QHttpObject*>(&httpMessage);

		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject)->version() == QHttpVersion::HTTP_1_1);
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject)->header(QHttpHeader::LOCATION) == QByteArray("Earth"));

		dynamic_cast<QHttpMessage*>(httpObject)->setVersion(QHttpVersion::HTTP_1_0);
		QVERIFY(httpMessage.version() == QHttpVersion::HTTP_1_0);

		dynamic_cast<QHttpMessage*>(httpObject)->setHeader("Custom", QByteArray("custom"));
		QVERIFY(httpMessage.header("Custom") == QByteArray("custom"));
	}

	{
		QHttpRequest httpRequest(QHttpVersion::HTTP_1_1, QHttpMethod::GET, "www.example.com");
		httpRequest.setHeader(QHttpHeader::LOCATION, QByteArray("Earth"));

		QHttpObject* httpObject = static_cast<QHttpObject*>(&httpRequest);

		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject)->version() == QHttpVersion::HTTP_1_1);
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject)->header(QHttpHeader::LOCATION) == QByteArray("Earth"));

		dynamic_cast<QHttpRequest*>(httpObject)->setVersion(QHttpVersion::HTTP_1_0);
		QVERIFY(httpRequest.version() == QHttpVersion::HTTP_1_0);

		dynamic_cast<QHttpRequest*>(httpObject)->setMethod(QHttpMethod::CONNECT);
		QVERIFY(httpRequest.method() == QHttpMethod::CONNECT);

		dynamic_cast<QHttpRequest*>(httpObject)->setUri(QUrl("www.custom.com"));
		QVERIFY(httpRequest.uri() == QUrl("www.custom.com"));

		dynamic_cast<QHttpRequest*>(httpObject)->setHeader("Custom", QByteArray("custom"));
		QVERIFY(httpRequest.header("Custom") == QByteArray("custom"));
	}

	{
		QHttpResponse httpResponse(QHttpVersion::HTTP_1_1, QHttpStatus::OK);
		httpResponse.setHeader(QHttpHeader::LOCATION, QByteArray("Earth"));

		QHttpObject* httpObject = static_cast<QHttpObject*>(&httpResponse);

		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject)->version() == QHttpVersion::HTTP_1_1);
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject)->header(QHttpHeader::LOCATION) == QByteArray("Earth"));

		dynamic_cast<QHttpResponse*>(httpObject)->setStatus(QHttpStatus::ACCEPTED);
		QVERIFY(httpResponse.status() == QHttpStatus::ACCEPTED);

		dynamic_cast<QHttpResponse*>(httpObject)->setVersion(QHttpVersion::HTTP_1_0);
		QVERIFY(httpResponse.version() == QHttpVersion::HTTP_1_0);

		dynamic_cast<QHttpResponse*>(httpObject)->setHeader("Custom", QByteArray("custom"));
		QVERIFY(httpResponse.header("Custom") == QByteArray("custom"));
	}

	{
		QFullHttpMessage fullMessage(QHttpVersion::HTTP_1_1);
		fullMessage.setHeader(QHttpHeader::LOCATION, QByteArray("Earth"));
		fullMessage.setContent(QByteArray("content"));

		QHttpObject* httpObject = static_cast<QHttpObject*>(&fullMessage);

		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject)->version() == QHttpVersion::HTTP_1_1);
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject)->header(QHttpHeader::LOCATION) == QByteArray("Earth"));

		QVERIFY(dynamic_cast<QHttpContent*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpContent*>(httpObject)->content() == QByteArray("content"));

		QVERIFY(dynamic_cast<QHttpTrailer*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpTrailer*>(httpObject)->header(QHttpHeader::LOCATION) == QByteArray("Earth"));
	}

	{
		QFullHttpRequest fullRequest(QHttpVersion::HTTP_1_1, QHttpMethod::GET, "www.example.com");
		fullRequest.setHeader(QHttpHeader::LOCATION, QByteArray("Earth"));
		fullRequest.setContent(QByteArray("content"));

		QHttpObject* httpObject = static_cast<QHttpObject*>(&fullRequest);

		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject)->version() == QHttpVersion::HTTP_1_1);
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject)->header(QHttpHeader::LOCATION) == QByteArray("Earth"));

		QVERIFY(dynamic_cast<QHttpRequest*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpRequest*>(httpObject)->version() == QHttpVersion::HTTP_1_1);
		QVERIFY(dynamic_cast<QHttpRequest*>(httpObject)->method() == QHttpMethod::GET);
		QVERIFY(dynamic_cast<QHttpRequest*>(httpObject)->uri() == QUrl("www.example.com"));
		QVERIFY(dynamic_cast<QHttpRequest*>(httpObject)->header(QHttpHeader::LOCATION) == QByteArray("Earth"));

		QVERIFY(dynamic_cast<QHttpContent*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpContent*>(httpObject)->content() == QByteArray("content"));

		QVERIFY(dynamic_cast<QHttpTrailer*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpTrailer*>(httpObject)->header(QHttpHeader::LOCATION) == QByteArray("Earth"));
	}

	{
		QFullHttpResponse fullResponse(QHttpVersion::HTTP_1_1, QHttpStatus::OK);
		fullResponse.setHeader(QHttpHeader::LOCATION, QByteArray("Earth"));
		fullResponse.setContent(QByteArray("content"));

		QHttpObject* httpObject = static_cast<QHttpObject*>(&fullResponse);
		
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject)->version() == QHttpVersion::HTTP_1_1);
		QVERIFY(dynamic_cast<QHttpMessage*>(httpObject)->header(QHttpHeader::LOCATION) == QByteArray("Earth"));

		QVERIFY(dynamic_cast<QHttpResponse*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpResponse*>(httpObject)->version() == QHttpVersion::HTTP_1_1);
		QVERIFY(dynamic_cast<QHttpResponse*>(httpObject)->status() == QHttpStatus::OK);
		QVERIFY(dynamic_cast<QHttpResponse*>(httpObject)->header(QHttpHeader::LOCATION) == QByteArray("Earth"));

		QVERIFY(dynamic_cast<QHttpContent*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpContent*>(httpObject)->content() == QByteArray("content"));

		QVERIFY(dynamic_cast<QHttpTrailer*>(httpObject) != 0);
		QVERIFY(dynamic_cast<QHttpTrailer*>(httpObject)->header(QHttpHeader::LOCATION) == QByteArray("Earth"));
	}
}


//-----------------------------------------------------------------------------
void HttpTest::testRequestDecoder()
{
	QScopedPointer<QHttpRequestDecoder> decoder(new QHttpRequestDecoder);
	QByteArray requestData = "GET /example HTTP/1.1\r\n"
							"Host: example.com\r\n"
							"Accept: text/html\r\n"
							"Content-Length: 38\r\n"
							"Connection: close\r\n"
							"\r\n"
							"<html><body>Hello World!</body></html>";
	
	QList<QHttpObject*> httpObjects;
	{
		QBuffer stream(&requestData);
		stream.open(QIODevice::ReadOnly);
		decoder->decode(stream, httpObjects);
		stream.close();
	}

	QVERIFY(httpObjects.size() > 0);
	{
		const QHttpObject* httpObject = httpObjects.at(0);
		const QHttpRequest* httpRequest = dynamic_cast<const QHttpRequest*>(httpObject);
		QVERIFY(httpRequest != 0);
		QVERIFY(httpRequest->version() == QHttpVersion::HTTP_1_1);
		QVERIFY(httpRequest->method() == QHttpMethod::GET);
		QVERIFY(httpRequest->uri() == QUrl("/example"));
		QVERIFY(httpRequest->header(QHttpHeader::ACCEPT) == "text/html");
		QVERIFY(httpRequest->header(QHttpHeader::CONTENT_LENGTH) == "38");
		QVERIFY(httpRequest->header(QHttpHeader::CONNECTION) == "close");
	}

	QVERIFY(httpObjects.size() > 1);
	{
		const QHttpObject* httpObject = httpObjects.at(1);
		const QHttpContent* httpContent = dynamic_cast<const QHttpContent*>(httpObject);
		QVERIFY(httpContent != 0);
		QVERIFY(httpContent->content() == "<html><body>Hello World!</body></html>");
	}

	QVERIFY(httpObjects.size() > 2);
	{
		const QHttpObject* httpObject = httpObjects.at(2);
		const QHttpTrailer* httpTrailer = dynamic_cast<const QHttpTrailer*>(httpObject);
		QVERIFY(httpTrailer != 0);
		QVERIFY(httpTrailer->headers().isEmpty());
	}

	QVERIFY(httpObjects.size() == 3);
}


//-----------------------------------------------------------------------------
void HttpTest::testRequestEncoder()
{
	/*
	QScopedPointer<QHttpRequestEncoder> handler(new QHttpRequestEncoder);

	QHttpRequest request(QHttpVersion::HTTP_1_1, QHttpMethod::GET, "http://example.com");
	request.setHeader(QHttpHeader::ACCEPT, "text/html");
	request.setHeader(QHttpHeader::CONNECTION, "close");

	QByteArray contentData("{\"origin\": \"24.127.96.129\"}\r\n");
	QHttpContent content(contentData);

	QByteArray data;
	handler->encode(request, data);
	handler->encode(content, data);

	QString encodedString(data);
	QString expectedString = "GET http://example.com/ HTTP/1.1\r\nAccept: text/html\r\nConnection: close\r\n\r\n{\"origin\": \"24.127.96.129\"}\r\n";
	QVERIFY(encodedString == expectedString);
	*/
}


QTEST_MAIN(HttpTest)
#include "test_http.moc"
