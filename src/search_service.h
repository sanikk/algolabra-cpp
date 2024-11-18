#pragma once
#include "scenario_service.h"
#include "common_search/astar_search.h"
#include "common_search/fringe_search.h"

namespace Searches {

class SearchService {
public:
  SearchService();
  SearchService(const Scenarios::ScenarioService &scenario_service);
  void run_astar(int index);
  void run_astar(int bucket, int index);
  void run_fringe(int index);
  void run_fringe(int bucket, int index);
private:
  Scenarios::ScenarioService scenario_service;
};
} // namespace Searches
