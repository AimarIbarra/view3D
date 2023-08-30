add_executable(${PROJECT_NAME} main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

add_subdirectory(math)

# data depends on math
add_subdirectory(data)

include_directories(${OPENGL_INCLUDE_DIRS} ${GLUT_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC data math)
