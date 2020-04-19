project(tests CXX)

file(GLOB HEADER_FILES "*.hpp")
file(GLOB SOURCE_FILES "*.cpp")
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} triangulation)
set_target_properties(${PROJECT_NAME} PROPERTIES LINKER_LANGUAGE CXX)