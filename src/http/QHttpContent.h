#pragma once

#include "QHttpObject.h"
#include <QtCore/QByteArray>


namespace QPipelinedStream
{

class QHttpContent: public virtual QHttpObject
{
public:
	QHttpContent();
	QHttpContent(const QByteArray& content);
	virtual ~QHttpContent();

public:
	void setContent(const QByteArray& content);
	QByteArray content() const;

private:
	QByteArray m_content;

};

} //namespace QPipelinedStream
