cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 11)

project(rtype)
add_definitions("-fPIC")

#include(${CMAKE_SOURCE_DIR}/build/conanbuildinfo.cmake)
#conan_basic_setup()

add_subdirectory(server)
add_subdirectory(client)
