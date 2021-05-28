#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <fstream>
#include <stdexcept>

#include "data_structures/tree.h"

void help();
void checkEnglish(std::string &word);
//void checkRussian(std::string& word);

template<class T>
void add(Tree<T> &dictionary);

template<class T>
void translate(Tree<T> &dictionary);

template<class T>
void deleteWord(Tree<T> &dictionary);

template<class T>
void all(Tree<T> &dictionary);

template<class T>
void exit(Tree<T> &dictionary);

template<class T>
void add(Tree<T> &dictionary)
{
  try
  {
    std::string english;
    std::string russian;
    std::cin >> english;
    checkEnglish(english);
    List<std::string> translations;
    while (std::cin.peek() != '\n')
    {
      std::cin >> russian;
      //checkRussian(russian);
      translations += russian;
    }
    if (russian.empty())
    {
      throw std::logic_error("Not input russian word");
    }
    dictionary.insert(english, translations);
    std::cout << "Word successfully added\n\n";
  }
  catch (std::logic_error &error)
  {
    std::cin.ignore(1000, '\n');
    std::cerr << error.what() << "\n";
    return;
  }
}

template<class T>
void translate(Tree<T> &dictionary)
{
  try
  {
    std::string temp;
    std::cin >> temp;
    checkEnglish(temp);
    dictionary.search(temp);
  }
  catch (std::logic_error &error)
  {
    std::cin.ignore(1000, '\n');
    std::cerr << error.what() << "\n";
    return;
  }
}

template<class T>
void deleteWord(Tree<T> &dictionary)
{
  std::string temp;
  std::cin >> temp;
  checkEnglish(temp);
  dictionary.deleteNode(temp);
}

template<class T>
void all(Tree<T> &dictionary)
{
  dictionary.output(std::cout);
}

template<class T>
void exit(Tree<T> &dictionary)
{
  std::ofstream file("dictionary.txt");
  dictionary.output(file);
}

#endif