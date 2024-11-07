#include <cstdlib>

double heuristics(int nodex, int nodey, int goalx, int goaly, double diff) {
  int abs_dx = abs(nodex - goalx);
  int abs_dy = abs(nodey - goaly);
  if (abs_dx < abs_dy)
    return abs_dx + abs_dy + diff * abs_dx;
  return abs_dx + abs_dy + diff * abs_dy;
}
