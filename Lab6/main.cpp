#include "exceptions.h"
#include "queuearray.h"
#include "queuelist.h"
#include "tree.h"

#include <iostream>

int main()
{
  std::cout << "Created tree and used iterative search in width: \n";
  BinarySearchTree<int> tree;
  tree.iterativeAppend(2);
  tree.iterativeAppend(4);
  tree.iterativeAppend(6);
  tree.iterativeAppend(3);
  tree.iterativeAppend(1);
  tree.iterativeAppend(0);
  tree.iterativeAppend(5);
  BinarySearchTree<int> tree2;
  tree2.iterativeAppend(2);
  tree2.iterativeAppend(4);
  tree2.iterativeAppend(6);
  tree2.iterativeAppend(3);
  tree2.iterativeAppend(1);
  tree2.iterativeAppend(0);
  tree2.iterativeAppend(5);
  BinarySearchTree<int> tree3; 
  tree3.iterativeAppend(3);
  tree3.iterativeAppend(1);
  tree3.iterativeAppend(0);
  tree.iterativeSearchInWidth();
  std::cout << "\n Used prefix search: \n";
  std::vector<int> vec = tree.iterativePrefixSearch();
  for (size_t i = 0; i < vec.size(); ++i)
  {
    std::cout << vec[i] << ' ';
  }
  std::cout << '\n';
  std::cout << "Are the two trees same? first and second: \n";
  std::cout << std::boolalpha << areSame(tree, tree2) << '\n';
  std::cout << "First and third: \n";
  std::cout << std::boolalpha << areSame(tree, tree3) << '\n';
  return 0;
}