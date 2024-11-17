#pragma once
#include "scenario_service.h"

namespace Searches {

class SearchService {
public:
  SearchService();
  SearchService(const Scenarios::ScenarioService &scenario_service);
  void run_search(int index);
  void run_search(int bucket, int index);

  void run_astar(int index);
  void run_astar(int bucket, int index);
private:
  Scenarios::ScenarioService scenario_service;
};
} // namespace Searches
