#include "scenario_service.h"
#include "search_service.h"
#include <iostream>
#include <ostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "please give a valid .map file as an argument. The .map.scen "
                 "file is also needed."
              << std::endl;
    return 1;
  }
  Scenarios::ScenarioService scenario_service(argv[1]);
  Searches::SearchService search_service(scenario_service);

  if (argc > 2) {
    search_service.run_search(std::stoi(argv[2]), std::stoi(argv[3]));
    // Scenarios::Scenario scen =
    // scenario_service.get_scenario(3, 2);
    // std::cout << scen.id << " start:" << scen.start_x << "," << scen.start_y
    //          << ", goal:" << scen.goal_x << "," << scen.goal_y
    //          << ", cost:" << scen.cost << std::endl;
  }
  return 0;
}
