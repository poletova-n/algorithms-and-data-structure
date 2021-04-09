#include <iostream>
#include <string>
#include <fstream>

#include "BinarySearchTree.hpp"

void makeClearWord(std::string& string);

int main()
{
  BinarySearchTree<std::string> tree;

  std::cout << "If you want to break the input just write the code word '/end/'.\n";
  while (true)
  {
    std::string input;
    std::cin >> input;

    if (input == "/end/")
    {
      break;
    }

    makeClearWord(input);

    if (input.empty())
    {
      continue;
    }

    tree.add(input);
  }

  tree.mostUsed();

  return 0;
}

void makeClearWord(std::string& string)
{
  for (size_t i = 0; i < string.length(); ++i)
  {
    if (!(string[i] >= -128 && string[i] <= -80 || string[i] >= -32 && string[i] <= -8
      || string[i] >= 'A' && string[i] <= 'Z' || string[i] >= 'a' && string[i] <= 'z'))
    {
      string.erase(i--, 1);
    }
  }
}
