#include <iostream>

#include "BinarySeacrhTree.h"

int main()
{
  int TreeKeys[14] = { 50, 67, 45, 3, 98, 56 , 46 ,74, 48, 59, 39, 4, 12,8};
  BinarySearchTree <int> myTree;
  std::cout << "Printing the tree in order\nBefore adding numbers";
  myTree.PrintInOrder();
  for (int i = 0; i < 14; i++)
  {
    myTree.AddLeaf(TreeKeys[i]);
  }
  std::cout << "\nPrinting the tree in order\nAfter adding numbers\n";
  myTree.PrintInOrder();

  std::cout<<"\n\nNodes number - "<< myTree.getCount();
  std::cout << "\nHeight of the tree - " << myTree.getHeight() << std::endl;

  int TreeKeys2[9] = { 45,30,27,55,18,58,48,59,67 };
  BinarySearchTree <int> myTree2;
  for (int i = 0; i < 9; i++)
  {
    myTree2.AddLeaf(TreeKeys2[i]);
  }
  std::cout << "\nSecond tree\nNodes number - " << myTree2.getCount();
  std::cout << "\nHeight of the tree - " << myTree2.getHeight() << "\n";

  std::cout << "\nSuccessor: " << myTree.GetSuccessor(50)->key_ << "\n";
  std::cout << "Successor: " << myTree.GetSuccessor(98)->key_ << "\n\n";

  myTree.printInfo(1);
  myTree.printInfo(3);

  myTree.PrintChildren(myTree.ReturnRootKey());

  std::cout << "\nThe smallest value in the tree is " << myTree.FindSmallest() << std::endl;

  myTree.RemoveNode(50);
  std::cout << "Printing the tree in order\nAfter deleting node\n";
  myTree.PrintInOrder();
  std::cout << std::endl;
  myTree.RemoveNode(56);
  std::cout << "Printing the tree in order\nAfter deleting node\n";
  myTree.PrintInOrder();
  std::cout << std::endl;
  myTree.RemoveNode(9);
  std::cout << "\nPrinting the tree in order\nAfter deleting node\n";
  myTree.PrintInOrder();
  std::cout << std::endl;
  myTree.RemoveNode(45);
  std::cout << "\nPrinting the tree in order\nAfter deleting node\n";
  myTree.PrintInOrder();

  int keyFound = myTree.iterativeSearch(3); 
  std::cout << "\n\nKey " << 3 << (keyFound ? " found successfully" : " not found") << " in the tree" << std::endl;
  keyFound = myTree.iterativeSearch(23);
  std::cout << "Key " << 23 << (keyFound ? " found successfully" : " not found") << " in the tree" << std::endl;

 
  return 0;
}
