set(CLIENT_NAME r-type_client)

project(${CLIENT_NAME})

include_directories(
	src
	src/Component
	src/Game
	src/Network
	src/Scene
	src/Scene/Menu
)

file(GLOB_RECURSE client_sources src/*.cpp src/*.hpp)
list(FILTER client_sources EXCLUDE REGEX "src/main.cpp$")

add_executable(${CLIENT_NAME} ${client_sources} src/main.cpp)
target_link_libraries(${CLIENT_NAME} ${CONAN_LIBS})
add_subdirectory(tests EXCLUDE_FROM_ALL)
