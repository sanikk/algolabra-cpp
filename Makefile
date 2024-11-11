CXX = g++

INCLUDE_DIR = src/common_search

CXXFLAGS = -Wall -I$(INCLUDE_DIR) -std=c++17
# CXXFLAGS = -c -Wall
# g++ -c Wall -Isrc/common_search -std=c++17

build: common_search.o filereader.o scenario_service.o search_service.o main.o
	$(CXX) $(CXXFLAGS) common_search.o filereader.o scenario_service.o search_service.o main.o -o eksekute

common_search.o: src/common_search/common_search.cpp src/common_search/common_search.h
	$(CXX) -c $(CXXFLAGS) src/common_search/common_search.cpp

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
