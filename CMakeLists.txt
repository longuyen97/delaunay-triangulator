# Standard setup
cmake_minimum_required(VERSION 3.0)
project(triangulation)
set(CMAKE_CXX_STANDARD 17)

# Setup conan
if(EXISTS ${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
    conan_basic_setup()
else()
    message(WARNING "The file conanbuildinfo.cmake doesn't exist. Please run 'conan install . -s build_type=Debug --install-folder=cmake-build-debug'")
endif()

# Setup code and unit tests
add_subdirectory(src)
add_subdirectory(tests)