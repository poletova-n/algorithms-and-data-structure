#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

#include "algorithms.h"

const int NUMBER_OF_TESTS = 4;

const std::string inputOne[NUMBER_OF_TESTS]{ "ABRACADABRA", "TAGTCAC", "PALINDROME", "STARDUST" };
const std::string inputTwo[NUMBER_OF_TESTS]{ "ABRAHAM", "GT","DROME", "ARD" };

int main()
{
  try
  {
    while (true)
    {
      std::cout << "1 - Demonstration of the algorithms with example inputs\n"
        << "2 - Demonstration of the algorithms with manually entered data\n"
        << "3 - Exit\n";

      int choice;
      std::cin >> choice;
      if (!std::cin)
      {
        throw std::invalid_argument("Invalid type of input in choice\n");
      }

      if (choice == 1)
      {
        for (int i = 0; i < NUMBER_OF_TESTS; i++)
        {
          std::cout << "\nLCS for \"" << inputOne[i] << "\" and \"" << inputTwo[i] << "\" - \n";
          std::cout << "\tNeedleman-Wunsch - " << std::setw(2) << NeedlemanWunsch(inputOne[i], inputTwo[i]) << "\n";
          std::cout << "\tHirschberg - " << std::setw(2) << Hirschberg(inputOne[i], inputTwo[i]) << "\n";
          std::cout << "\n";
        }
      }
      else if (choice == 2)
      {
        std::string firstString, secondString;

        std::cout << "\nEnter the first string - ";
        std::cin >> firstString;

        std::cout << "\nEnter the second string - ";
        std::cin >> secondString;

        std::cout << "\nLCS for \"" << firstString << "\" and \"" << secondString << "\" - \n";
        std::cout << "\tNeedleman-Wunsch - " << std::setw(2) << NeedlemanWunsch(firstString, secondString) << "\n";
        std::cout << "\tHirschberg - " << std::setw(2) << Hirschberg(firstString, secondString) << "\n";
        std::cout << "\n";
      }
      else if (choice == 3)
      {
        return 0;
      }
      else
      {
        throw std::invalid_argument("Invalid choice selection\n");
      }
    }

    return 0;
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << std::endl;
  }
}
