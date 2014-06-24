#pragma once

#include <QtCore/QUrl>
#include <QtCore/QSharedDataPointer>

#include "QHttpMessage.h"
#include "QHttpMethod.h"
#include "QHttpVersion.h"


namespace QPipelinedStream
{

class QHttpRequestPrivate;

class QHttpRequest: public QHttpMessage
{
public:
	QHttpRequest();
	QHttpRequest(QHttpVersion::Version version, QHttpMethod::Method method, const QString& uri);
	QHttpRequest(QHttpVersion::Version version, QHttpMethod::Method method, const QUrl& uri);
	virtual ~QHttpRequest();

public:
	QHttpRequest(const QHttpRequest& other);
	QHttpRequest& operator=(const QHttpRequest& other);

public:
	QHttpMethod::Method method() const;
	void setMethod(QHttpMethod::Method method);

	QUrl uri() const;
	void setUri(const QUrl& uri);

private:
	QSharedDataPointer<QHttpRequestPrivate> d_ptr;

};

}
