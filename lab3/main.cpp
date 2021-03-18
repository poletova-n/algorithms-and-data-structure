#include <iostream>
#include <string>
#include "stackArray.h"

int evaluatePostfix(std::string infix);
bool isOperator(const char& c);
int precedence(const char& c);
bool bracketsBalance(std::string infix);
std::string InfixToPostfix(StackArray <char> s, std::string infix);

int main()
{
  try 
  {
    std::string firstExpression = "(9 > 1)* (5 + 7) - 6"; 
    StackArray <char> stack;
    std::cout << InfixToPostfix(stack, firstExpression);
    std::cout << '\n' << evaluatePostfix(firstExpression);

    std::string secondExpression = "(9) > (2)  * (5) + (7) - (6)";
    std::cout << '\n' << InfixToPostfix(stack, secondExpression);
    std::cout << '\n' << evaluatePostfix(secondExpression);

    std::string thirdExpression = "(9^2)/((5) + (7))>(2)";
    std::cout << '\n' << InfixToPostfix(stack, thirdExpression);
    std::cout << '\n' << evaluatePostfix(thirdExpression);

    std::string lastExpression = "3*1+2/0";
    std::cout << '\n' << InfixToPostfix(stack, lastExpression);
    std::cout << '\n' << evaluatePostfix(lastExpression);

  }
  catch (...)
  {
    std::cout << "\nIncorrect expression!";
    return -1;
  }
  return 0;
}


int evaluatePostfix(std::string infix)
{
  int rVal = 0;
  int lVal = 0;
  int result = 0;
  StackArray <int> s;
  StackArray <char> ss;
  std::string postfix = InfixToPostfix(ss, infix);
  for (int i = 0; i < postfix.length(); i++)
  {
    if (isdigit(postfix[i]))
    {
      s.push((int)(postfix[i]-'0'));
    }
    else if (isOperator(postfix[i]))
    {
      if (postfix[i] == '+')
      {
        rVal = s.peek();
        s.pop();
        lVal = s.peek();
        s.pop();
        result = lVal + rVal;
        s.push(result);
      }
      else if (postfix[i] == '-')
      {
        rVal = s.peek();
        s.pop();
        lVal = s.peek();
        s.pop();
        result = lVal - rVal;
        s.push(result);
      }
      else if (postfix[i] == '*')
      {
        rVal = s.peek();
        s.pop();
        lVal = s.peek();
        s.pop();
        result = lVal * rVal;
        s.push(result);
      }
      else if (postfix[i] == '/')
      {
        rVal = s.peek();
        s.pop();
        lVal = s.peek();
        s.pop();
        if (rVal != 0)
        {
          result = lVal / rVal;
        }
        else
        {
          throw - 1;
        }
        s.push(result);
      }
      if (postfix[i] == '^')
      {
        rVal = s.peek();
        s.pop();
        lVal = s.peek();
        s.pop();
        result = pow(lVal,rVal);
        s.push(result);
      }
      if (postfix[i] == '>')
      {
        rVal = s.peek();
        s.pop();
        lVal = s.peek();
        s.pop();
        result = lVal >> rVal;
        s.push(result);
      }
    }
  }
  {
    result = s.peek();
    s.pop();
    if (!s.isEmpty())
    {
      throw - 1;
    }
    else
    {
      return result;
    }
  }
}

bool isOperator(const char& c)
{
  if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '>')
  {
    return true;
  }
  else
  {
    throw - 1;
  }
}

int precedence(const char& c)
{
  if (c == '^' || c == '>')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

bool bracketsBalance(std::string infix)
{
  Stack <char>* stack = new StackArray<char>;
  bool isBalanceBrackets = true;
  try {
    char cText = '\0';
    for (int i = 0; ((cText = infix[i]) != '\0') && (isBalanceBrackets == true); i++)
    {
      switch (cText) {
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


std::string InfixToPostfix(StackArray <char> s, std::string infix)
{
  if (bracketsBalance(infix) == false)
  {
    throw - 1;
  }
  std::string postfix;
  for (int i = 0; i < infix.length(); i++)
  {
    if (infix[i] == ' ')
    {
      continue;
    }
    else if (infix[i] >= '0' && infix[i] <= '9')
    {
      postfix += infix[i];
    }
    else if (infix[i] == '(')
    {
      s.push(infix[i]);
    }
    else if (infix[i] == ')')
    {
      while ((s.peek() != '(') && (!s.isEmpty()))
      {
        char temp = s.peek();
        postfix += temp;
        s.pop();
      }
      if (s.peek() == '(')
      {
        s.pop();
      }
    }
    else if (isOperator(infix[i]))
    {
      if (s.isEmpty())
      {
        s.push(infix[i]);
      }
      else
      {
        if (precedence(infix[i]) > precedence(s.peek()))
        {
          s.push(infix[i]);
        }
        else if ((precedence(infix[i]) == precedence(s.peek())) && (infix[i] == '^'))
        {
          s.push(infix[i]);
        }
        else
        {
          while ((!s.isEmpty()) && (precedence(infix[i]) <= precedence(s.peek())))
          {
            postfix += s.peek();
            s.pop();
          }
          s.push(infix[i]);
        }
      }
    }
    else
    {
      throw - 1;
    }
  }
  while (!s.isEmpty())
  {
    postfix += s.peek();
    s.pop();
  }
  return postfix;
}

