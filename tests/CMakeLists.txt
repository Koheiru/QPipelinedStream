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
add_executable(colorize colorize.cpp)

