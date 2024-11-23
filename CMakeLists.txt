cmake_minimum_required(VERSION 3.20)
project(SearchAlgoProject)
add_subdirectory(src/scenario_service)
add_subdirectory(src/searches/common/)
add_subdirectory(src/searches/)
add_subdirectory(src)
add_executable(eksekutable src/main.cpp)
target_link_libraries(eksekutable PRIVATE scenario_service search_service)

enable_testing()
add_subdirectory(tests)

