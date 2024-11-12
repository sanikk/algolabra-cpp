#pragma once
#include <cmath>
#include <vector>
#include <string>
#include <array>

namespace CommonSearch {
 
  const double DIAG = std::sqrt(2.0);
  const double DIFF = std::sqrt(2.0) - 2.0;
  
  struct Node {
    double cost;
    int x, y;

    Node(double i_cost, int i_x, int i_y) : cost(i_cost), x(i_x), y(i_y) {}
    Node(int i_x, int i_y) : x(i_x), y(i_y) {}
    Node() {}

    bool operator==(const Node& other) const {
          return x == other.x && y == other.y;
      }
    friend bool operator<(const Node& l, const Node& r) {return l.cost < r.cost;}
    friend bool operator>(const Node& l, const Node& r) {return l.cost > r.cost;}
    };


  double heuristics(int nodex, int nodey, int goalx, int goaly);
  double heuristics(Node node, Node goal);

  void children(Node node, const std::vector<std::string> &citymap, std::vector<Node>& node_list);

  struct NodeHash {
      std::size_t operator()(const Node& node) const {
          return std::hash<int>()(node.x) ^ (std::hash<int>()(node.y) << 1);
      }
  };
} // namespace ends
