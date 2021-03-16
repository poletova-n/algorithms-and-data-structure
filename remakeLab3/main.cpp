#include <iostream>
#include <cmath>
#include <string>

#include "operator.hpp"
#include "StackArray.hpp"

bool checkingParentheses (const std::string& string);
std::string getPostfixForm(const std::string& expression, int maxDepth);
std::string evaluatePostfix(const std::string& evexpr, int maxDepth);

int main() {
  std::string firstExpression("(3+1)*2");
  try
  {
    std::cout << getPostfixForm(firstExpression, 30);
  }
  catch (const std::invalid_argument& e)
  {
    std::cout << e.what();
    return 1;
  }
  catch (const std::logic_error& e)
  {
    std::cout << e.what();
    return 1;
  }
  std::cout << '\n' << evaluatePostfix(getPostfixForm(firstExpression, 30), 30);

  std::string secondExpression("(1+3)-5");
  try
  {
    std::cout << '\n' << getPostfixForm(secondExpression, 30);
  }
  catch (const std::invalid_argument& e)
  {
    std::cout << e.what();
    return 1;
  }
  std::cout << '\n' << evaluatePostfix(getPostfixForm(secondExpression, 30), 30);
  return 0;
}

bool checkingParentheses (const std::string& string)
{
  int roundCount = 0;
  StackArray<char> temp(string.size());
  for (size_t i = 0; i < string.size(); i++)
  {
    if (string[i] == '(')
    {
      roundCount++;
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
  }

  if (roundCount != 0)
  {
    return false;
  }

  return true;
}

std::string getPostfixForm(const std::string& expression, int maxDepth)
{
  StackArray<Operator> arr(maxDepth);
  std::string newExpression = "";
  if (!checkingParentheses (expression))
  {
    throw std::logic_error("Parenthesises failure");
  }
  for (size_t i = 0; i < expression.size(); i++)
  {
    if (expression[i] - '0' < 0
        && expression[i] - '0' > 9
        && expression[i] != '+'
        && expression[i] != '-'
        && expression[i] != '/'
        && expression[i] != '*'
        && expression[i] != '^'
        && expression[i] != '('
        && expression[i] != ')'
        && expression[i] != ' ')
    {
      throw std::invalid_argument("unidentified operand");
    }
    if (expression[i] == ' ')
    {
      continue;
    }
    if (expression[i] - '0' >= 0 && expression[i] - '0' <= 9)
    {
      newExpression += expression[i];
      continue;
    }
    if (arr.getPos() == 0)
    {
      arr.push(Operator(expression[i]));
      continue;
    }
    else
    {
      if (expression[i] == '(')
      {
        arr.push(Operator(expression[i]));
        continue;
      }
      if (expression[i] == ')')
      {
        while (arr.top().getOperand() != '(')
        {
          newExpression += arr.pop().getOperand();
        }
        arr.pop();
        continue;
      }
      while (arr.top().getPriority() >= Operator(expression[i]).getPriority())
      {
        newExpression += arr.pop().getOperand();
      }
      arr.push(Operator(expression[i]));
      continue;
    }
  }
  while (arr.getPos() != 0)
  {
    newExpression += arr.pop().getOperand();
  }
  return newExpression;
}

std::string evaluatePostfix(const std::string& evexpr, int maxDepth)
{
  StackArray<std::string> stack(maxDepth);
  std::string num;
  for (size_t i = 0; i < evexpr.size(); i++)
  {
    if (evexpr[i] - '0' >= 0 && evexpr[i] - '0' <= 9)
    {
      std::string temp = "";
      temp += evexpr[i];
      stack.push(temp);
      temp = "";
      continue;
    }
    if (evexpr[i] == '+'
        || evexpr[i] == '-'
        || evexpr[i] == '*'
        || evexpr[i] == '/'
        || evexpr[i] == '^')
    {
      int secondOperand = strtoul(stack.pop().c_str(), nullptr, 10);
      int firstOperand = strtoul(stack.pop().c_str(), nullptr, 10);
      int result = 0;
      switch (evexpr[i])
      {
        case '+':
          result = firstOperand + secondOperand;
          break;
        case '-':
          result = firstOperand - secondOperand;
          break;
        case '*':
          result = firstOperand * secondOperand;
          break;
        case '/':
          if (secondOperand == 0)
          {
            throw std::invalid_argument("Division by zero");
          }
          result = firstOperand / secondOperand;
          break;
        case '^':
          result = static_cast<int>(pow(firstOperand, secondOperand));
          break;
        default:
          break;
      }
      stack.push(std::to_string(result));
    }
  }
  return stack.pop();
}