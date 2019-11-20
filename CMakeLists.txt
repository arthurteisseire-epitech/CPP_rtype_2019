cmake_minimum_required(VERSION 3.14)
set(CMAKE_CXX_STANDARD 14)

project(rtype)
add_definitions("-fPIC")


# TODO -- use a conanfile at root to build two other conanfiles in server an client if possible
include(${CMAKE_SOURCE_DIR}/build/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(server)
add_subdirectory(client)
