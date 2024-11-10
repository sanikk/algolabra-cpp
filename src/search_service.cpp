#include "search_service.h"
#include "scenario_service.h"
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
}
void Searches::SearchService::run_search(int bucket, int index) {
  Searches::SearchService::run_search(10 * bucket + index);
}
