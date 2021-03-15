#include <cmath>
#include <stack>
#include <string>
#include <iostream>
#include "operator.hpp"

bool isRight(std::string& expression);

void toPostfix(std::string& expression);

int getPostfixValue(std::string& expression);

bool isPrioritySign(char symbol);

int main()
{
  std::cout << "Please, enter the math expression that you want to test.\n";
  std::string expression;
  std::getline(std::cin, expression);
  if (isRight(expression))
  {
    toPostfix(expression);
    std::cout << "Postfix form of this expression = " << expression << '\n';
    int value = getPostfixValue(expression);
    std::cout << "Value of expression = " << value;
  }
  else
  {
    std::cout << "Expression is not right. Please, fix it and try again.";
  }
  return 0;
}

bool isRight(std::string& expression)
{
  int parentheses = 0;
  for (char symbol : expression)
  {
    if (!(symbol <= '9' && symbol >= '0' || symbol == '+' || symbol == '-' || symbol == '('
      || symbol == ')' || symbol == '*' || symbol == '/' || symbol == '^' || symbol == ' '))
    {
      return false;
    }
    if (symbol == '(')
    {
      ++parentheses;
    }
    else if (symbol == ')')
    {
      --parentheses;
      if (parentheses < 0)
      {
        return false;
      }
    }
  }
  if (parentheses > 0)
  {
    return false;
  }
  return true;
}

void toPostfix(std::string& expression)
{
  std::string translation;
  for (char symbol : expression)
  {
    if (symbol == ' ') { continue; }
    translation += symbol;
  }
  int countBrackets = 0;
  bool flagBracket = false;
  for (size_t i = 0; i < translation.length(); ++i)
  {
    if (isPrioritySign(translation[i + 2]))
    {
      translation.insert(i + 1, "(");
      i += 1;
      continue;
    }
    if (isPrioritySign(translation[i]) && (translation[i + 1] == '('))
    {
      ++countBrackets;
      flagBracket = true;
    }
    else if (isPrioritySign(translation[i]))
    {
      translation.insert(i + 2, ")");
      i += 2;
      continue;
    }
    if ((translation[i] == '(') && flagBracket)
    {
      ++countBrackets;
    }
    else if (translation[i] == ')' && flagBracket)
    {
      --countBrackets;
      if (countBrackets == 0)
      {
        flagBracket = false;
        translation.insert(i, ")");
      }
    }
  }
  std::stack<char> stack;
  std::string result;
  for (char symbol : translation)
  {
    if (symbol == ' ') { continue; }
    if (symbol >= '0' && symbol <= '9')
    {
      result += symbol;
      result += ' ';
    }
    else if (symbol == '(' || stack.empty() || stack.top() == '(')
    {
      stack.push(symbol);
    }
    else if (symbol == ')')
    {
      while (stack.top() != '(')
      {
        result += stack.top();
        result += ' ';
        stack.pop();
      }
      stack.pop();
    }
    else
    {
      if (stack.top() != '(' && stack.top() != ')')
      {
        result += stack.top();
        result += ' ';
      }
      stack.pop();
      stack.push(symbol);
    }
  }
  while (!stack.empty())
  {
    if (stack.top() != '(' && stack.top() != ')')
    {
      result += stack.top();
      result += ' ';
    }
    stack.pop();
  }
  expression = result;
}

int getPostfixValue(std::string& expression)
{
  std::stack<int> stack;
  for (char symbol : expression)
  {
    if (symbol >= '0' && symbol <= '9')
    {
      int number = 0;
      number = symbol - '0';
      stack.push(number);
      continue;
    }
    if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' || symbol == '^')
    {
      int operand2 = stack.top();
      stack.pop();
      int operand1 = stack.top();
      stack.pop();
      switch (symbol)
      {
      case '+':
        stack.push(operand1 + operand2);
        break;
      case '-':
        stack.push(operand1 - operand2);
        break;
      case '*':
        stack.push(operand1 * operand2);
        break;
      case '/':
        if (operand2 == 0)
        {
          std::cerr << "Not allowed dividing by zero.\n";
          exit(2);
        }
        stack.push(operand1 / operand2);
        break;
      case '^':
        if (operand1 == 0 && operand2 == 0)
        {
          std::cerr << "Uncertainty expression (0 raising to the power 0).\n";
          exit(2);
        }
        stack.push(std::pow(operand1, operand2));
      }
    }
  }
  return stack.top();
}

bool isPrioritySign(char symbol)
{
  if (symbol == '*' || symbol == '/' || symbol == '^')
  {
    return true;
  }
  return false;
}
