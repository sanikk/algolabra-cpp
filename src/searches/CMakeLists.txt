add_library(searches
    astar_search.cpp
    fringe_search.cpp
    fringe_unopt.cpp
)

target_include_directories(searches PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(searches PRIVATE searches_common)
