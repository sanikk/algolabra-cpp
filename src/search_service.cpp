#include "search_service.h"
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

SearchService::SearchService() {}

SearchService::SearchService(
    const ScenarioService &scenario_service)
    : scenario_service(scenario_service) {};

void SearchService::run_astar(int index) {
  Scenario scen = scenario_service.get_scenario(index);
  std::cout << scen.id << " start:" << scen.start_x << "," << scen.start_y
            << ", goal:" << scen.goal_x << "," << scen.goal_y
            << ", cost:" << scen.cost << std::endl;
  const auto& citymap = scenario_service.get_map();
  auto [cost, routeOpt] = astar_search(scen.start_x, scen.start_y, scen.goal_x, scen.goal_y, citymap);
  std::cout << cost << std::endl;
  if (routeOpt) {
    const auto route = routeOpt.value();
    for (auto [x, y] : route) {
      std::cout << x << "," << y << ": " << citymap[y][x] << std::endl;
    }
  }
  // TODO remove this
  // debugging children..
  // std::vector<std::string> le_map{"...", "...", "..."};
  // std::vector<CommonSearch::Node> vec;
  // CommonSearch::children(1, 1, le_map, vec);
  // std::cout << vec.size() << std::endl;
  // for (int i=0;i < vec.size();i++) {
  //   std::cout << vec[i].x << "," << vec[i].y << ": " << vec[i].cost << std::endl;
  // }

}


void print_route(std::vector<std::pair<int, int>> route) {
  for (std::pair<int, int> here : route) {
    std::cout << here.first << "," << here.second << std::endl;
  }
}


void SearchService::run_astar(int bucket, int index) {
  SearchService::run_astar(10 * bucket + index);
}

void SearchService::run_fringe(int index) {
  Scenario scen = scenario_service.get_scenario(index);
  std::cout << scen.id << " start:" << scen.start_x << "," << scen.start_y
            << ", goal:" << scen.goal_x << "," << scen.goal_y
            << ", cost:" << scen.cost << std::endl;
  const auto& citymap = scenario_service.get_map();
  auto [cost, routeOpt] = fringe_search(scen.start_x, scen.start_y, scen.goal_x, scen.goal_y, citymap);
  std::cout << cost << std::endl;
  if (routeOpt) {
    const auto route = routeOpt.value();
    for (auto [x, y] : route) {
      std::cout << x << "," << y << ": " << citymap[y][x] << std::endl;
    }
  }
}

void SearchService::run_fringe(int bucket, int index) {
  SearchService::run_fringe(bucket * 10 + index);
}

const double EPSILON = 0.0001;

int SearchService::full_comparison_run() {
  std::vector<Scenario> scenarios = scenario_service.get_all_scenarios();
  for (Scenario scenario : scenarios) {
    // std::tuple<double, std::optional<std::vector<std::pair<int, int>>>>

    auto [astar_cost, astar_routeOpt] = astar_search(scenario.start_x, scenario.start_y, scenario.goal_x, scenario.goal_y, scenario_service.get_map());
    auto [fringe_cost, fringe_routeOpt] = fringe_search(scenario.start_x, scenario.start_y, scenario.goal_x, scenario.goal_y, scenario_service.get_map());
    if (fabs(astar_cost - scenario.cost) > EPSILON) {
      std::cout << "astar cost " << astar_cost << " is not correct, " << scenario.cost << std::endl;
      return 1;
    }
    if (fabs(fringe_cost - astar_cost) > EPSILON) {
      std::cout << "astar: " << astar_cost << ", fringe: " << fringe_cost << " while scenario says " << scenario.cost << std::endl;
      if (astar_routeOpt) {
        std::cout << "astar" << std::endl;
        print_route(astar_routeOpt.value());
      }
      if (fringe_routeOpt) {
        std::cout << "fringe" << std::endl;
        print_route(fringe_routeOpt.value());
      }
      return 1;
    }
  }
  return 0;
}

void SearchService::astar_full_run() {

}

void SearchService::fringe_full_run() {
}

