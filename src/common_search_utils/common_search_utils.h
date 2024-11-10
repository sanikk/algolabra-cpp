#pragma once
#include <cmath>
#include <vector>
#include <string>

namespace CommonSearchUtils {
 
  constexpr double DIFF = sqrt(2.0) - 2.0;

  double heuristics(int nodex, int nodey, int goalx, int goaly);

  void children(int x, int y, std::vector<std::string> citymap); 
} // namespace ends
