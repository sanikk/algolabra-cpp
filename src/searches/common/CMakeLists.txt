add_library(search_common
    children.cpp
    heuristics.cpp
)

target_include_directories(search_common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
