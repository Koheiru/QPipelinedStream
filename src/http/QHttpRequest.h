#pragma once

#include "QHttpMessage.h"
#include "QHttpMethod.h"
#include <QtCore/QUrl>
#include <QtCore/QString>


namespace QPipelinedStream
{

class QHttpRequest: public virtual QHttpMessage
{
public:
	QHttpRequest();
	QHttpRequest(QHttpVersion::Version version, QHttpMethod::Method method, const QString& uri);
	QHttpRequest(QHttpVersion::Version version, QHttpMethod::Method method, const QUrl& uri);
	virtual ~QHttpRequest();

public:
	void setMethod(QHttpMethod::Method method);
	QHttpMethod::Method method() const;

	void setUri(const QUrl& uri);
	QUrl uri() const;

private:
	QHttpMethod::Method m_method;
	QUrl m_uri;
};

} //namespace QPipelinedStream
