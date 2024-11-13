#include "scenario_service.h"
#include "search_service.h"
#include <iostream>
#include <ostream>
#include <string>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cerr << "please give a valid .map file as an argument. The .map.scen "
                 "file is also needed."
              << std::endl;
    return 1;
  }
  Scenarios::ScenarioService scenario_service(argv[1]);
  Searches::SearchService search_service(scenario_service);

  if (argc == 4) {
    search_service.run_search(std::stoi(argv[2]), std::stoi(argv[3]));
  } else if (argc == 3) {
    search_service.run_search(std::stoi(argv[2]));
  }
  return 0;
}
