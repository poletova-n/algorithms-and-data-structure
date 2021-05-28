#include "functions.h"

#include <iostream>
#include <stdexcept>

void help()
{
  std::cout << "List of commands\n\n"
            << "add - add new word\n"
            << "add <english word> <list of russian words>\n\n"
            << "translate - find translations of word\n"
            << "translate <english word>\n\n"
            << "delete - delete word\n"
            << "delete <english word>\n\n"
            << "all - print all words of translations\n\n"
            << "exit - stop program and write words to file\n\n";
}

void checkEnglish(std::string &word)
{
  for (size_t i = 0; i < word.size(); i++)
  {
    if (word[i] < 97 || word[i] > 122)
    {
      if (word[i] >= 65 && word[i] <= 90)
      {
        word[i] = word[i] - 32;
      }
      else
      {
        throw std::logic_error("Incorrect input of english word");
      }
    }
  }
}

/*void checkRussian(std::string& word)
{
  for (size_t i = 0; i < word.size(); i++)
  {
    if (word[i] < 224 || word[i] > 255)
    {
      if (word[i] >= 192 && word[i] <= 223)
      {
        word[i] = word[i] - 32;
      }
      else
      {
        throw std::logic_error("Incorrect input of russian word");
      }
    }
}*/