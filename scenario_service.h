#pragma once
#include "filereader.h"
#include <cmath>
#include <string>
#include <vector>
namespace Scenarios {

class ScenarioService {

public:
  ScenarioService(double diag_cost = 1.414);
  ScenarioService(const std::string filename, double diag_cost = 1.414);

private:
  std::string filename{""};
  // double diag_cost{1.414};
  double diag_cost;
  std::vector<std::string> citymap;
  std::vector<Scenario> scenarios;
};

struct Scenario {
  int id;
  int start_x;
  int start_y;
  int goal_x;
  int goal_y;
  float cost;
};
} // namespace Scenarios
