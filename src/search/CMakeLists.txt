add_library(search search.h search.c)
target_include_directories(search PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(search LINK_PUBLIC air_ticket)
