#include "scenario_service/scenario_service.h"
#include "search_service.h"
#include <iostream>
#include <ostream>
#include <string>
#include <cstring>


void show_help() {
  std::cout << "Little search prog" << std::endl;
  std::cout << "<prog> run \"scenario_file\" bucket index" << std::endl;
  std::cout << "<prog> run \"scenario_file\" index" << std::endl;
  std::cout << "<prog> run \"scenario_file\" bucket index" << std::endl;
  std::cout << "please give a valid .map file as an argument. The .map.scen "
               "file is also needed."
            << std::endl;
}

int main(int argc, char *argv[]) {
  if (argc > 2) {
    ScenarioService scenario_service(argv[2]);
    SearchService search_service(scenario_service);
    if (std::strcmp("astar", argv[1]) == 0) {
      if (argc == 5) {
        search_service.run_astar(std::stoi(argv[3]), std::stoi(argv[4]));
        return 0;
      } else if (argc == 4) {
        search_service.run_astar(std::stoi(argv[3]));
        return 0;
      } else {
        show_help();
        return 1;
      }
    } else if (std::strcmp("fringe", argv[1]) == 0) {
      if (argc == 5) {
        search_service.run_fringe(std::stoi(argv[3]), std::stoi(argv[4]));
        return 0;
      } else if (argc == 4) {
        search_service.run_fringe(std::stoi(argv[3]));
        return 0;
      } else {
        show_help();
        return 1;
      }
    }
  show_help();
  return 1;
  }
}
