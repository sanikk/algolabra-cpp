// #include "common_search_utils.h"
#include <vector>
#include <string>


namespace CommonSearch::AstarSearch {

int get_one();

double astar_search(int startx, int starty, int goalx, int goaly, std::vector<std::string> &citymap);


//struct NodeEqual {
//    bool operator()(const Node& n1, const Node& n2) const {
//        return n1.x == n2.x && n1.y == n2.y;
//    }
//};
}//namespace
