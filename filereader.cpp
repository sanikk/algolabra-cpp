#include <bits/stdc++.h>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <string>
#include <vector>

std::vector<std::string> read_map_mki(const std::string &filename,
                                      int skip_count = 4) {
  std::ifstream f(filename);

  int width;

  if (!f) {
    std::cout << "error reading " << filename << '\n';
  }

  std::string str;
  std::vector<std::string> lines;

  while (getline(f, str)) {
    if (skip_count > 0) {
      if (str.compare(0, 6, "width ") == 0) {
        width = std::stoi(str.substr(6, std::string::npos));
      }
      skip_count--;
      continue;
    }

    if (str.empty())
      continue;

    if (str.size() < width)
      continue;

    lines.push_back(str.substr(0, width));
  }
  return lines;
}

std::string *read_map(const std::string &filename, int skip_count = 4) {
  std::ifstream f(filename);

  if (!f) {
    std::cout << "error reading " << filename << '\n';
    throw std::invalid_argument("error reading file");
  }

  int width;

  std::string str;

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

int main() {
  auto data = read_map("Boston_0_512.map", 4);

  std::cout << data->size() << std::endl;
  std::cout << data[0].size() << std::endl;
  return 0;
}
