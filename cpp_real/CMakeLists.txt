cmake_minimum_required(VERSION 3.13)
project(main)

add_library(src main.cpp
    cpp_real.cpp
    cpp_real.hpp
)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main main.cpp)
target_link_libraries(main src)