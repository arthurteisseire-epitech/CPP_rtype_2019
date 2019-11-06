project(client_tests)
cmake_minimum_required(VERSION 3.14)

file(GLOB_RECURSE client_tests_sources src/*.cpp)
add_executable(client_tests_run ${client_tests_sources} ${client_sources})
target_link_libraries(client_tests_run gtest gtest_main ${CONAN_LIBS})
