include_directories(${CMAKE_SOURCE_DIR}/src/searches/common)

add_executable(children_test children_test.cpp)
target_link_libraries(children_test PRIVATE searches_common gtest gtest_main)
add_test(NAME ChildrenTest COMMAND children_test)
