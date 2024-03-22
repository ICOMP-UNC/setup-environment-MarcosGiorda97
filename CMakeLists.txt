#   Request the minimum version of CMake, in case of lower version throws error.
cmake_minimum_required(VERSION 3.25 FATAL_ERROR)

#   Define our project.
project(
    "First_Project"
    VERSION 1.2.0
    DESCRIPTION "CMake C Project Template for OS II"
    LANGUAGES C
)

#   ENable testint and add the tests
include(CTest)

#   Define, in this case, the C standard, we are going to use std17.
set(CMAKE_C_STANDARD 17)

#   Include the 'include' directory, where the headers are located.
include_directories(include)

#   To automatic townload external deps
include(FetchContent)

#   Download unity library 
set(UNITY_GIT_URL "https://github.com/ThrowTheSwitch/Unity.git")

#   Enable Debug
set(FETCHCONTENT_QUIET OFF)

FetchContent_Declare(
    Unity
    GIT_REPOSITORY ${UNITY_GIT_URL}
    SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR}/external/Unity
    UPDATE_COMMAND ""
)

#   Ensures the named dependencies have been populated..
FetchContent_MakeAvailable(Unity)

#   Defino el codigo fuente. Add the 'src' directory, where the source files are located.
file(GLOB_RECURSE SOURCES "src/*.c")

#   Create the executable
add_executable(${PROJECT_NAME} ${SOURCES})

#   Compile the libraries
add_subdirectory(lib/libdyn)
add_subdirectory(lib/libsta)

#   Include the headers in lib
target_include_directories(${PROJECT_NAME} PUBLIC lib/libdyn/include)
target_include_directories(${PROJECT_NAME} PUBLIC lib/libsta/include)

#   Link the libraries
target_link_libraries(${PROJECT_NAME} StaticCLib DynamicCLib)

#   Add subdirectory of tests
if(RUN_TESTS EQUAL 1 OR RUN_COVERAGE EQUAL 1)
    add_subdirectory(tests)
endif()