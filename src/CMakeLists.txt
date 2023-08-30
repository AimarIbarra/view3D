add_executable(${PROJECT_NAME} main.cpp)


add_subdirectory(math)

# data depends on math
add_subdirectory(data)

target_link_libraries(${PROJECT_NAME} PUBLIC data math)
