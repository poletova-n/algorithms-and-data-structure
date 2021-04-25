#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

#include "AVLTree.h"
#include "list.h"
#include "tests.h"

int main()
{
  double selection{};
  while (true)
  {
    system("cls");
    std::cout << "================== Program ========================\n";
    std::cout << "1 - AVL tree test correct or not?\n";
    std::cout << "2 - Experiment with the insert function.\n";
    std::cout << "3 - Test the program with the search function.\n";
    std::cout << "4 - Test with deleteKey function.\n";
    std::cout << "0 - End of test program and See the results of the built-in dictionary of prefixes from available text.\n";
    std::cout << "******************* END ************************\n";
    std::cout << "Please select options in the test program: ";
    std::cin >> selection;
    if (std::cin.fail())
    {
      char warningSound = 7;
      std::cout << warningSound;
      std::cout << "Please re-enter.\n";
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      system("pause");
    }
    else
    {
      if (selection == 0)
      {
        break;
      }
      else
      {
        if (selection == 1)
        {
          testAVLTree();
          system("pause");
        }
        else
        {
          if (selection == 2)
          {
            testInsert();
            system("pause");
          }
          else
          {
            if (selection == 3)
            {
              testSearch();
              system("pause");
            }
            else
            {
              if (selection == 4)
              {
                testDeleteKey();
                system("pause");
              }
              else
              {
                char warningSound = 7;
                std::cout << warningSound;
                std::cout << "Please re-enter.\n";
                system("pause");
              }
            }
          }
        }
      }
    }
	}
  system("cls");
  std::cout << "The program takes the words from the text and builds into an AVL tree: \n\n";
  std::ifstream file;
  file.open("input.txt");
  if (file.fail())
  {
    char warningSound = 7;
    std::cout << warningSound;
    std::cout << "The file cannot be opened.\n";
    return 0;
  }
  AVLTree dictionary;
  while (!file.eof())
  {
    std::string temp;
    std::getline(file, temp);
    size_t index{};
    size_t length = temp.size();
    bool breakWhile = false;
    while (!breakWhile)
    {
      bool breakFor = false;
      std::string word;
      for (size_t i = index; i < length && breakFor == false;)
      {
        if (i == length - 1)
        {
          breakWhile = true;
        }
        if ((temp[i] > 64 && temp[i] < 91) || (temp[i] > 96 && temp[i] < 123))
        {
          word.push_back(temp[i]);
          i++;
        }
        else
        {
          breakFor = true;
          index = i + 1;
        }
      }
      if (word.size() >= 2)
      {
        strlwrWord(word);
        std::string keyWord = word.substr(0, 2);
        dictionary.insert(keyWord, word);
      }
    }
  }
  file.close();
  std::cout << "The number of keywords added to the tree is: " << dictionary.getCount() << '\n';
  std::cout << "\nThe complete AVL tree(tree browsed left-right-parent): \n";
  dictionary.printTree(std::cout);

  return 0;
}
