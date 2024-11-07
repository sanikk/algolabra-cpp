#include "scenario_service.h"
#include "../fileIO/filereader.h"
#include <iostream>
#include <stdexcept>
#include <string>

namespace Scenarios {

ScenarioService::ScenarioService(double diag_cost) : diag_cost(diag_cost) {}

ScenarioService::ScenarioService(std::string filename, double diag_cost)
    : filename(filename), scenarios(read_scenarios(filename + ".scen")),
      citymap(read_map(filename, 4)), diag_cost(diag_cost) {}

Scenario ScenarioService::get_scenario(int bucket, int index) {
  if (bucket < 0 || index < 0) {
    std::cerr << "bucket and index have to be positive ints." << std::endl;
    throw std::invalid_argument("invalid scenario argument.");
  }
  return get_scenario(10 * bucket + index);
}

Scenario ScenarioService::get_scenario(int index)

{
  if (index < 0 || index >= scenarios.size()) {
    throw std::invalid_argument("invalid scenario number.");
  }
  return scenarios[index];
}
} // namespace Scenarios
