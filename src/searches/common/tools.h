#pragma once
#include <utility>



// x,y to a single int
int xy2int(int x, int y, int map_size);
std::pair<int, int> int2xy(int index, int map_size);
