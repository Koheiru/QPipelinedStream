#pragma once

#include <QtCore/QString>

namespace QPipelinedStream
{
namespace QHttpHeader
{

enum Header
{
	UNKNOWN,
	// GENERAL HEADERS:
	CACHE_CONTROL,
	CONNECTION,
	DATE,
	PRAGMA,
	TRAILER,
	TRANSFER_ENCODING,
	UPGRADE,
	VIA,
	WARNING,
	// REQUEST HEADERS:
	ACCEPT,
	ACCEPT_CHARSET,
	ACCEPT_ENCODING,
	ACCEPT_LANGUAGE,
	AUTHORIZATION,
	COOKIE,
	EXPECT,
	FROM,
	HOST,
	IF_MATCH,
	IF_MODIFIED_SINCE,
	IF_NONE_MATCH,
	IF_RANGE,
	IF_UNMODIFIED_SINCE,
	MAX_FORWARDS,
	PROXY_AUTHORIZATION,
	RANGE,
	REFERER,
	TE,
	USER_AGENT,
	// RESPONSE HEADERS:
	ACCEPT_RANGES,
	AGE,
	ETAG,
	LOCATION,
	PROXY_AUTHENTICATE,
	RETRY_AFTER,
	SERVER,
	SET_COOKIE,
	VARY,
	WWW_AUTHENTICATE,
	// ENTITY HEADERS:
	ALLOW,
	CONTENT_ENCODING,
	CONTENT_LANGUAGE,
	CONTENT_LENGTH,
	CONTENT_LOCATION,
	CONTENT_MD5,
	CONTENT_RANGE,
	CONTENT_TYPE,
	EXPIRES,
	LAST_MODIFIED,
};

static inline QString toString(Header header)
{
	switch (header)
	{
		// GENERAL HEADERS:
		case CACHE_CONTROL:     return QString("Cache-Control");
		case CONNECTION:        return QString("Connection");
		case DATE:              return QString("Date");
		case PRAGMA:            return QString("Pragma");
		case TRAILER:           return QString("Trailer");
		case TRANSFER_ENCODING: return QString("Transfer-Encoding");
		case UPGRADE:           return QString("Upgrade");
		case VIA:               return QString("Via");
		case WARNING:           return QString("Warning");
		// REQUEST HEADERS:
		case ACCEPT:              return QString("Accept");
		case ACCEPT_CHARSET:      return QString("Accept-Charset");
		case ACCEPT_ENCODING:     return QString("Accept-Encoding");
		case ACCEPT_LANGUAGE:     return QString("Accept-Language");
		case AUTHORIZATION:       return QString("Authorization");
		case COOKIE:              return QString("Cookie");
		case EXPECT:              return QString("Expect");
		case FROM:                return QString("From");
		case HOST:                return QString("Host");
		case IF_MATCH:            return QString("If-Match");
		case IF_MODIFIED_SINCE:   return QString("If-Modified-Since");
		case IF_NONE_MATCH:       return QString("If-None-Match");
		case IF_RANGE:            return QString("If-Range");
		case IF_UNMODIFIED_SINCE: return QString("If-Unmodified-Since");
		case MAX_FORWARDS:        return QString("Max-Forwards");
		case PROXY_AUTHORIZATION: return QString("Proxy-Authorization");
		case RANGE:               return QString("Range");
		case REFERER:             return QString("Referer");
		case TE:                  return QString("TE");
		case USER_AGENT:          return QString("User-Agent");
		// RESPONSE HEADERS:
		case ACCEPT_RANGES:      return QString("Accept-Ranges");
		case AGE:                return QString("Age");
		case ETAG:               return QString("ETag");
		case LOCATION:           return QString("Location");
		case PROXY_AUTHENTICATE: return QString("Proxy-Authenticate");
		case RETRY_AFTER:        return QString("Retry-After");
		case SERVER:             return QString("Server");
		case SET_COOKIE:         return QString("Set-Cookie");
		case VARY:               return QString("Vary");
		case WWW_AUTHENTICATE:   return QString("WWW-Authenticate");
		// ENTITY HEADERS:
		case ALLOW:            return QString("Allow");
		case CONTENT_ENCODING: return QString("Content-Encoding");
		case CONTENT_LANGUAGE: return QString("Content-Language");
		case CONTENT_LENGTH:   return QString("Content-Length");
		case CONTENT_LOCATION: return QString("Content-Location");
		case CONTENT_MD5:      return QString("Content-MD5");
		case CONTENT_RANGE:    return QString("Content-Range");
		case CONTENT_TYPE:     return QString("Content-Type");
		case EXPIRES:          return QString("Expires");
		case LAST_MODIFIED:    return QString("Last-Modified");
		default: return QString();
	}
}

static inline Header fromString(const QString& header)
{
	// GENERAL HEADERS:
	if (header == "Cache-Control")          return CACHE_CONTROL;
	else if (header == "Connection")        return CONNECTION;
	else if (header == "Date")              return DATE;
	else if (header == "Pragma")            return PRAGMA;
	else if (header == "Trailer")           return TRAILER;
	else if (header == "Transfer-Encoding") return TRANSFER_ENCODING;
	else if (header == "Upgrade")           return UPGRADE;
	else if (header == "Via")               return VIA;
	else if (header == "Warning")           return WARNING;
	// REQUEST HEADERS:
	else if (header == "Accept")              return ACCEPT;
	else if (header == "Accept-Charset")      return ACCEPT_CHARSET;
	else if (header == "Accept-Encoding")     return ACCEPT_ENCODING;
	else if (header == "Accept-Language")     return ACCEPT_LANGUAGE;
	else if (header == "Authorization")       return AUTHORIZATION;
	else if (header == "Cookie")              return COOKIE;
	else if (header == "Expect")              return EXPECT;
	else if (header == "From")                return FROM;
	else if (header == "Host")                return HOST;
	else if (header == "If-Match")            return IF_MATCH;
	else if (header == "If-Modified-Since")   return IF_MODIFIED_SINCE;
	else if (header == "If-None-Match")       return IF_NONE_MATCH;
	else if (header == "If-Range")            return IF_RANGE;
	else if (header == "If-Unmodified-Since") return IF_UNMODIFIED_SINCE;
	else if (header == "Max-Forwards")        return MAX_FORWARDS;
	else if (header == "Proxy-Authorization") return PROXY_AUTHORIZATION;
	else if (header == "Range")               return RANGE;
	else if (header == "Referer")             return REFERER;
	else if (header == "TE")                  return TE;
	else if (header == "User-Agent")          return USER_AGENT;
	// RESPONSE HEADERS:
	else if (header == "Accept-Ranges")      return ACCEPT_RANGES;
	else if (header == "Age")                return AGE;
	else if (header == "ETag")               return ETAG;
	else if (header == "Location")           return LOCATION;
	else if (header == "Proxy-Authenticate") return PROXY_AUTHENTICATE;
	else if (header == "Retry-After")        return RETRY_AFTER;
	else if (header == "Server")             return SERVER;
	else if (header == "Set-Cookie")         return SET_COOKIE;
	else if (header == "Vary")               return VARY;
	else if (header == "WWW-Authenticate")   return WWW_AUTHENTICATE;
	// ENTITY HEADERS:
	else if (header == "Allow")            return ALLOW;
	else if (header == "Content-Encoding") return CONTENT_ENCODING;
	else if (header == "Content-Language") return CONTENT_LANGUAGE;
	else if (header == "Content-Length")   return CONTENT_LENGTH;
	else if (header == "Content-Location") return CONTENT_LOCATION;
	else if (header == "Content-MD5")      return CONTENT_MD5;
	else if (header == "Content-Range")    return CONTENT_RANGE;
	else if (header == "Content-Type")     return CONTENT_TYPE;
	else if (header == "Expires")          return EXPIRES;
	else if (header == "Last-Modified")    return LAST_MODIFIED;
	else return UNKNOWN;
}

}
}


