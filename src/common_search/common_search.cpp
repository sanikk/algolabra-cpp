#include "common_search.h"
#include <cmath>
#include <string>
#include <vector>
#include <array>

namespace CommonSearch {

double heuristics(int nodex, int nodey, int goalx, int goaly) {
  double abs_dx = abs(nodex - goalx);
  double abs_dy = abs(nodey - goaly);
  if (abs_dx < abs_dy)
    return static_cast<double>(abs_dx + abs_dy + DIFF * abs_dx);
  return static_cast<double>(abs_dx + abs_dy + DIFF * abs_dy);
}

double heuristics(Node node, Node goal) {
  return heuristics(node.x, node.y, goal.x, goal.y);
}

// std::array<Node, 8>  children(int x, int y, const std::vector<std::string> &citymap) {
//   std::array<Node, 8> returnable;
//   return returnable;
// }

//  std::span<Node> children(int x, int y, const std::vector<std::string> &citymap) {
//    std::vector<Node> vec;
//    return std::span<Node>(vec);
//  }

void children(Node node, const std::vector<std::string> &citymap, std::vector<Node>& node_list) {
  int x = node.x;
}


}
