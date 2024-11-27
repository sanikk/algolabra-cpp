#include "tools.h"

int xy2int(int x, int y, int map_size) {
  return y*map_size + x;
}

std::pair<int, int> int2xy(int index, int map_size) {
  int x = index % map_size;
  int y = index / map_size;
  return std::make_pair(x,y);
}

