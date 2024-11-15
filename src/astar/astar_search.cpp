#include "../common_search/common_search.h"

#include <queue>
#include <vector>

#include <string>
#include <iostream>
#include <optional>
 
int get_one() {
  return 1;
}

std::vector<std::pair<int, int>> reconstruct_route(const std::pair<int, int>* came_from, const std::pair<int, int> start, const std::pair<int, int> goal, const int map_size) {
  std::vector<std::pair<int, int>> route{goal};
  std::pair<int, int> current = goal;
  while (current != start) {
    current = came_from[current.second * map_size + current.first];
    route.push_back(current);
  }
  return route;
}

std::tuple<double, std::optional<std::vector<std::pair<int, int>>>> astar_search(int startx, int starty, int goalx, int goaly,
  const std::vector<std::string> &citymap) {

  std::priority_queue<CommonSearch::Node, std::vector<CommonSearch::Node>, std::greater<CommonSearch::Node>> heap;
  
  CommonSearch::Node start_node = CommonSearch::Node(startx, starty);
  CommonSearch::Node goal_node = CommonSearch::Node(goalx,goaly);

  start_node.cost = CommonSearch::heuristics(start_node, goal_node);
  heap.push(start_node);

  int map_size = citymap.size();
  double gscores[map_size][map_size];
  // std::vector<std::vector<double>> g_scores;
  std::pair<int, int>* camefrom = new std::pair<int, int>[map_size * map_size];
  std::pair<int,int> nullpair{-1,-1};

  for (int i=0;i < map_size;i++) {
    for (int j=0;j < map_size;j++) {
      gscores[i][j] = -1.0;
      camefrom[i * map_size + j] = nullpair;
    }
  }
  gscores[starty][startx] = 0.0;

  while (!heap.empty()) {
    CommonSearch::Node current = heap.top(); 
    heap.pop();
    // std::cout << "current: " << current.x << "," << current.y << std::endl;
    if (current == goal_node) {
      std::cout << "goal found with cost " << current.cost << std::endl;
      auto route = reconstruct_route(camefrom, std::make_pair(startx, starty), std::make_pair(goalx, goaly), map_size);
      return {current.cost, route};
    }

    std::vector<CommonSearch::Node> nodes;
    CommonSearch::children(current.x, current.y, citymap, nodes);

    for (CommonSearch::Node& child : nodes) {
      double tentative_gscore = gscores[current.y][current.x] + child.cost;
      if (gscores[child.y][child.x] == -1 || tentative_gscore  < gscores[child.y][child.x]) {
        gscores[child.y][child.x] = tentative_gscore; 
        camefrom[child.y * map_size + child.x] = std::make_pair(current.x, current.y);
        child.cost = tentative_gscore + CommonSearch::heuristics(child, goal_node);
        heap.push(child);
      }
    }
  }
  std::cout << "path not found" << std::endl;
  return {-1.0, std::nullopt};

}
