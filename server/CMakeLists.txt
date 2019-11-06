set(SERVER_NAME r-type_server)

project(${SERVER_NAME})

include_directories(src)

file(GLOB_RECURSE server_sources src/*.cpp src/*.hpp)

add_executable(${SERVER_NAME} ${server_sources})
target_link_libraries(${SERVER_NAME} ${CONAN_LIBS})
add_subdirectory(tests EXCLUDE_FROM_ALL)
