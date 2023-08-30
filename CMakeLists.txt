cmake_minimum_required(VERSION 3.21)

# We on the edge baby
set(CMAKE_C_STANDARD 23)
set(CMAKE_CXX_STANDARD 23)

# I doubt we will be using MSVC, but it doesn't
# hurt to have support for it.
if(MSVC)
  add_compile_options(/W4 /WX)
else()
  add_compile_options(-Wall -Wextra -Werror)
endif()

project(view3D
        DESCRIPTION "A simple 3D model viewer."
        LANGUAGES C CXX) # We may just use CXX

add_subdirectory(src)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(test)
endif()
