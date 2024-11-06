// #include "filereader.h"
#include "scenario_service.h"
#include <iostream>
// #include <vector>

int funcone() { return 1; }

int main(int argc, char *argv[]) {
  if (argc < 2) {
    std::cout << "please give a valid .map file as an argument. The .map.scen "
                 "file is also needed."
              << std::endl;
    return 1;
  }
  // std::vector<std::string> citymap = read_map(argv[1], 4);
  Scenarios::ScenarioService ss(argv[1]);
  // std::cout << citymap.size() << std::endl;
  return 0;
}
