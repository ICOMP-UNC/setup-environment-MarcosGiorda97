#   Request the minimum version of CMake, in case of lower throws error
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

#   Define our project.
project(
    "DynamicCLib"
    VERSION 1.0.0
    DESCRIPTION "CMake C Project Template for OS II"
    LANGUAGES C
)

#   Define, in this case, the C standard, we are going to use std17.
set(CMAKE_C_STANDARD 17)

#   Include the 'include' directory, where the headers are located.
include_directories(include)

#   Add the 'src' directory, where the source files are located.
file(GLOB_RECURSE SOURCES "src/*.c")

#   Create the executable
add_library(${PROJECT_NAME} SHARED ${SOURCES})
