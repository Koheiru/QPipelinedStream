#pragma once

#include <QtCore/QIODevice>
#include <QtCore/QList>


namespace QPipelinedStream
{

template <typename EncodedObject>
class QStreamEncoder
{
public:
	virtual ~QStreamEncoder() {}

public:
	virtual void encode(QIODevice& input, QList<EncodedObject*>& output) = 0;
	virtual void reset() = 0;
};

} //namespace QPipelinedStream
