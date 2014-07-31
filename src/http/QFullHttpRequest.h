#pragma once

#include "QFullHttpMessage.h"
#include "QHttpRequest.h"


namespace QPipelinedStream
{

class QFullHttpRequest: public QFullHttpMessage,
						public QHttpRequest
{
public:
	QFullHttpRequest();
	QFullHttpRequest(QHttpVersion::Version version, QHttpMethod::Method method, const QString& uri);
	QFullHttpRequest(QHttpVersion::Version version, QHttpMethod::Method method, const QUrl& uri);
	virtual ~QFullHttpRequest();

};

} //namespace QPipelinedStream
