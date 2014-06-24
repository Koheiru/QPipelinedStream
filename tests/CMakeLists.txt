cmake_minimum_required(VERSION 2.8.11)

#----------------------------------------------
set(CMAKE_INSTALL_PREFIX CACHE PATH "D:\\trash" FORCE)

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

include_directories("${tests_SOURCE_DIR}/../include")

find_package(Qt5Core REQUIRED)
find_package(Qt5Network REQUIRED)
find_package(Qt5Test REQUIRED)

set(TEMP_SOURCES
		../src/QHttpMessage.cpp ../src/QHttpRequest.cpp ../src/QHttpResponse.cpp
		../src/QHttpObjectDecoder.cpp ../src/QHttpRequestDecoder.cpp)

#----------------------------------------------
#add_executable(test test.cpp)
#qt5_use_modules(test Core Test Network)

#add_test(test test)

#----------------------------------------------
add_executable(test_http ${TEMP_SOURCES} test_http.cpp)
qt5_use_modules(test_http Core Test Network)

add_test(tests test_http)
