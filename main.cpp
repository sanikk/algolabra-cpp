#include "filereader.h"
#include <iostream>
#include <vector>

int main() {
  std::vector<std::string> citymap = read_map("Boston_0_512.map", 4);
  std::cout << citymap.size() << std::endl;
  return 0;
}
