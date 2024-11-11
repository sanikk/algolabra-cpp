#pragma once
#include <cmath>
#include <vector>
#include <string>
#include <array>

namespace CommonSearch {
 
  struct Node {
    double cost;
    int x, y;

    Node(double i_cost, int i_x, int i_y) : cost(i_cost), x(i_x), y(i_y) {}
    Node(int i_x, int i_y) : x(i_x), y(i_y) {}
    Node() {}

    bool operator==(const Node& other) const {
          return x == other.x && y == other.y;
      }
    //bool operator<(const Node& other) {
    //    return cost > other.cost;
    //  }
    //bool operator>(const Node& other) {
    //    return cost < other.cost;
    //  }
    friend bool operator<(const Node& l, const Node& r) {return l.cost < r.cost;}
    friend bool operator>(const Node& l, const Node& r) {return l.cost > r.cost;}
    };

  constexpr double DIFF = sqrt(2.0) - 2.0;

  double heuristics(int nodex, int nodey, int goalx, int goaly);
  double heuristics(Node node, Node goal);

  std::array<Node, 8> children(int x, int y, std::vector<std::string> citymap);

  struct NodeHash {
      std::size_t operator()(const Node& node) const {
          return std::hash<int>()(node.x) ^ (std::hash<int>()(node.y) << 1);
      }
  };
} // namespace ends
