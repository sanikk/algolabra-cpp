CXX = c++

INCLUDE_DIR = src/common_search

CXXFLAGS = -Wall -I$(INCLUDE_DIR) -std=c++17
# CXXFLAGS = -c -Wall
# g++ -c Wall -Isrc/common_search -std=c++17

build: filereader.o scenario_service.o children.o heuristics.o astar_search.o fringe_search.o search_service.o main.o
	$(CXX) $(CXXFLAGS) filereader.o scenario_service.o heuristics.o children.o fringe_search.o astar_search.o search_service.o main.o -o eksekute


filereader.o: src/scenario_service/filereader.cpp src/scenario_service/filereader.h
	$(CXX) -c $(CXXFLAGS) src/scenario_service/filereader.cpp

scenario_service.o: src/scenario_service/scenario_service.cpp src/scenario_service/scenario_service.h src/scenario_service/filereader.h
	$(CXX) -c $(CXXFLAGS) src/scenario_service/scenario_service.cpp

children.o: src/common_search/children.cpp src/common_search/children.h src/common_search/node.h
	$(CXX) -c $(CXXFLAGS) src/common_search/children.cpp

heuristics.o: src/common_search/heuristics.cpp src/common_search/heuristics.h src/common_search/node.h
	$(CXX) -c $(CXXFLAGS) src/common_search/heuristics.cpp

astar_search.o: src/common_search/astar_search.cpp src/common_search/astar_search.h src/common_search/children.h src/common_search/heuristics.h
	$(CXX) -c $(CXXFLAGS) src/common_search/astar_search.cpp

fringe_search.o: src/common_search/fringe_search.cpp src/common_search/fringe_search.h src/common_search/children.h src/common_search/heuristics.h
	$(CXX) -c $(CXXFLAGS) src/common_search/fringe_search.cpp


search_service.o: src/search_service.cpp src/search_service.h src/common_search/fringe_search.h src/common_search/astar_search.h
	$(CXX) -c $(CXXFLAGS)  src/search_service.cpp

main.o: src/main.cpp src/search_service.h src/scenario_service/scenario_service.h
	$(CXX) -c $(CXXFLAGS) src/main.cpp

	

ifneq ("$(wildcard gtest_Makefile)", "")
  include gtest_Makefile
endif

# Clean up
clean:
	# rm -f *.o 
	find . -type f -name '*.o' -delete
