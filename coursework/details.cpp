#include "details.h"

#include <string>

const char* myExceptions::ErrorSyntax::what() const
{
  return reason_.c_str();
}
const char* myExceptions::EmptyDictionary::what() const
{
  return reason_;
}
const char* myExceptions::NoWordFound::what() const
{
  return reason_;
}

bool isKey(std::string key)
{
  size_t length = key.length();
  if (length != 2)
  {
    return 0;
  }
  for (size_t i = 0; i < key.length(); i++)
  {
    if (key[i] < 65 || key[i]>122 || (key[i] > 90 && key[i] < 97))
    {
      return 0;
    }
  }
  return 1;
}

bool isWord(std::string word)
{
  for (size_t i = 0; i < word.length(); i++)
  {
    if (word[i] < 65 || word[i]>122 || (word[i] > 90 && word[i] < 97))
    {
      return 0;
    }
  }
  return 1;
}

void strlwrWord(std::string& word)
{
  size_t length = word.length();
  for (size_t i = 0; i < length; i++)
  {
    if (word[i] > 64 && word[i] < 91)
    {
      word[i] += 32;
    }
  }
}

int compareKey(std::string key1, std::string key2)
{
  strlwrWord(key1);
  strlwrWord(key2);
  if (key1[0] == key2[0])
  {
    if (key1[1] > key2[1])
    {
      return 1;
    }
    else
    {
      if (key1[1] < key2[1])
      {
        return -1;
      }
      else
      {
        return 0;
      }
    }
  }
  else
  {
    if (key1[0] > key2[0])
    {
      return 1;
    }
    else
    {
      return -1;
    }
  }
}
