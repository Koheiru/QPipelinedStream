#pragma once

#include <QtCore/QString>


namespace QPipelinedStream
{

//-----------------------------------------------------------------------------
namespace QHttpMethod
{

//! TODO: replace switch to the map.

enum Method
{
	UNKNOWN,
	CONNECT,
	DELETE,
	GET,
	HEAD,
	OPTIONS,
	PATCH,
	POST,
	PUT,
	TRACE,
};

static inline QString toString(Method method)
{
	switch (method)
	{
		case CONNECT: return QString("CONNECT");
		case DELETE:  return QString("DELETE");
		case HEAD:    return QString("HEAD");
		case GET:     return QString("GET");
		case OPTIONS: return QString("OPTIONS");
		case PATCH:   return QString("PATCH");
		case POST:    return QString("POST");
		case PUT:     return QString("PUT");
		case TRACE:   return QString("TRACE");
		default:      return QString();
	}
}

static inline Method fromString(const QString& method)
{
	if (method == "CONNECT")      return CONNECT;
	else if (method == "DELETE")  return DELETE;
	else if (method == "HEAD")    return HEAD;
	else if (method == "GET")     return GET;
	else if (method == "OPTIONS") return OPTIONS;
	else if (method == "PATCH")   return PATCH;
	else if (method == "POST")    return POST;
	else if (method == "PUT")     return PUT;
	else if (method == "TRACE")   return TRACE;
	else return UNKNOWN;
}

} //namespace HttpMethod

} //namespace QPipelinedStream
