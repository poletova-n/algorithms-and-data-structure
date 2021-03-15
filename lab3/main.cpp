#include <iostream>
#include <cmath>
#include "stackarray.hpp"
#include "operator.hpp"

bool isDigit(const char& t);
std::string translate(const std::string& exp);
int calculation(const std::string& text);

int main()
{
  try
  {
    std::string test1 = "5+1";
    std::cout << "Test1: " << test1 << " = " << translate(test1) << " = "
              << calculation(translate(test1)) << "\n";
    std::string test2 = "9-4+2*3";
    std::cout << "Test2: " << test2 << " = " << translate(test2) << " = "
              << calculation(translate(test2)) << "\n";
    std::string test3 = "3/3-4*2+8";
    std::cout << "Test3: " << test3 << " = " << translate(test3) << " = "
              << calculation(translate(test3)) << "\n";
  }
  catch(const std::logic_error &e)
  {
    std::cerr << e.what() << '\n';
  }
  return 0;
}

bool isDigit(const char& t)
{
  if (t >= '0' && t <= '9')
  {
    return true;
  }
  return false;
}

std::string translate(const std::string &exp)
{
  std::string result = "";
  StackArray<char> stack(exp.size());
  for (int i = 0; i < exp.size(); i++)
  {
    if (isDigit(exp[i]))
    {
      result += exp[i];
    }
    switch (exp[i])
    {
      case '+': case '-': case '/': case '*': case '^':
      {
        Object current(exp[i]);
        Object last(stack.getTop());
        if (stack.isEmpty() || stack.getTop() == '(')
        {
          stack.push(exp[i]);
        }
        else if (current.getPriority() > last.getPriority())
        {
          stack.push(exp[i]);
        }
        else if (current.getPriority() <= last.getPriority())
        {
          char temp = stack.getTop();
          while ((temp != '(' || Object(temp).getPriority() > Object(stack.getTop()).getPriority()) && !stack.isEmpty())
          {
            temp = stack.getTop();
            result += (stack.pop());
          }
          stack.push(exp[i]);
        }
        break;
      }
      case '(':
        stack.push(exp[i]);
        break;
      case ')':
      {
        char last = stack.getTop();
        while (last != '(' && !stack.isEmpty())
        {
          last = stack.getTop();
          result += (stack.pop());
        }
        break;
      }
    }
  }
  while (!stack.isEmpty())
  {
    result += (stack.pop());
  }
  return result;
}

int calculation(const std::string& exp)
{
  StackArray<int> stack(exp.size());
  int operator1 = 0;
  int operator2 = 0;
  int result = 0;
  for (int i = 0; i < exp.size(); i++)
  {
    if (isDigit(exp[i]))
    {
      stack.push(exp[i] - '0');
    }
    else
    {
      operator2 = stack.pop();
      operator1 = stack.pop();
      switch (exp[i])
      {
        case '+':
          result = operator1 + operator2;
          break;
        case '-':
          result = operator1 - operator2;
          break;
        case '/':
          if (operator2 == 0)
          {
            throw std::logic_error("divided by 0");
          }
          else
            result = operator1 / operator2;
          break;
        case '*':
          result = operator1 * operator2;
          break;
        case '^':
          result = pow(operator1, operator2);
          break;
      }
      stack.push(result);
    }
  }
  return stack.pop();
}
