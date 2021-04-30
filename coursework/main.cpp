#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "AvlTree.h"

std::string deleteSymbols(std::string& word)
{
  int i = 0;
  while (word.size() && i < word.size())
  {
    if ((word[i] < 65 || word[i] > 122) && (word[i] > 90 || word[i] < 97))
    {
      word.erase(i, 1);
    }
    else
    {
      i++;
    }
  }
  return word;
}

int main()
{
  AvlTree dictionary;
  std::ifstream fin;
  fin.open("article");
  if (fin.fail())
  {
    std::cout << "Input file opening failed.\n";
    exit(1);
  }
  if (fin.peek() == EOF)
  {
    std::cout << "Input file is empty.\n";
    exit(1);
  }
  std::string word;
  int total = 0;
  while (!fin.eof())
  {
    fin >> word;
    if (!word.size())
    {
      continue;
    }
    deleteSymbols(word);
    if (!word.size())
    {
      continue;
    }
    for (unsigned int i = 0; i < word.size(); i++)
    {
      word[i] = tolower(word[i]);
    }
    dictionary.insert(word);
    total++;
  }
  fin.close();

  std::cout << "\tText 1" << std::endl;
  std::cout << "Is tree balanced?  " << (dictionary.isBalanced() ? "YES\n" : "NO\n") << std::endl;
  dictionary.inorderWalk(std::cout);
  std::cout << std::endl;
  std::cout << "Total number of words: " << total << "\n";
  std::cout << "Total unique words in text: " << dictionary.getCount();
  std::cout << "\n\n3 most common words in text:\n";
  try
  {
    dictionary.printMostCommonWords(std::cout);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
  }


  AvlTree dictionary2;
  std::ifstream fin2;
  fin2.open("article");
  if (fin2.fail())
  {
    std::cout << "Input file opening failed.\n";
    exit(1);
  }
  if (fin2.peek() == EOF)
  {
    std::cout << "Input file is empty.\n";
    exit(1);
  }
  std::string word2;
  int total2 = 0;
  while (!fin2.eof())
  {
    fin2 >> word2;
    if (!word2.size())
    {
      continue;
    }
    deleteSymbols(word2);
    if (!word2.size())
    {
      continue;
    }
    for (unsigned int i = 0; i < word2.size(); i++)
    {
      word2[i] = tolower(word2[i]);
    }
    dictionary2.insert(word2);
    total2++;
  }
  fin2.close();

  std::cout << "\tText 2" << std::endl;
  std::cout << "Is tree balanced?  " << (dictionary2.isBalanced() ? "YES\n" : "NO\n") << std::endl;
  dictionary2.inorderWalk(std::cout);
  std::cout << std::endl;
  std::cout << "Total number of words: " << total2 << "\n";
  std::cout << "Total unique words in text: " << dictionary2.getCount();
  std::cout << "\n\n3 most common words in text:\n";
  try
  {
    dictionary2.printMostCommonWords(std::cout);
  }
  catch (const std::exception& e)
  {
    std::cerr << e.what();
  }
  return 0;
}
