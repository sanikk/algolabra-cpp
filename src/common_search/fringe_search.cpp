#include "../common_search/common_search.h"
#include <deque>
#include <limits>
#include <tuple>
#include <unordered_map>
#include <iostream>
// #include <utility>
#include <optional>
#include <utility>
#include <algorithm>

template<typename M, typename K, typename... Args>
void emplaced(M& map, K&& key, Args&&... args) {
  map.emplace(std::piecewise_construct,
    std::forward_as_tuple(std::forward<K>(key)),
    std::forward_as_tuple(std::forward<Args>(args)...)
  );
}

 std::tuple<double, std::optional<std::vector<std::pair<int, int>>>> fringe_search(int startx, int starty, int goalx, int goaly, const std::vector<std::string>& citymap) {
  // TODO: at least scenarios 1336, 1337, 162 give wrong answers. mabbe visualize?
  int map_size = citymap.size(); 
  
  int start = starty * map_size + startx;
  int goal = goaly * map_size + goalx;

  std::deque<int> now = {start};
  std::deque<int> later;

  double flimit = CommonSearch::heuristics(startx, starty, goalx, goaly);
  // std::cout << "flimit " << flimit << std::endl;
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
        data = {std::get<0>(data), std::get<1>(data), std::get<1>(data) + CommonSearch::heuristics(nx, ny, goalx, goaly)};
        cache[current] = data;
      }

      if (std::get<2>(data) > flimit) {
        fmin = std::min(std::get<2>(data), fmin);
        if (std::find(later.begin(), later.end(), current) == later.end()) {
          later.push_back(current);
        }
        continue;
      }

      if (current == goal) {
        found = true;
        std::cout << "found with cost " << std::get<1>(data) << std::endl;
        return {std::get<1>(data), std::nullopt};
      }
      CommonSearch::children(nx, ny, citymap, children_list);
      for (const auto& [cx, cy, cc] : children_list) {
        int child_index = cy * map_size + cx;
        double g_child = std::get<1>(data) + cc;
        auto res = cache.find(child_index);
        if (res != cache.end() && std::get<1>(res->second) < g_child) {
          continue;
        }
        emplaced(cache, child_index, current, g_child, -1);
        now.push_back(child_index);
      }
      children_list.clear();
    }
    if (!found) {
      if (later.empty()) {
        return {-1.0, std::nullopt};
      }
      std::swap(now, later);
      flimit = fmin;
      std::cout << "flimit set to " << flimit << std::endl;
    }
  }
  return {-1.0, std::nullopt};

}
