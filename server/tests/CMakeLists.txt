project(server_tests)
cmake_minimum_required(VERSION 3.14)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR} ../src)
add_subdirectory(googletest)

file(GLOB_RECURSE server_tests_sources src/*.cpp)

set(bin server_tests_run)
add_executable(${bin} ${server_tests_sources} ${server_sources})
target_link_libraries(${bin} gtest gtest_main ${CONAN_LIBS})
