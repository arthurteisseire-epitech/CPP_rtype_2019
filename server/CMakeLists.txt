cmake_minimum_required(VERSION 3.14)

set(SERVER_NAME r-type_server)

project(${SERVER_NAME})

set(INCLUDES
	src
	src/engine
	src/engine/entity
	src/engine/component
	src/engine/component/network
	src/engine/component/tuple
	src/engine/system
	src/engine/system/network
	src/engine/system/monster_loading
	src/engine/mathUtils
	src/engine/util
	src/engine/util/math
	src/engine/util/network
	src/engine/protocol

	monster_libraries/src
)

include_directories(${INCLUDES})

file(GLOB_RECURSE server_sources src/*.cpp src/*.hpp)
list(FILTER server_sources EXCLUDE REGEX "src/main.cpp$")

add_executable(${SERVER_NAME} ${server_sources} src/main.cpp)
target_link_libraries(${SERVER_NAME} ${Boost_LIBRARIES} boost_thread pthread dl)
add_subdirectory(tests EXCLUDE_FROM_ALL)
add_subdirectory(monster_libraries)
