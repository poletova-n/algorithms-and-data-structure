#include <iostream>
#include <cmath>
#include "stackarray.hpp"
#include "operator.hpp"

bool isDigit(const char& t);
std::string translate(const std::string& exp, bool n);
std::string infToPost(const std::string &exp);
int calculation(const std::string& text);
bool testBalanceBrackets(const std::string& exp, int maxDeep);

int main()
{
  try
  {
    std::string test1 = "(5+1)";
    std::cout << "Test1: " << test1 << " = " << infToPost(test1) << " = "
              << calculation(translate(test1, 1)) << "\n";
    std::string test2 = "9-4+(2*3)";
    std::cout << "Test2: " << test2 << " = " << infToPost(test2) << " = "
              << calculation(translate(test2, 1)) << "\n";
    std::string test3 = "3/3-4*2+8";
    std::cout << "Test3: " << test3 << " = " << infToPost(test3) << " = "
              << calculation(translate(test3, 1)) << "\n";
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

std::string infToPost(const std::string &exp)
{
  if (!testBalanceBrackets(exp, 30))
    throw std::logic_error("Not balanced");
  return translate(exp, 0);
}

std::string translate(const std::string &exp, bool n)
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
        if (n == 0)
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
        if (n == 0)
          stack.push(exp[i]);
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

bool testBalanceBrackets(const std::string &exp, int maxDeep)
{
  Stack<char>* stack = new StackArray<char>(maxDeep);
  bool isBalanceBrackets = true;
  try
  {
    char cText = '\0';
    for (int i = 0; ((cText = exp[i]) != '\0') && (isBalanceBrackets == true); i++)
    {
      switch (cText)
      {
        case '(':
          stack->push(cText);
          break;
        case ')':
          if (stack->pop() != '(')
          {
            isBalanceBrackets = false;
          }
          break;
      }
    }
    isBalanceBrackets = isBalanceBrackets && stack->isEmpty();
  }
  catch (StackUnderflow)
  {
    isBalanceBrackets = false;
  }
  catch (StackOverflow)
  {
    isBalanceBrackets = false;
  }
  delete stack;
  return isBalanceBrackets;
}
