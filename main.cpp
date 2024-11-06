#include "scenario_service.h"
#include <iostream>
#include <ostream>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "please give a valid .map file as an argument. The .map.scen "
                 "file is also needed."
              << std::endl;
    return 1;
  }
  Scenarios::ScenarioService ss(argv[1]);
  if (argc > 2) {

    Scenarios::Scenario scen = ss.get_scenario(3, 2);
    std::cout << scen.id << " start:" << scen.start_x << "," << scen.start_y
              << ", goal:" << scen.goal_x << "," << scen.goal_y
              << ", cost:" << scen.cost << std::endl;
  }
  return 0;
}
