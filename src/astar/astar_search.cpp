#include "../common_search/common_search.h"

#include <queue>
#include <vector>

#include <string>
#include <iostream>
 
int get_one() {
  return 1;
}

double astar_search(int startx, int starty, int goalx, int goaly,
  const std::vector<std::string> &citymap) {

  
  std::priority_queue<CommonSearch::Node, std::vector<CommonSearch::Node>, std::greater<CommonSearch::Node>> heap;
  
  CommonSearch::Node start_node = CommonSearch::Node(startx, starty);
  CommonSearch::Node goal_node = CommonSearch::Node(goalx,goaly);

  start_node.cost = CommonSearch::heuristics(start_node, goal_node);
  heap.push(start_node); 

  int map_size = citymap.size();
  double gscores[map_size][map_size];
  std::pair<int, int> camefrom[map_size][map_size];
  std::pair<int,int> nullpair{-1,-1};
  for (int i=0;i < map_size;i++) {
    for (int j=0;j < map_size;j++) {
      gscores[i][j] = -1.0;
      camefrom[i][j] = nullpair;
    }
  }
  gscores[starty][startx] = 0.0;

  while (!heap.empty()) {
    CommonSearch::Node current = heap.top(); 
    heap.pop();
    // std::cout << "current: " << current.x << "," << current.y << std::endl;
    if (current == goal_node) {
      std::cout << "goal found with cost " << current.cost << std::endl;
      return current.cost;
    }

    std::vector<CommonSearch::Node> nodes;
    CommonSearch::children(current.x, current.y, citymap, nodes);

    for (CommonSearch::Node& child : nodes) {
      double tentative_gscore = gscores[current.y][current.x] + child.cost;
      if (gscores[child.y][child.x] == -1 || tentative_gscore  < gscores[child.y][child.x]) {
        gscores[child.y][child.x] = tentative_gscore; 
        camefrom[child.y][child.x] = std::make_pair(current.x, current.y);
        child.cost = tentative_gscore + CommonSearch::heuristics(child, goal_node);
        heap.push(child);
      }
    }
  }
  std::cout << "path not found" << std::endl;
  return -1.0;

}
