#include <iostream>
#include <limits>
#include "BinarySearchTree.hpp"

int main()
{
  std::cout << "This program is working with tree of type 'int'.\n"
            << "Please, write your numbers. If you want to stop, just print something else into the stream.\n";
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

  std::cout << "Your tree is:\n";
  tree.print();

  std::cout << '\n' << "The size of tree: " << tree.size() << '\n'
            << "The height of tree: " << tree.height() << '\n';

  std::cout << "If you want remove some number in this tree, just write it.\n"
            << "Printing something else into the stream - discard.\n"
            << "If your number won't be found program will throw the exception. Be careful!\n";
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
  catch (std::invalid_argument& exc)
  {
    std::cerr << exc.what();
  }

  std::cout << "Your new tree is:\n";
  tree.print();

  std::cout << "Write value that you want to find:\n";
  int findValue;
  std::cin >> findValue;

  std::cout << (tree.find(findValue) ? "Value was found.\n" : "Value was not found.\n");

  return 0;
}