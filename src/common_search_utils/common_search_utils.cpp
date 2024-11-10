#include "common_search_utils.h"
#include <cmath>
#include <string>
#include <vector>


namespace CommonSearchUtils {

double heuristics(int nodex, int nodey, int goalx, int goaly) {
  double abs_dx = abs(nodex - goalx);
  double abs_dy = abs(nodey - goaly);
  if (abs_dx < abs_dy)
    return static_cast<double>(abs_dx + abs_dy + DIFF * abs_dx);
  return static_cast<double>(abs_dx + abs_dy + DIFF * abs_dy);
}

void children(int x, int y, std::vector<std::string> citymap) {}

}
