#pragma once

#include "QHttpObject.h"
#include "QHttpHeaders.h"


namespace QPipelinedStream
{

class QHttpTrailer: public virtual QHttpObject,
					public virtual QHttpHeaders
{
public:
	QHttpTrailer();
	virtual ~QHttpTrailer();

};

} //namespace QPipelinedStream
