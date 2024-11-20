cmake_minimum_required(VERSION 3.29)
project(wren_sandbox
        VERSION 0.1
        DESCRIPTION "Wren sandbox"
        LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(wren_sandbox source/main.cpp)

# Add wren
add_subdirectory(external/wren EXCLUDE_FRM_ALL)

set_target_properties(wren PROPERTIES LINKER_LANGUAGE C)

# Add include directories
target_include_directories(wren_sandbox
    PRIVATE external/wren/src/include
    PRIVATE external/wren/src/vm)

# Link to the wren library
target_link_libraries(wren_sandbox PRIVATE wren)
