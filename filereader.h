#pragma once
#include <string>
#include <vector>

namespace Scenarios {
struct Scenario;
}

std::vector<std::string> read_map(const std::string &filename, int skip_count);
std::vector<Scenarios::Scenario> read_scenarios(const std::string &filename);
