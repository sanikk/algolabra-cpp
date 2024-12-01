#include <iostream>
#include <unordered_map>


int xy2int(int x, int y, int map_size) {
  return y*map_size + x;
}

int xy2int(std::pair<int, int> pari, int map_size) {
  return xy2int(pari.first, pari.second, map_size);
}

std::pair<int, int> int2xy(int index, int map_size) {
  int x = index % map_size;
  int y = index / map_size;
  return std::make_pair(x,y);
}


struct Link {
  int value;
  Link* prev;
  Link* next;


  Link(int i_value, Link* i_prev, Link* i_next) : value(i_value), prev(i_prev), next(i_next) {};
  Link(int i_value):value(i_value), prev(nullptr), next(nullptr) {};
  Link():prev(nullptr), next(nullptr) {};
  // Link():prev(nullptr),next(nullptr) {};
};


class WrapperIterator {
  Link* current;

  public:
    explicit WrapperIterator(Link* link) : current(link) {}

    int operator*() const { return current -> value; } 
    WrapperIterator& operator++() {
      current = current -> next;
      return *this;
    }
    bool operator!=(const WrapperIterator& other) const { return current != other.current; }
};


class Fringe {
private:
  std::unordered_map<int, Link> links;
  Link* head;
  Link* tail;

public:
  // Fringe();
  // Fringe(int value);


  Fringe():head(nullptr), tail(nullptr) {}
  Fringe(int value):head(nullptr), tail(nullptr) {
    // Link link(value, nullptr, nullptr);
    links.emplace(value, Link(value, tail, nullptr));
    head = &links[value];
    tail = &links[value];
  }


  


  void add(int value) {
    // no recycling version
    if (links.find(value) != links.end()) {
        Link& link = links[value];
        if (link.next != nullptr) {
            link.next->prev = link.prev;
        }
        if (link.prev != nullptr) {
            link.prev->next = link.next;
        }
        if (head == &link) {
            head = link.next;
        }
        if (tail == &link) {
            tail = link.prev;
        }
        links.erase(value);
    }
    links.emplace(value, Link(value, tail, nullptr));
    // Link link(value, tail, nullptr);
    // links[value] = link;
    if (head == nullptr) {
        head = &links[value];
    }
    if (tail != nullptr) {
      tail->next = &links[value];
    }
    tail = &links[value];

  };




  void remove(int value);

  WrapperIterator begin() const {return WrapperIterator(head);}
  WrapperIterator end() const { return WrapperIterator(nullptr);}
  
};


int main() {
    int map_size = 512;
    Fringe fringe;
    int start_index = xy2int(5,5,map_size);
    fringe.add(start_index);
    std::cout << "adding moar" << std::endl;
    fringe.add(xy2int(1,1,map_size));
    fringe.add(xy2int(2,1,map_size));
    fringe.add(xy2int(3,1,map_size));
    fringe.add(xy2int(4,1,map_size));
    fringe.add(xy2int(5,1,map_size));
    fringe.add(xy2int(6,1,map_size));
    fringe.add(xy2int(7,1,map_size));


    for (auto current: fringe)
    {
        std::cout << "current " << current << std::endl;
        const auto[nx, ny] = int2xy(current, map_size);

        std::cout << "unpacked: " << nx << "," << ny << std::endl;
    }
}
