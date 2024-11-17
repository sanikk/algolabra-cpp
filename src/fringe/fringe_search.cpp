#include "../common_search/common_search.h"
#include <deque>
#include <limits>
#include <tuple>
#include <unordered_map>
#include <iostream>
#include <utility>

template<typename M, typename K, typename... Args>
void emplaced(M& map, K&& key, Args&&... args) {
  map.emplace(std::piecewise_construct,
    std::forward_as_tuple(std::forward<K>(key)),
    std::forward_as_tuple(std::forward<Args>(args)...)
  );
}

double fringe_search(int startx, int starty, int goalx, int goaly, std::vector<std::string> citymap) {
  int map_size = citymap.size(); 
  
  int start = starty * map_size + startx;
  int goal = goaly * map_size + goalx;

  std::deque<int> now = {start};
  std::deque<int> later;

  double flimit = CommonSearch::heuristics(startx, starty, goalx, goaly);
  bool found = false;

  std::unordered_map<int, std::tuple<int, double, double>> cache;
  std::vector<std::tuple<int, int, double>> children_list;
  emplaced(cache, start, -1, 0.0, flimit);
  while (!found) {
    double fmin = std::numeric_limits<double>::max();
    while (!now.empty() && not found) {
      int current = now.back();
      now.pop_back();
    
      std::tuple<int, double, double> data = cache[current];
      int ny = current / map_size; 
      int nx = current % map_size;

      if (std::get<2>(data) == -1) {
        data = {std::get<0>(data), std::get<1>(data), CommonSearch::heuristics(nx, ny, goalx, goaly)};
        cache[current] = data;
      }

      if (std::get<2>(data) > flimit) {
        fmin = std::min(std::get<2>(data), fmin);
        later.push_back(current);
        continue;
      }

      if (current == goal) {
        found = true;
        std::cout << "found with cost " << std::get<1>(data) << std::endl;
        return std::get<1>(data);
      }
      children_list.clear();
      CommonSearch::children(nx, ny, citymap, children_list);
      for (const auto& [cx, cy, cc] : children_list) {
        int child_index = cy * map_size + cx;
        double g_child = std::get<1>(data) + cc;
        auto res = cache.find(child_index);
        if (res != cache.end() && std::get<1>(res->second) < g_child) {
          continue;
        }
        emplaced(cache, child_index, current, g_child, -1); 
      }
    }
    if (!found) {
      flimit = fmin;
    }
  }
  return -1.0;
}
