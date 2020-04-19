cmake_minimum_required(VERSION 3.0)

project(triangulation-algorithms CXX)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (NOT EXISTS cmake-build-debug/conanbuildinfo.cmake)
        file(COPY conanfile.py DESTINATION cmake-build-debug)
        execute_process(COMMAND conan install . -s build_type=Debug --install-folder=cmake-build-debug)
    endif ()
endif ()
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

add_subdirectory(src)
add_subdirectory(tests)