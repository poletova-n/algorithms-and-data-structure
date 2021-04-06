#include <iostream>

#include "BinarySearchTree.h"

int main()
{
  try
  {
    BinarySearchTree<int> forest;  //Create empty tree
    forest.addIterative(100);  //Add elements iteratively and recursively 
    forest.addIterative(70);
    forest.addRecursive(150);
    forest.addRecursive(50);
    forest.addIterative(90);
    forest.addIterative(200);
    forest.addRecursive(10);
    forest.addRecursive(55);
    forest.addIterative(170);
    forest.addIterative(210);
    forest.addRecursive(40);
    forest.addRecursive(60);
    forest.addIterative(58);
    forest.addIterative(65);
    std::cout << "Number of nodes: " << forest.countNodes() << "\n\n";  //Determine the number of nodes
    std::cout << "Height: " << forest.getheight() << "\n\n";  //Determine the height of the tree
    for (int i = 1; i <= forest.countNodes(); i++)  //Print all elements
    {
      forest.printInfo(i, std::cout);
      std::cout << "\n";
    }
    forest.deleteNode(150);  //delete some elements
    forest.deleteNode(65);
    forest.deleteNode(55);
    std::cout << "\nDeleted: 150, 65, 55\n";
    for (int i = 1; i <= forest.countNodes(); i++)  //Print all elements after deletion
    {
      forest.printInfo(i, std::cout);
      std::cout << "\n";
    }
  }
  catch (std::exception& error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
  return 0;
}