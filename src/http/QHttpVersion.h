#pragma once

#include <QtCore/QString>


namespace QPipelinedStream
{

//-----------------------------------------------------------------------------
namespace QHttpVersion
{

enum Version
{
	UNKNOWN,
	HTTP_1_0,
	HTTP_1_1,
};

static inline QString toString(Version version)
{
	switch (version)
	{
		case HTTP_1_0: return QString("HTTP/1.0");
		case HTTP_1_1: return QString("HTTP/1.1");
		default:       return QString();
	}
}

static inline Version fromString(const QString& version)
{
	if (version == "HTTP/1.0")      return HTTP_1_0;
	else if (version == "HTTP/1.1") return HTTP_1_1;
	else return UNKNOWN;
}

} //namespace HttpVersion

} //namespace QPipelinedStream
