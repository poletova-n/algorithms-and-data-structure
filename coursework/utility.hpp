#ifndef COURSEWORK_UTILITY_HPP
#define COURSEWORK_UTILITY_HPP

#include <fstream>
#include <map>
#include <vector>

#include "BinaryTree.hpp"

namespace preparation
{
  class Symbols
  {
  public:
    using map_ = std::map<std::string, unsigned>;
    using iterator = map_::iterator;

    void addSym(const char);
    void showAll();
    iterator findMin();
    map_& getMap();

  private:
    map_ frequency_;
  };

  std::vector<char> readFromFile(Symbols&);
}

namespace details
{
  BinaryTree::Node* findRoot(std::vector<BinaryTree::Node*>);
}

#endif //COURSEWORK_UTILITY_HPP
