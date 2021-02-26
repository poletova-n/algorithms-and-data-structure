#include <iostream>
#include <string>
#include "stackarray.hpp"
#include "stacklist.hpp"

bool isBalanced (std::string& string, bool byList);

int main()
{
  std::string test;
  std::cout << "Please, input the test sentence with parentheses:\n";
  std::cin >> test;
  std::cout << "\nPlease, choose the method of check (1 - by Stack Array, 2 - "
               "by Stack List):\n";
  size_t check = 0;
  std::cin >> check;
  if (check == 1)
  {
    std::cout << (isBalanced(test, true) ? "Yes" : "No");
  }
  else if (check == 2)
  {
    std::cout << (isBalanced(test, false) ? "Yes" : "No");
  }
  return 0;
}

bool isBalanced (std::string& string, bool byList)
{
  if (!byList)
  {
    StackArray<char> bracketsArray(string.length());
    size_t i = 0;
    while (string[i] != '\0')
    {
      switch (string[i])
      {
      case '(':
      {
        bracketsArray.push('(');
        break;
      }
      case ')':
      {
        if (bracketsArray.isEmpty() || bracketsArray.pop() != '(')
        {
          return false;
        }
        break;
      }
      case '[':
      {
        bracketsArray.push('[');
        break;
      }
      case ']':
      {
        if (bracketsArray.isEmpty() || bracketsArray.pop() != '[')
        {
          return false;
        }
        break;
      }
      case '{':
      {
        bracketsArray.push('{');
        break;
      }
      case '}':
      {
        if (bracketsArray.isEmpty() || bracketsArray.pop() != '{')
        {
          return false;
        }
        break;
      }
      }
      ++i;
    }
    if (bracketsArray.isEmpty())
    {
      return true;
    }
    else
    {
      return false;
    }
  }
  else
  {
    StackList<char> bracketsList;
    size_t i = 0;
    while(string[i] != '\0')
    {
      switch (string[i])
      {
      case '(':
      {
        bracketsList.push('(');
        break;
      }
      case ')':
      {
        if (bracketsList.isEmpty() || bracketsList.pop() != '(')
        {
          return false;
        }
        break;
      }
      case '[':
      {
        bracketsList.push('[');
        break;
      }
      case ']':
      {
        if (bracketsList.isEmpty() || bracketsList.pop() != '[')
        {
          return false;
        }
        break;
      }
      case '{':
      {
        bracketsList.push('{');
        break;
      }
      case '}':
      {
        if (bracketsList.isEmpty() || bracketsList.pop() != '{')
        {
          return false;
        }
        break;
      }
      }
      ++i;
    }
    if (bracketsList.isEmpty())
    {
      return true;
    }
    else
    {
      return false;
    }
  }
}