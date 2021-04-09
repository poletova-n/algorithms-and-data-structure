#include <iostream>
#include "Tree.h"

using namespace std;

int main()
{
  Tree<int> tree;

  tree.insert(10);
  tree.insert(5);
  tree.insert(11);
  tree.insert(12);
  tree.insert(2);
  tree.insert(25);

  std::cout << "-----------------------------Binary Tree-----------------------------\n";
  std::cout << "Tree: \n";
  tree.print(std::cout);
  std::cout << "Tree count of nodes: " << tree.getCount() << '\n';
  std::cout << "Tree height: " << tree.getHeight() << '\n';
  std::cout << "-----------------------------Search methods-----------------------------\n";
  std::cout << (tree.iterativeSearch(10) ? "True\n" : "False\n");
  std::cout << (tree.iterativeSearch(4) ? "True\n" : "False\n");
  std::cout << tree.nextNode(11) << '\n';
  std::cout << "------------------------------------------------------------------------\n";
  tree.deleteKey(5);
  std::cout << (tree.iterativeSearch(5) ? "True\n" : "False\n");
  return 0;
}
