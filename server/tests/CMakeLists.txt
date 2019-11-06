project(server_tests)
cmake_minimum_required(VERSION 3.14)

file(GLOB_RECURSE server_tests_sources src/*.cpp)
add_executable(server_tests_run ${server_tests_sources} ${server_sources})
target_link_libraries(server_tests_run gtest gtest_main ${CONAN_LIBS})
