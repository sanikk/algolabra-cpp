#pragma once
#include "scenario_service/scenario_service.h"
#include "searches/astar_search.h"
#include "searches/fringe_search.h"


class SearchService {
public:
  SearchService();
  SearchService(const ScenarioService &scenario_service);
  void run_astar(int index);
  void run_astar(int bucket, int index);
  void run_fringe(int index);
  void run_fringe(int bucket, int index);
private:
  ScenarioService scenario_service;
};
