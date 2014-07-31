#pragma once

#include "QHttpObject.h"
#include "QHttpHeaders.h"
#include "QHttpVersion.h"


namespace QPipelinedStream
{

class QHttpMessage: public virtual QHttpObject,
					public virtual QHttpHeaders
{
public:
	QHttpMessage();
	QHttpMessage(QHttpVersion::Version version);
	virtual ~QHttpMessage();

public:
	QHttpVersion::Version version() const;
	void setVersion(QHttpVersion::Version version);

private:
	QHttpVersion::Version m_version;
};

} //namespace QPipelinedStream
