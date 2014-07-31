#pragma once

#include <QtCore/QIODevice>
#include <QtCore/QList>


namespace QPipelinedStream
{

template <typename DecodedObject>
class QStreamDecoder
{
public:
	virtual ~QStreamDecoder() {}

public:
	virtual void decode(QIODevice& input, QList<DecodedObject*>& output) = 0;
	virtual void reset() = 0;
};

} //namespace QPipelinedStream
