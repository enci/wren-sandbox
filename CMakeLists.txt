cmake_minimum_required(VERSION 3.29)
project(wren_sandbox
        VERSION 0.1
        DESCRIPTION "Wren sandbox"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(wren_sandbox source/main.cpp)

