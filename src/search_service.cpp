#include "search_service.h"
// #include "common/searches_common.h"
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


void print_route(std::vector<std::pair<int, int>> astar_route, std::vector<std::pair<int, int>> fringe_route) {
  // std::reverse(astar_route.begin(), astar_route.end());
  // std::reverse(fringe_route.begin(), fringe_route.end());
  std::cout << "astar" << "\tfringe" << std::endl;
  for (int i=0; i < fmax(astar_route.size(), fringe_route.size()); i++) {
    if(astar_route.size() > i) {
      std::cout << astar_route[i].first << "," << astar_route[i].second;
    }
    if(fringe_route.size() > i) {
      std::cout << "\t" << fringe_route[i].first << "," << fringe_route[i].second;
    }
    std::cout << std::endl;
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
    // std::reverse(route.begin(), route.end());
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
    std::cout << scenario.cost << std::endl;
    std::cout << "astar" << std::endl;
    auto [astar_cost, astar_routeOpt] = astar_search(scenario.start_x, scenario.start_y, scenario.goal_x, scenario.goal_y, scenario_service.get_map());
    std::cout << "fringe" << std::endl;
    // auto [fringe_cost, fringe_routeOpt] = fringe_search(scenario.start_x, scenario.start_y, scenario.goal_x, scenario.goal_y, scenario_service.get_map());
    double fringe_cost = fringe_search_unopt(scenario.start_x, scenario.start_y, scenario.goal_x, scenario.goal_y, scenario_service.get_map());
    if (fabs(astar_cost - scenario.cost) > EPSILON) {
      std::cout << "astar cost " << astar_cost << " is not correct, " << scenario.cost << std::endl;
      return 1;
    }
    if (fabs(fringe_cost - astar_cost) > EPSILON) {
      std::cout << "astar: " << astar_cost << ", fringe: " << fringe_cost << " while scenario says " << scenario.cost << std::endl;
      // if (astar_routeOpt && fringe_routeOpt) {
      //  print_route(astar_routeOpt.value(), fringe_routeOpt.value());
      // }
      return 1;
    }
  }
  return 0;
}

void SearchService::astar_full_run() {

}

void SearchService::fringe_full_run() {
}

void SearchService::fringe_unopt(int scenario_id) {
  Scenario scen = scenario_service.get_scenario(scenario_id);
  std::cout << scen << std::endl;
  fringe_search_unopt(scen.start_x, scen.start_y, scen.goal_x, scen.goal_y, scenario_service.get_map());
}

