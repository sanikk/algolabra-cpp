#pragma  once
#include <vector>
struct RetVal {
  bool found;
  double cost;
  std::vector<int> route;

  RetVal(bool i_found=false) : found(i_found) {}
  RetVal(double i_cost, std::vector<int> i_route) : found(true), cost(i_cost), route(i_route) {}
};
