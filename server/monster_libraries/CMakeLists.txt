cmake_minimum_required(VERSION 3.14)

set(CMAKE_BUILD_TYPE Release)
include_directories(${INCLUDES})

add_library(random_monster SHARED ${server_sources} src/RandomMonster.cpp)
