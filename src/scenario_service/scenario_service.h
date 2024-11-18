#pragma once
#include "filereader.h"
#include <string>
#include <vector>
#include <stdexcept>

class ScenarioService {

public:
  ScenarioService(double diag_cost = 1.414);
  ScenarioService(const std::string filename, double diag_cost = 1.414);
  Scenario get_scenario(int index);
  Scenario get_scenario(int bucket, int index);
  std::vector<std::string> get_map();

private:
  std::string filename{""};
  double diag_cost;
  std::vector<std::string> citymap;
  std::vector<Scenario> scenarios;
};

