cmake_minimum_required(VERSION 3.16.3)
project(FLCounter)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_VERBOSE_MAKEFILE ON)
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(BOOST_ROOT /usr)
set(Boost_INCLUDE_DIR /usr/include/)

find_package(Boost 1.80.0 COMPONENTS filesystem REQUIRED)

add_executable(FLCounter src/FLCounter.cpp)
target_link_libraries(FLCounter PRIVATE Boost::filesystem)

