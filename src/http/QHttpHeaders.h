#pragma once

#include "QHttpObject.h"
#include "QHttpHeader.h"
#include <QtCore/QString>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QtCore/QMap>


namespace QPipelinedStream
{

class QHttpHeaders: public virtual QHttpObject
{
public:
	QHttpHeaders();
	QHttpHeaders(QMap<QString, QByteArray> headersValues);
	virtual ~QHttpHeaders();

public:
	QList<QString> headers() const;
	QMap<QString, QByteArray> headersValues() const;

	bool isHeaderSet(const QString& header) const;
	bool isHeaderSet(QHttpHeader::Header header) const;

	QByteArray header(const QString& header, const QByteArray& defaultValue = QByteArray()) const;
	QByteArray header(QHttpHeader::Header header, const QByteArray& defaultValue = QByteArray()) const;

	void setHeader(const QString& header, const QByteArray& value);
	void setHeader(QHttpHeader::Header header, const QByteArray& value);

	void removeHeader(const QString& header);
	void removeHeader(QHttpHeader::Header header);

private:
	QMap<QString, QByteArray> m_headers;
};

} //namespace QPipelinedStream
