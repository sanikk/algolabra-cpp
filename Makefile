CXX = c++

INCLUDE_DIR = src/common_search

CXXFLAGS = -Wall -I$(INCLUDE_DIR) -std=c++17
# CXXFLAGS = -c -Wall
# g++ -c Wall -Isrc/common_search -std=c++17

build: filereader.o common_search.o astar_search.o fringe_search.o scenario_service.o search_service.o main.o
	$(CXX) $(CXXFLAGS) common_search.o filereader.o astar_search.o scenario_service.o search_service.o main.o -o eksekute

filereader.o: src/fileIO/filereader.cpp src/fileIO/filereader.h
	$(CXX) -c $(CXXFLAGS) src/fileIO/filereader.cpp

common_search.o: src/common_search/common_search.cpp src/common_search/common_search.h
	$(CXX) -c $(CXXFLAGS) src/common_search/common_search.cpp

astar_search.o: src/astar/astar_search.cpp src/astar/astar_search.h src/common_search/common_search.h
	$(CXX) -c $(CXXFLAGS) src/astar/astar_search.cpp

fringe_search.o: src/fringe/fringe_search.cpp src/fringe/fringe_search.h src/common_search/common_search.h
	$(CXX) -c $(CXXFLAGS) src/fringe/fringe_search.cpp

scenario_service.o: src/scenario_service.cpp src/fileIO/filereader.cpp src/fileIO/filereader.h
	$(CXX) -c $(CXXFLAGS) src/scenario_service.cpp

search_service.o: src/search_service.cpp
	$(CXX) -c $(CXXFLAGS)  src/search_service.cpp

main.o: src/main.cpp
	$(CXX) -c $(CXXFLAGS) src/main.cpp


ifneq ("$(wildcard gtest_Makefile)", "")
  include gtest_Makefile
endif

# Clean up
clean:
	# rm -f *.o 
	find . -type f -name '*.o' -delete
