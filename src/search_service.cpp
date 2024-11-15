#include "search_service.h"
#include "scenario_service.h"
#include "astar/astar_search.h"
#include <iostream>

Searches::SearchService::SearchService() {}

Searches::SearchService::SearchService(
    const Scenarios::ScenarioService &scenario_service)
    : scenario_service(scenario_service) {};

void Searches::SearchService::run_search(int index) {
  Scenarios::Scenario scen = scenario_service.get_scenario(index);
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
void Searches::SearchService::run_search(int bucket, int index) {
  Searches::SearchService::run_search(10 * bucket + index);
}
