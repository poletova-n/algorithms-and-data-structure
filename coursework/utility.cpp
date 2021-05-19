#include "utility.hpp"

#include <string>
#include <iostream>
#include <memory>
#include <limits>

void preparation::Symbols::addSym(const char c)
{
  std::string symbol;
  symbol += c;
  auto it = frequency_.find(symbol);
  if (it == frequency_.end())
  {
    frequency_.insert({symbol, 1});
  }
  else
  {
    (it->second)++;
  }
}

void preparation::Symbols::showAll()
{
  for (auto i = frequency_.begin(); i != frequency_.end(); ++i)
  {
    std::cout << i->first << ": " << i->second << " time(s)\n";
  }
}

std::vector<char> preparation::readFromFile(preparation::Symbols& map)
{
  std::string filename;
  std::cin >> filename;
  std::ifstream stream(filename);
  if (!stream)
  {
    throw std::invalid_argument("File cannot be opened");
  }
  std::vector<char> vec;
  char c;
  while (stream.peek() != EOF)
  {
    stream.get(c);
    vec.push_back(c);
    map.addSym(c);
  }
  return vec;
}

preparation::Symbols::iterator preparation::Symbols::findMin()
{
  unsigned min = std::numeric_limits<unsigned>::max();
  auto it = frequency_.begin();
  for (auto i = frequency_.begin(); i != frequency_.end(); ++i)
  {
    if (min > i->second)
    {
      it = i;
      min = i->second;
    }
  }
  return it;
}

preparation::Symbols::map_& preparation::Symbols::getMap()
{
  return this->frequency_;
}

BinaryTree::Node* details::findRoot(std::vector<BinaryTree::Node*> vec)
{
  BinaryTree::Node* root = nullptr;
  for (auto it = vec.begin();
       it != vec.end();
       ++it)
  {
    if ((*it)->p_ == nullptr)
    {
      root = *it;
      break;
    }
  }
  return root;
}
