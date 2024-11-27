#pragma once
#include <utility>
#include <vector>



// x,y to a single int
int xy2int(int x, int y, int map_size);
std::pair<int, int> int2xy(int index, int map_size);

std::vector<std::pair<int, int>> pair_route(std::vector<int> route);
std::vector<int> unpair_route(std::vector<std::pair<int, int>> route);
