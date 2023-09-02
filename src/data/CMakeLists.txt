add_library(data vertex.cpp obj_parser.cpp mesh.cpp)
target_include_directories(data PUBLIC ".")
target_link_libraries(data math)
