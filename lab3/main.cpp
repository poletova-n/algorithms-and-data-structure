#include <iostream>
#include <string>

#include "stack.h"
#include "stackArray.h"
#include "stackOverflow.h"
#include "stackUnderflow.h"
#include "wrongStackSize.h"

bool checkBalanceBrackets(const std::string& text, int maxDeep = 30);
bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize = 30);
int evaluatePostfix(const std::string& infix, size_t stackSize = 30);

int main()
{
  setlocale(LC_ALL, "ru");
  std::cout << "Check balance brackets: \n";
  std::string str = "()";
  std::cout << str << ": " << (checkBalanceBrackets(str) ? "right" : "wrong") << "\n";
  str = "{}(())";
  std::cout << str << ": " << (checkBalanceBrackets(str) ? "right" : "wrong") << "\n";
  str = "{()}({[()]})";
  std::cout << str << ": " << (checkBalanceBrackets(str) ? "right" : "wrong") << "\n";
  str = "{(({}))}";
  std::cout << str << ": " << (checkBalanceBrackets(str) ? "right" : "wrong") << "\n";
  str = "((())";
  std::cout << str << ": " << (checkBalanceBrackets(str) ? "right" : "wrong") << "\n";
  str = "(((({{{))))}}}";
  std::cout << str << ": " << (checkBalanceBrackets(str) ? "right" : "wrong") << "\n";
  str = "({})(()){}";
  std::cout << str << ": " << (checkBalanceBrackets(str) ? "right" : "wrong") << "\n";
  str = "{{})()";
  std::cout << str << ": " << (checkBalanceBrackets(str) ? "right" : "wrong") << "\n";
  str = "(()()()()[]{})[]";
  std::cout << str << ": " << (checkBalanceBrackets(str) ? "right" : "wrong") << "\n";
  str = "((((((";
try
{
  std::cout << checkBalanceBrackets(str, 5);
}
catch (const StackOverflow& error)
{
  std::cout << str << ": " << error.what() << "\n";
}


  std::string a = "(2*4*(5+3/6)+9)*7";
  std::string b;
  getPostfixFromInfix(a, b, 30);
  std::cout << a << "\n";
  std::cout << b << "\n" << "\n";
  a = "24/";
  std::cout << a << "\n" << evaluatePostfix(a, 30);

}

bool checkBalanceBrackets(const std::string& text, int maxDeep)
{
  StackArray<char> test(maxDeep);
  for (size_t i = 0; i < text.size(); i++)
  {

    if ((text[i] == '(') || (text[i] == '{') || (text[i] == '['))
    {
      test.push(text[i]);
    }
    if (text[i] == ')')
    {
      if (test.top() == '(')
      {
        test.pop();
      }
      else
      {
        return false;
      }
    }
    if (text[i] == '}')
    {
      if (test.top() == '{')
      {
        test.pop();
      }
      else
      {
        return false;
      }
    }
    if (text[i] == ']')
    {
      if (test.top() == '[')
      {
        test.pop();
      }
      else
      {
        return false;
      }
    }
  }
  if (test.isEmpty())
  {
    return true;
  }
  return false;
}

bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize)
{
  StackArray<char> test(stackSize);
  checkBalanceBrackets(infix);
  for (size_t i = 0; i < infix.size(); i++)
  {
    if (infix[i] == '(')
    {
      test.push(infix[i]);
    }
    else if (infix[i] == ')')
    {
      while (test.top() != '(')
      {
        postfix.push_back(test.pop());
      }
      test.pop();
    }
    else if ((infix[i] >= '0') && (infix[i] <= '9'))
    {
      postfix.push_back(infix[i]);
    }
    else if (((infix[i] == '+') || (infix[i] == '*') || (infix[i] == '/') || (infix[i] == '-')) && (test.isEmpty())||(test.top()=='('))
    {
      test.push(infix[i]);
    }
    else if (((infix[i] == '*') || (infix[i] == '/')) && ((test.top() == '*') || (test.top() == '/')))
    {
      postfix.push_back(test.pop());
      test.push(infix[i]);
    }
    else if (((infix[i] == '*') || (infix[i] == '/')) && ((test.top() == '+') || (test.top() == '-')))
    {
      test.push(infix[i]);
    }

    else if ((infix[i] == '+') || (infix[i] == '-'))
    {
      while ((test.isEmpty() == 0)&&(test.top()!='('))
      {
        postfix.push_back(test.pop());
      }
      test.push(infix[i]);
    }
  }
  while (test.isEmpty() == 0)
  {
    postfix.push_back(test.pop());
  }
  return 1;
}

int evaluatePostfix(const std::string& infix, size_t stackSize)
{
  int result = 0;
  int tempOne = 0;
  int tempTwo = 0;
  StackArray<int> test(stackSize);
  for (size_t i = 0; i < infix.size(); i++)
  {
    if ((infix[i] >= '0') && (infix[i] <= '9'))
    {
      test.push(infix[i] - '0');
    }
    else if (infix[i] == '+')
    {
      tempOne = test.pop();
      tempTwo = test.pop();
      result = tempOne + tempTwo;
      test.push(result);
    }
    else if (infix[i] == '-')
    {
      tempTwo = test.pop();
      tempOne = test.pop();
      result = tempOne - tempTwo;
      test.push(result);
    }
    else if (infix[i] == '*')
    {
      tempOne = test.pop();
      tempTwo = test.pop();
      result = tempOne * tempTwo;
      test.push(result);
    }
    else if (infix[i] == '/')
    {
      tempTwo = test.pop();
      tempOne = test.pop();
      result = tempOne / tempTwo;
      test.push(result);
    }
  }
  result = test.pop();
  return result;
}


