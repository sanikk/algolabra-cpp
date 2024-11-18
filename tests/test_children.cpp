
#include "node.h"
#include "children.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>

namespace {

TEST(children, gives_8_back_on_empty) {
  std::vector<std::string> empty_map{"...", "...", "..."};
  std::vector<Node> vec;
  children(1, 1, empty_map, vec);

  EXPECT_EQ(vec.size(), 8);

  std::vector<Node> vec2{
    Node(1, 0, 1.0),
    Node(0, 0, DIAG),
    Node(0, 1, 1.0),
    Node(0, 2, DIAG),
    Node(1, 2, 1.0),
    Node(2, 2, DIAG),
    Node(2, 1, 1.0),
    Node(2, 0, DIAG)
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


TEST(children, map_edges_respected) {
  std::vector<std::string> le_map{"...","...","..."};
  std::vector<Node> vec2;
}
}// namespace ends
