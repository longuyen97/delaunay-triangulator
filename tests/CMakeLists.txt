project(triangulation_tests)

add_executable(${PROJECT_NAME} tests.cpp tests_edge.hpp tests_incremental.hpp tests_point.hpp tests_triangle.hpp)
target_link_libraries(${PROJECT_NAME} triangulation_include)