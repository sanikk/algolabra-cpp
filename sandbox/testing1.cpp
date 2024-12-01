#include <vector>
#include <cmath>
#include <iostream>



const double DIAG = std::sqrt(2.0);
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

struct ChildrenTestCase {
  std::vector<std::string> map_input;
  std::string bools;

  ChildrenTestCase(std::vector<std::string> i_map, std::string i_bools) : map_input(i_map), bools(i_bools) {};
  // initializer_list constructor
  // ChildrenTestCase(std::vector<std::string> i_map, std::initializer_list<std::tuple<int, int, double>> i_results) : map_input(i_map), results(i_results) {};
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


int main() {
  std::vector<ChildrenTestCase> testcases = {
    { {"...","#..","..."}, "10001111"  },
    { {"...","..#","..."}, "11111000" }
  };
  for (ChildrenTestCase tc : testcases) {
    for (auto str : tc.map_input) {
      std::cout << str << " " << std::endl;
    }
    auto answer = vec_for(tc.bools);
    for (auto tup : answer) {
      std::cout << std::get<0>(tup) << ", " << std::get<1>(tup) << ", " << std::get<2>(tup) << std::endl;
    }
  // auto a = vec_for("10001111");
  // for (auto p : a) {
  //   std::cout << std::get<0>(p) << ", " << std::get<1>(p) << ", " << std::get<2>(p) << std::endl;
  }

}

