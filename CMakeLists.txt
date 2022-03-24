cmake_minimum_required(VERSION 3.21)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(src)
add_subdirectory(GoogleTest)
add_executable(untitled1 main.c)
target_link_libraries(untitled1 LINK_PUBLIC air_ticket input search)
