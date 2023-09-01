add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(math)

# data depends on math
add_subdirectory(data)

target_include_directories(${PROJECT_NAME} PUBLIC ${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC data math ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES})