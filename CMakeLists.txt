cmake_minimum_required(VERSION 3.21)
project(untitled1 C)

set(CMAKE_C_STANDARD 99)
add_subdirectory(src)

add_executable(untitled1 main.c)
if (test)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${LCOV_COMPILE_FLAGS} -coverage -lgcov -g -Wall -Werror")
    set(CMAKE_CXX_COMPILE_FLAGS "${CMAKE_CXX_FLAGS} ${LCOV_LINK_FLAGS}")
    add_subdirectory(GoogleTest)
target_link_libraries(untitled1 LINK_PUBLIC air_ticket input search)
