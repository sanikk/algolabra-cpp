#include "scenario_service.h"
#include "filereader.h"
#include <iostream>

namespace Scenarios {

ScenarioService::ScenarioService(double diag_cost) : diag_cost(diag_cost) {
  // std::cout << "executing default constructor" << std::endl;
}

ScenarioService::ScenarioService(std::string filename, double diag_cost)
    : filename(filename), scenarios(read_scenarios(filename + ".scen")),
      citymap(read_map(filename, 4)), diag_cost(diag_cost) {
  // std::cout << "executing parametrized constructor" << std::endl;
  std::cout << citymap.size() << std::endl;
}
} // namespace Scenarios
