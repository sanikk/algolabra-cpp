#pragma once
#include "filereader.h"
#include <cmath>
#include <string>
#include <vector>
namespace Scenarios {

struct Scenario {
  int id;
  int start_x;
  int start_y;
  int goal_x;
  int goal_y;
  float cost;
};

class ScenarioService {

public:
  ScenarioService(double diag_cost = 1.414);
  ScenarioService(const std::string filename, double diag_cost = 1.414);
  void get_scenario_startgoalcost(int bucket, int index);
  void get_scenario_startgoalcost(int index);
  Scenario get_scenario(int index);
  Scenario get_scenario(int bucket, int index);

private:
  std::string filename{""};
  double diag_cost;
  std::vector<std::string> citymap;
  std::vector<Scenario> scenarios;
};

} // namespace Scenarios
