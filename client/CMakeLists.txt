set(CLIENT_NAME r-type_client)

project(${CLIENT_NAME})

include_directories(src)

file(GLOB_RECURSE client_sources src/*.cpp src/*.hpp)

add_executable(${CLIENT_NAME} ${client_sources})
#target_link_libraries(${CLIENT_NAME} ${CONAN_LIBS})
