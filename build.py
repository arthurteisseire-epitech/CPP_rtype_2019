#!/usr/bin/env python

import os


def get_cmake_options():
    cmake_options = '-G "'
    if os.name == 'nt':
        cmake_options += 'Visual Studio 16 2019'
    else:
        cmake_options += 'Unix Makefiles'
    cmake_options += '"'
    return cmake_options


bash_cmd = 'mkdir -p build && cd build && conan install .. --build=missing && cmake .. ' + get_cmake_options() + ' && cmake --build .'

print(bash_cmd)
os.system(bash_cmd)
