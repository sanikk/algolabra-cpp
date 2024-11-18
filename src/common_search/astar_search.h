#include "node.h"
#include "children.h"
#include "heuristics.h"
#include <vector>
#include <string>
#include <optional>

#include <queue>

int get_one();

std::tuple<double, std::optional<std::vector<std::pair<int, int>>>> astar_search(int startx, int starty, int goalx, int goaly,
  const std::vector<std::string> &citymap);


std::vector<std::pair<int, int>> reconstruct_route(const std::pair<int, int>* came_from, const std::pair<int, int> start, const std::pair<int, int> goal, const int map_size);

