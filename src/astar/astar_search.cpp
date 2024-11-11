#include "common_search.h"

#include <queue>
#include <vector>
#include <unordered_map>

#include <string>
#include <iostream>

namespace CommonSearch::AstarSearch {
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
    int gscores[map_size][map_size];
    //int camefrom[mapsize][mapsize];
    for (int i=0;i < map_size;i++) {
      for (int j=0;j < map_size;j++) {
        gscores[i][j] = -1;
        // camefrom[i][j] = 0;
      }
    }
    gscores[starty][startx] = 0;

    while (!heap.empty()) {
      CommonSearch::Node current = heap.top(); 
      heap.pop();
      if (current == goal_node) {
        std::cout << "goal found with cost " << current.cost << std::endl;
        return current.cost;
      }
      for (CommonSearch::Node child : children(current.x, current.y, citymap)) {
        double tentative_gscore = gscores[current.y][current.x] + child.cost;
        if (gscores[child.y][child.x] == -1 || tentative_gscore  < gscores[child.y][child.x]) {
          gscores[child.y][child.x] = tentative_gscore; 
          // camefrom[child.y][child.x] = current;
        }
      }
    }
    std::cout << "path not found" << std::endl;
    return -1.0;

}
}//namespace
//    # init
//    map_size = len(citymap)
//    heap = []
//    diff = diag_cost - Decimal('1')
//    heappush(heap, (heuristics(*start, *goal, diff), start))
//    came_from = {start: 0}
//    g_scores = {start:0}
//
//    while heap:
//        estimate, current = heappop(heap)
//        if current == goal:
//            final_cost = g_scores[current]
//            rounded = getcontext().flags[Rounded]
//            inexact = getcontext().flags[Inexact]
//
//            return final_cost, reconstruct_path(start, goal, came_from), rounded, inexact
//
//        for x, y, cost in children(*current, citymap, diag_cost, map_size):
//            child = x, y
//            tentative_gscore = g_scores[current] + cost
//            if tentative_gscore < g_scores.get(child, 10000000):
//                came_from[child] = current
//                g_scores[child] = tentative_gscore
//
//                fscore = tentative_gscore + heuristics(x, y, *goal, diff)
//                heappush(heap, (fscore, child))
