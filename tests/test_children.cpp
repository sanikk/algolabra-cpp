
#include "common_search.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>

namespace {

TEST(children, gives_8_back_on_empty) {
  std::vector<std::string> empty_map{"...", "...", "..."};
  std::vector<CommonSearch::Node> vec;
  CommonSearch::children(1, 1, empty_map, vec);

  EXPECT_EQ(vec.size(), 8);

  std::vector<CommonSearch::Node> vec2{
    CommonSearch::Node(1.0, 1, 0),
    CommonSearch::Node(CommonSearch::DIAG, 0, 0),
    CommonSearch::Node(1.0, 0, 1),
    CommonSearch::Node(CommonSearch::DIAG, 0, 2),
    CommonSearch::Node(1.0, 1, 2),
    CommonSearch::Node(CommonSearch::DIAG, 2, 2),
    CommonSearch::Node(1.0, 2, 1),
    CommonSearch::Node(CommonSearch::DIAG, 2, 0)
  };

  // debug leftovers, imma leave them.
  for (int i=0; i < 8; i++) {
    EXPECT_EQ(vec[i].x, vec2[i].x);
    EXPECT_EQ(vec[i].y, vec2[i].y);
    EXPECT_EQ(vec[i].cost, vec2[i].cost);
  }
  // can do this too now it that it works:
  EXPECT_EQ(vec, vec2);
}
}// double heuristics(int nodex, int nodey, int goalx, int goaly, double diff) {
