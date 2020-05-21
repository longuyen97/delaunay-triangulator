cmake_minimum_required(VERSION 3.0)

project(triangulation CXX)

set(CMAKE_CXX_STANDARD 17)

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    if (NOT EXISTS cmake-build-debug/conanbuildinfo.cmake)
        file(COPY conanfile.py DESTINATION cmake-build-debug)
        execute_process(COMMAND conan install . -s build_type=Debug --install-folder=cmake-build-debug)
    endif ()
else()
    file(COPY conanfile.py DESTINATION ${CMAKE_BINARY_DIR})
    execute_process(COMMAND conan install .)
endif ()

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)

conan_basic_setup()

find_package(OpenCV REQUIRED)

add_library(${PROJECT_NAME} INTERFACE)

target_include_directories(${PROJECT_NAME} INTERFACE include)

add_subdirectory(tests)

add_executable(tri main.cpp)

target_link_libraries(tri ${PROJECT_NAME})

target_link_libraries(tri ${OpenCV_LIBS})