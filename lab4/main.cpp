#include <iostream>
#include "BinarySearchTree.h"

int main()
{
  BinarySearchTree<int> tree1;
  BinarySearchTree<int> tree2;

  tree1.insert(3); tree1.insert(-8); tree1.insert(15); tree1.insert(-10); tree1.insert(1);
  tree1.insert(10); tree1.insert(100); tree1.insert(2); tree1.insert(11); tree1.insert(115);

  tree2.insert(3); tree2.insert(1); tree2.insert(15); tree2.insert(-9); tree2.insert(2);
  tree2.insert(11); tree2.insert(100); tree2.insert(-10); tree2.insert(95); tree2.insert(115);
  
  std::cout << "tree1 : ";  tree1.print(std::cout);
  std::cout << "tree2 : ";  tree2.print(std::cout);

  tree1.deleteKey(-8); tree1.deleteKey(10);
  tree2.deleteKey(-9); tree2.deleteKey(95);

  std::cout << "tree1 : ";  tree1.print(std::cout);
  std::cout << "tree2 : ";  tree2.print(std::cout);

  std::cout << "tree1 height : " << tree1.getHeight() << "\n";
  std::cout << "tree1 inorderWalk : "; tree1.inorderWalk(); std::cout << "\n";
  std::cout << "tree2 iterativeInorderWalk : "; tree2.iterativeInorderWalk(); std::cout << "\n";
  
  std::cout << "tree1 == tree2 : " << bool(tree1 == tree2) << "\n";

  tree1.deleteKey(3);
  std::cout << "tree1 : ";  tree1.print(std::cout);

  return 0;
}
