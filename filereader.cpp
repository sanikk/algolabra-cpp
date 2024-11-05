#include <fstream>
#include <iostream>
#include <limits>
#include <sstream>
#include <string>
#include <vector>

std::ifstream read_file(const std::string &filename) {
  std::ifstream f(filename);

  if (!f) {
    std::cout << "error reading " << filename << '\n';
    throw std::invalid_argument("error reading file");
  }
  return f;
}

std::string *read_map_array(const std::string &filename, int skip_count = 4) {
  // jäi /r sinne loppuun koko ajan niin leikataan mittaansa.
  int width;
  std::string str;

  auto f = read_file(filename);

  while (skip_count > 0 && getline(f, str)) {
    if (str.compare(0, 6, "width ") == 0) {
      width = std::stoi(str.substr(6, std::string::npos));
    }
    skip_count--;
    continue;
  }

  std::string *arr = new std::string[width];

  for (int i = 0; i < width; i++) {
    getline(f, str);
    if (str.empty() || str.size() < width) {
      continue;
    }
    arr[i] = str.substr(0, width);
  }

  return arr;
}

std::vector<std::string> read_map(const std::string &filename,
                                  int skip_count = 4) {
  // jäi /r sinne loppuun koko ajan niin leikataan mittaansa.
  int width;
  std::string str;

  std::ifstream f = read_file(filename);

  while (skip_count > 0 && getline(f, str)) {
    if (str.compare(0, 6, "width ") == 0) {
      width = std::stoi(str.substr(6, std::string::npos));
    }
    skip_count--;
    continue;
  }

  std::vector<std::string> citymap;

  while (getline(f, str)) {
    if (str.empty() || str.size() < width)
      continue;
    citymap.push_back(str.substr(0, width));
  }
  return citymap;
}

struct Scenario {
  int id;
  int start_x;
  int start_y;
  int goal_x;
  int goal_y;
  float cost;
};

std::vector<Scenario> read_scenarios(std::string filename) {
  std::ifstream f = read_file(filename);

  std::vector<Scenario> scenarios;

  std::string str;
  getline(f, str);
  if (f.peek() == 'v')
    f.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

  while (getline(f, str)) {
    if (str.empty()) {
      continue;
    }
    std::istringstream iss(str);
    Scenario scenario;
    iss >> scenario.id;
    iss.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
    iss.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
    iss.ignore(std::numeric_limits<std::streamsize>::max(), '\t');
    iss >> scenario.start_x >> scenario.start_y >> scenario.goal_x >>
        scenario.goal_y >> scenario.cost;
    scenarios.push_back(scenario);
  }
  return scenarios;
}
//
// int main() {
//  auto data = read_scenarios("Boston_0_512.map.scen");
//
//  std::cout << data.size() << std::endl;
//
//  auto citymap = read_map("Boston_0_512.map");
//
//  std::cout << citymap.size() << std::endl;
//
//  return 0;
//}
