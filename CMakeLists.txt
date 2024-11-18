cmake_minimum_required(VERSION 3.29)
project(wren_sandbox
        VERSION 0.1
        DESCRIPTION "Wren sandbox"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(wren_sandbox source/main.cpp)

# Add wren
add_subdirectory(external/wren EXCLUDE_FROM_ALL)

# Add include directories
target_include_directories(wren_sandbox
    PRIVATE external/wren/src
    PRIVATE external/wren/src/include)

# Link to the wren library
target_link_libraries(wren_sandbox PRIVATE wren)
