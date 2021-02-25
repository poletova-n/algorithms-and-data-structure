#include <iostream>
#include <string>

#include "stackarray.h"
#include "stacklist.h"

bool areParenthesisesValid(const std::string& string, bool useList);

bool areArrayParenthesisesValid(const std::string& string);

bool areListParenthesisesValid(const std::string& string);

int main() {
  // testing for Array Stack :
  StackArray<int> arr(3); 
  arr.push(1);
  arr.push(2);
  arr.push(3);
  std::cout << arr;
  for (int j = 0; j < 3; j++) 
  {
    arr.pop();
  }
  try 
  {
    arr.push(4);
  }
  catch (std::exception& e)
  {
    std::cout << e.what();
    return 1;
  }

  StackList<int> list;
  list.push(3);
  list.push(4);
  std::cout << list.pop() << "\n";
  std::cout << list.pop() << "\n";
  list.push(10);
  std::cout << list.pop() << "\n";
  std::cout << "\nparenthesises check: \n";
  //
  std::string text00 = " ok ";
  std::cout << text00 << ": " << (areParenthesisesValid(text00, false) ? "right" : "wrong") << '\n';

  std::string text01 = "( ) ok ";
  std::cout << text01 << ": " << (areParenthesisesValid(text01, false) ? "right" : "wrong") << '\n';

  std::string text02 = "( ( [] ) ) ok ";
  std::cout << text02 << ": " << (areParenthesisesValid(text02, true) ? "right" : "wrong") << '\n';

  std::string text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) OK";
  std::cout << text03 << ": " << (areParenthesisesValid(text03, false) ? "right" : "wrong") << '\n';

  std::string text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
  std::cout << text04 << ": " << (areParenthesisesValid(text04, true) ? "right" : "wrong") << '\n';

  std::string text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
  std::cout << text05 << ": " << (areParenthesisesValid(text05, false) ? "right" : "wrong") << '\n';

  std::string text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
  std::cout << text06 << ": " << (areParenthesisesValid(text06, true) ? "right" : "wrong") << '\n';
  
  return 0;
}

bool areParenthesisesValid(const std::string& string, bool useList)
{
  if (!useList) 
  {
    return areArrayParenthesisesValid(string);
  }
  else
  {
    return areListParenthesisesValid(string);
  }
}

bool areArrayParenthesisesValid(const std::string& string)
{
  int roundCount = 0, squareCount = 0, curlyCount = 0;
  StackArray<char> temp(string.size());
  for (size_t i = 0; i < string.size(); i++)
  {
    if (string[i] == '(')
    {
      roundCount++;
      temp.push(string[i]);
    }
    else if (string[i] == '[') {
      squareCount++;
      temp.push(string[i]);
    } 
    else if (string[i] == '{')
    {
      curlyCount++;
      temp.push(string[i]);
    }
    else if (string[i] == ')')
    {
      if (temp.top() != '(')
      {
        return false;
      }
      else if (roundCount <= 0)
      {
        return false;
      }
      else
      {
        temp.pop();
        roundCount--;
      }
    }
    else if (string[i] == ']')
    {
      if (temp.top() != '[')
      {
        return false;
      }
      else if (squareCount <= 0)
      {
        return false;
      }
      else
      {
        temp.pop();
        squareCount--;
      }
    }
    else if (string[i] == '}')
    {
      if (temp.top() != '{')
      {
        return false;
      }
      else if (curlyCount <= 0)
      {
        return false;
      }
      else
      {
        temp.pop();
        curlyCount--;
      }
    }
  }

  if (roundCount != 0 || squareCount != 0 || curlyCount != 0)
  {
    return false;
  }

  return true;
}

bool areListParenthesisesValid(const std::string& string)
{
  int roundCount = 0, squareCount = 0, curlyCount = 0;
  StackList<char> temp;
  for (size_t i = 0; i < string.size(); i++)
  {
    if (string[i] == '(')
    {
      roundCount++;
      temp.push(string[i]);
    }
    else if (string[i] == '[') {
      squareCount++;
      temp.push(string[i]);
    }
    else if (string[i] == '{')
    {
      curlyCount++;
      temp.push(string[i]);
    }
    else if (string[i] == ')')
    {
      if (!temp.isEmpty() && temp.top() != '(')
      {
        return false;
      }
      else if (roundCount <= 0)
      {
        return false;
      }
      else
      {
        temp.pop();
        roundCount--;
      }
    }
    else if (string[i] == ']')
    {
      if (!temp.isEmpty() && temp.top() != '[')
      {
        return false;
      }
      else if (squareCount <= 0)
      {
        return false;
      }
      else
      {
        temp.pop();
        squareCount--;
      }
    }
    else if (string[i] == '}')
    {
      if (!temp.isEmpty() && temp.top() != '{')
      {
        return false;
      }
      else if (curlyCount <= 0)
      {
        return false;
      }
      else
      {
        temp.pop();
        curlyCount--;
      }
    }
  }

  if (roundCount != 0 || squareCount != 0 || curlyCount != 0)
  {
    return false;
  }

  return true;
}