#include <iostream>
#include <limits>
#include "binarysearchtree.hpp"

int main()
{
  std::cout << "This program is working with trees of type 'int'.\n"
            << "Please, write your numbers into the first tree.\n"
            << "If you want to stop, just print something else into the stream.\n";
  BinarySearchTree<int> firstTree;
  while (true)
  {
    int input;
    std::cin >> input;
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
    firstTree.addIterative(input);
  }

  std::cout << "Your first tree is:\n";
  firstTree.print();

  std::cout << "Width traversal of the first tree:\n";
  firstTree.widthTraversal();

  std::cout << '\n' << "Please, write your numbers into the second tree.\n"
            << "If you want to stop, just print something else into the stream.\n";
  BinarySearchTree<int> secondTree;
  while (true)
  {
    int input;
    std::cin >> input;
    if (std::cin.fail())
    {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      break;
    }
    secondTree.addIterative(input);
  }

  std::cout << "Your second tree is:\n";
  secondTree.print();

  std::cout << "Prefix traversal of the second tree:\n";
  secondTree.prefixTraversal();

  std::cout << "\n\n" << (firstTree.similar(secondTree) ? "Trees are the similar.\n" : "Trees aren't the similar.\n");

  return 0;
}