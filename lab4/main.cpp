#include <iostream>
#include <limits>
#include "BinarySearchTree.hpp"

int main()
{
  std::cout << "Write down your tree.\nTo stop type any word.\n";
  BinarySearchTree<int> tree;

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
    tree.addIterative(input);
  }

  std::cout << "Your tree:\n";
  tree.print();

  std::cout << '\n' << "Size of tree: " << tree.size() << '\n'
            << "Height of tree: " << tree.height() << '\n';

  std::cout << "Removal: WRITE DOWN number you want to remove\n\n";

  std::cin.clear();
  try
  {
    while (true)
    {
      int removableValue = 0;
      std::cin >> removableValue;
      if (std::cin.fail())
      {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
      }
      tree.remove(removableValue);
    }
  }
  catch (std::invalid_argument& exception)
  {
    std::cerr << exception.what();
  }

  std::cout << "Your new tree is:\n";
  tree.print();

  std::cout << "-----------------------------Search methods-----------------------------\n";
  std::cout << "Write value that you want to find:\n";
  int findValue;
  std::cin >> findValue;
  if (tree.find(findValue))
  {
    std::cout << "Value '" << findValue << "' was found.\n";
  }
  else
  {
    std::cout << "Value '" << findValue << "' was not found.\n";
  }

  return 0;
}
