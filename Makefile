CXX = g++

INCLUDE_DIR = src/common_search_utils

CXXFLAGS = -Wall -I$(INCLUDE_DIR) -std=c++17
# CXXFLAGS = -c -Wall


build: common_search_utils.o filereader.o scenario_service.o search_service.o main.o
	$(CXX) $(CXXFLAGS) common_search_utils.o filereader.o scenario_service.o search_service.o main.o -o eksekute

common_search_utils.o: src/common_search_utils/common_search_utils.cpp src/common_search_utils/common_search_utils.h
	$(CXX) -c $(CXXFLAGS) src/common_search_utils/common_search_utils.cpp

filereader.o: src/fileIO/filereader.cpp src/fileIO/filereader.h
	$(CXX) -c $(CXXFLAGS) src/fileIO/filereader.cpp

scenario_service.o: src/scenario_service.cpp
	$(CXX) -c $(CXXFLAGS) src/scenario_service.cpp

search_service.o: src/search_service.cpp
	$(CXX) -c $(CXXFLAGS)  src/search_service.cpp

main.o: src/main.cpp
	$(CXX) -c $(CXXFLAGS) src/main.cpp


ifneq ("$(wildcard gtest_Makefile)", "")
  include gtest_Makefile
endif

# include gtest_mf

# Clean up
clean:
	rm -f $(TARGET)

#
# g++ -Wall -c -Isrc/common_search_utils -std=c++14  -Lsrc/lib -lgtest_main tests/heuristics_test.cpp
# -Lsrc/lib -lgtest_main tests/heuristics_test.cpp -o build/heuristics_test
# -Lsrc/lib -lgtest_main tests/heuristics_test.cpp -o build/heuristics_test
