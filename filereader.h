#pragma once
#include <string>
#include <vector>

struct Scenario {
  int id;
  int start_x;
  int start_y;
  int goal_x;
  int goal_y;
  float cost;
};

std::vector<std::string> read_map(const std::string &filename, int skip_count);
std::vector<Scenario> read_scenarios(std::string filename);
