add_library(input input.h input.c)
target_include_directories(input PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(input LINK_PUBLIC air_ticket search)