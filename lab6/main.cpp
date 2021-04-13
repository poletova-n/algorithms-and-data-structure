#include "exception.hpp"
#include "queuearray.hpp"
#include "queuelist.hpp"
#include "tree.hpp"

#include <iostream>

int main()
{
  std::cout << "iterative search in width: \n";
  BinarySearchTree<int> tree;
  tree.iterativeAppend(1);
  tree.iterativeAppend(0);
  tree.iterativeAppend(2);
  tree.iterativeAppend(1);
  tree.iterativeAppend(7);

  BinarySearchTree<int> tree2;
  tree2.iterativeAppend(1);
  tree2.iterativeAppend(0);
  tree2.iterativeAppend(2);
  tree2.iterativeAppend(5);

  BinarySearchTree<int> tree3;
  tree3.iterativeAppend(1);
  tree3.iterativeAppend(6);
  tree3.iterativeAppend(4);
  tree.iterativeSearchInWidth();
  std::cout << "\n Used prefix search: \n";
  std::vector<int> vec = tree.iterativePrefixSearch();
  for (size_t i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i] << ' ';
  }
  return 0;
}
