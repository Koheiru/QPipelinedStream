cmake_minimum_required(VERSION 2.8.11)

#----------------------------------------------
set(CMAKE_AUTOMOC ON)
set(CMAKE_INCLUDE_CURRENT_DIR ON)


#----------------------------------------------
# Check if environment variable QTDIR is set.
if (DEFINED ENV{QTDIR})
    set(CMAKE_PREFIX_PATH $ENV{QTDIR} ${CMAKE_PREFIX_PATH})
else ()
    message (FATAL_ERROR "ERROR: Environment variable QTDIR is not set.")
endif ()


#----------------------------------------------
project(tests)

find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Test REQUIRED)

include_directories("${tests_SOURCE_DIR}/../include")

#----------------------------------------------
set(STREAM_FILES
	../src/QStream.h
	../src/QStreamHandler.h
	../src/QStreamDecoder.h
	../src/QStreamEncoder.h)

source_group("Stream" FILES ${STREAM_FILES})

#----------------------------------------------
set(HTTP_FILES 
	../src/http/QHttpObject.h
	../src/http/QHttpVersion.h
	../src/http/QHttpHeader.h
	../src/http/QHttpMethod.h
	../src/http/QHttpStatus.h
	../src/http/QHttpHeaders.h
	../src/http/QHttpContent.h
	../src/http/QHttpTrailer.h
	../src/http/QHttpMessage.h
	../src/http/QHttpRequest.h
	../src/http/QHttpResponse.h
	../src/http/QFullHttpMessage.h
	../src/http/QFullHttpRequest.h
	../src/http/QFullHttpResponse.h
	../src/http/QHttpObjectDecoder.h
	../src/http/QHttpRequestDecoder.h
	../src/http/QHttpResponseDecoder.h
	../src/http/QHttpHeaders.cpp
	../src/http/QHttpContent.cpp
	../src/http/QHttpTrailer.cpp
	../src/http/QHttpMessage.cpp
	../src/http/QHttpRequest.cpp
	../src/http/QHttpResponse.cpp
	../src/http/QFullHttpMessage.cpp
	../src/http/QFullHttpRequest.cpp
	../src/http/QFullHttpResponse.cpp
	../src/http/QHttpObjectDecoder.cpp
	../src/http/QHttpRequestDecoder.cpp
	../src/http/QHttpResponseDecoder.cpp)

source_group("HTTP" FILES ${HTTP_FILES})

add_executable(test_http ${STREAM_FILES} ${HTTP_FILES} test_http.cpp)
qt5_use_modules(test_http Core Test Network)

#----------------------------------------------
add_executable(colorize colorize.cpp)




