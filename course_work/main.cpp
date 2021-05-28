#include <iostream>
#include <string>
#include <stdexcept>

#include "data_structures/tree.h"
#include "functions.h"

int main()
{
  try
  {
    Tree<std::string> dictionary;
    std::string command;
    std::cout << "Enter help to get list of commands\n";
    while (command != "exit")
    {
      std::cout << "Enter command: ";
      std::cin >> command;
      if (command == "help")
      {
        help();
      }
      else if (command == "add")
      {
        add(dictionary);
      }
      else if (command == "translate")
      {
        translate(dictionary);
      }
      else if (command == "delete")
      {
        deleteWord(dictionary);
      }
      else if (command == "all")
      {
        all(dictionary);
      }
      else if (command == "exit")
      {
        exit(dictionary);
      }
      else
      {
        std::cin.ignore(1000, '\n');
        std::cout << "Undefined command\n";
        std::cout << "Enter help to get list of commands\n\n";
      }
    }
  }
  catch (std::runtime_error &error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
  catch (std::logic_error &error)
  {
    std::cerr << error.what() << "\n";
    return 1;
  }
  return 0;
}
