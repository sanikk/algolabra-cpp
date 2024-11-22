
#include "searches_common.h"
#include <gtest/gtest.h>
#include <vector>
#include <string>

namespace {

  std::vector<std::tuple<int, int, double>> vec2{
      {1, 0, 1.0},
      {0, 0, DIAG},
      {0, 1, 1.0},
      {0, 2, DIAG},
      {1, 2, 1.0},
      {2, 2, DIAG},
      {2, 1, 1.0},
      {2, 0, DIAG}
      };
  }

struct ChildrenTestCase {
  std::vector<std::string> map_input;
  std::string bools;
  std::vector<std::tuple<int, int, double>> results;

  ChildrenTestCase(std::vector<std::string> i_map, std::string i_bools) : map_input(i_map), bools(i_bools) {};
  // initializer_list constructor
  ChildrenTestCase(std::vector<std::string> i_map, std::initializer_list<std::tuple<int, int, double>> i_results) : map_input(i_map), results(i_results) {};
  ChildrenTestCase() {};
};


std::vector<std::tuple<int, int, double>> vec_for(std::string bools) {
  std::vector<std::tuple<int, int, double>> returnable;
  for (int i=0; i < bools.size(); i++) {
    // std::cout << bools[i] << std::endl;
    if (bools[i] == '1') {
      returnable.push_back(vec2[i]);
    }
  }
  return returnable;
}


// initializer_list constructor tests
std::initializer_list<std::tuple<int, int, double>> full_list = {
      {1, 0, 1.0},
      {0, 0, DIAG},
      {0, 1, 1.0},
      {0, 2, DIAG},
      {1, 2, 1.0},
      {2, 2, DIAG},
      {2, 1, 1.0},
      {2, 0, DIAG}
  };
TEST(children_with_nodes, blocker_corner) {
  std::vector<std::string> le_map1{"#..", "...", "..."};
  std::vector<std::string> le_map2{"..#", "...", "..."};
  std::vector<std::string> le_map3{"...", "...", "#.."};
  std::vector<std::string> le_map4{"...", "...", "..#"};
  ChildrenTestCase({"#..", "...", "..."}, {{1, 0, 1.0}});
}
// init_list ends

//
TEST(children_with_nodes, blocked_straight) {
  std::vector<std::string> le_map1{".#.", "...", "..."};
  std::vector<std::string> le_map2{"...", "#..", "..."};
  std::vector<std::string> le_map3{"...", "..#", "..."};
  std::vector<std::string> le_map4{"...", "...", ".#."};
}


TEST(children_with_nodes, blocked_straight2) {
  std::vector<std::vector<std::string>> le_maps = {
    {".#.", "...", "..."}, 
    {"...", "#..", "..."},
    {"...", "..#", "..."}, 
    {"...", "...", ".#."}};
}

TEST(children_with_nodes, blocked_straight3) {
  std::vector<ChildrenTestCase> testcases = {
    { {".#.", "...", "..."}, "00111110" },
    { {"...", "#..", "..."}, "10001111" },
    { {"...", "..#", "..."}, "11111000" },
    { {"...", "...", ".#."}, "11100011" }
  };
  std::vector<std::tuple<int, int, double>> node_list;
  for (ChildrenTestCase tc : testcases) {
    node_list.clear();
    children(1,1, tc.map_input, node_list);
    EXPECT_EQ(node_list, vec_for(tc.bools));
  }
}


TEST(children_with_nodes, alley_between_blocked_corners) {
  std::vector<std::string> le_map1{"#.#", "...", "..."};
  std::vector<std::string> le_map2{"#..", "...", "#.."};
  std::vector<std::string> le_map3{"...", "...", "#.#"};
  std::vector<std::string> le_map4{"..#", "...", "..#"};
}

TEST(children_with_nodes, blocked_straight4) {
  std::vector<std::string> le_map1{".#.", "...", "..."};
  std::vector<std::string> le_map2{"...", "#..", "..."};
  std::vector<std::string> le_map3{"...", "..#", "..."};
  std::vector<std::string> le_map4{"...", "...", ".#."};
}

