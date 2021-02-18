#include <iostream>
#include "stackarray.hpp"
#include "stacklist.hpp"

bool isBalancedBrackets(std::string originStr, bool isArrayWay = false);

bool balanceByArray(std::string originStr);

bool balanceByList(std::string originStr);

int countLeftBrackets(std::string originStr);

int countRightBrackets(std::string originStr);

int main()
{
  std::string text01 = "( ) ok ";
  std::cout << text01 << ": " << (isBalancedBrackets(text01) ? "right" : "wrong") << std::endl;
  std::string text02 = "( ( [] ) ) ok ";
  std::cout << text02 << ": " << (isBalancedBrackets(text02) ? "right" : "wrong") << std::endl;
  std::string text03 = "( ( ( { { [ ] } } ) ) ) OK";
  std::cout << text03 << ": " << (isBalancedBrackets(text03) ? "right" : "wrong") << std::endl;
  std::string text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
  std::cout << text04 << ": " << (isBalancedBrackets(text04) ? "right" : "wrong") << std::endl;
  std::string text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
  std::cout << text05 << ": " << (isBalancedBrackets(text05) ? "right" : "wrong") << std::endl;
  std::string text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
  std::cout << text06 << ": " << (isBalancedBrackets(text06) ? "right" : "wrong") << std::endl;
}

bool isBalancedBrackets(std::string originStr, bool isArrayWay)
{
  if (isArrayWay)
  {
    return balanceByArray(originStr);
  }
  else
  {
    return balanceByList(originStr);
  }
}

bool balanceByArray(std::string originStr)
{
  int leftCount = countLeftBrackets(originStr);
  int rightCount = countRightBrackets(originStr);
  StackArray<char> leftBrackets(leftCount);
  StackArray<char> tempRightBrackets(rightCount);
  for (int i = 0; i < originStr.length(); i++)
  {
    if (originStr[i] == '(' || originStr[i] == '[' || originStr[i] == '{')
    {
      leftBrackets.push(originStr[i]);
    }

    if (originStr[i] == ')' || originStr[i] == ']' || originStr[i] == '}')
    {
      tempRightBrackets.push(originStr[i]);
    }
  }
  char left, right;
  StackList<char> rightBrackets;
  while (!tempRightBrackets.isEmpty())
  {
    rightBrackets.push(tempRightBrackets.pop());
  }

  while (!leftBrackets.isEmpty() && !rightBrackets.isEmpty())
  {
    left = leftBrackets.pop();
    right = rightBrackets.pop();
    if ((left == '(' && right != ')') || (left == '[' && right != ']') || (left == '{' && right != '}'))
    {
      return false;
    }
  }
  if (leftBrackets.isEmpty() && rightBrackets.isEmpty())
  {
    return true;
  }
  else
  {
    return false;
  }
}

bool balanceByList(std::string originStr)
{
  StackList<char> leftBrackets;
  StackList<char> tempRightBrackets;
  for (int i = 0; i < originStr.length(); i++)
  {
    if (originStr[i] == '(' || originStr[i] == '[' || originStr[i] == '{')
    {
      leftBrackets.push(originStr[i]);
    }

    if (originStr[i] == ')' || originStr[i] == ']' || originStr[i] == '}')
    {
      tempRightBrackets.push(originStr[i]);
    }
  }
  char left, right;
  StackList<char> rightBrackets;
  while (!tempRightBrackets.isEmpty())
  {
    rightBrackets.push(tempRightBrackets.pop());
  }

  while (!leftBrackets.isEmpty() && !rightBrackets.isEmpty())
  {
    left = leftBrackets.pop();
    right = rightBrackets.pop();
    if ((left == '(' && right != ')') || (left == '[' && right != ']') || (left == '{' && right != '}'))
    {
      return false;
    }
  }
  if (leftBrackets.isEmpty() && rightBrackets.isEmpty())
  {
    return true;
  }
  else
  {
    return false;
  }
}

int countLeftBrackets(std::string originStr)
{
  int count = 0;
  for (int i = 0; i < originStr.length(); i++)
  {
    if (originStr[i] == '(' || originStr[i] == '[' || originStr[i] == '{')
    {
      count++;
    }
  }
  return count;
}

int countRightBrackets(std::string originStr)
{
  int count = 0;
  for (int i = 0; i < originStr.length(); i++)
  {
    if (originStr[i] == ')' || originStr[i] == ']' || originStr[i] == '}')
    {
      count++;
    }
  }
  return count;
}
