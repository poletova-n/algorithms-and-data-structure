#include <iostream>
#include <exception>
#include <string>
#include "stackArray.h"

bool checkBalanceBrackets(const std::string& text, size_t maxDeep = 30);
bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize = 30);
int evaluatePostfix(const std::string& infix, size_t stackSize = 30);

void createBorder()
{
  int size = 50;
  for (int i = 0; i < size; i++)
  {
    std::cout << "_";
  }
    std::cout << std::endl;
}

bool testCheckBalanceBrackets()
{
  const std::string& text00 = " ok ";
  std::cout << text00 << ": " << (checkBalanceBrackets(text00) ? "right" : "wrong") << '\n';
  const std::string& text01 = "( ) ok ";
  std::cout << text01 << ": " << (checkBalanceBrackets(text01) ? "right" : "wrong") << '\n';
  const std::string& text02 = "( ( [] ) ) ok ";
  std::cout << text02 << ": " << (checkBalanceBrackets(text02) ? "right" : "wrong") << '\n';
  const std::string& text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) OK";
  std::cout << text03 << ": " << (checkBalanceBrackets(text03) ? "right" : "wrong") << '\n';
  const std::string& text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
  std::cout << text04 << ": " << (checkBalanceBrackets(text04) ? "right" : "wrong") << '\n';
  const std::string& text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
  std::cout << text05 << ": " << (checkBalanceBrackets(text05) ? "right" : "wrong") << '\n';
  const std::string& text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
  std::cout << text06 << ": " << (checkBalanceBrackets(text06) ? "right" : "wrong") << '\n';
  return true;
}

bool testInfixPostfixEvaluation(std::string infix)
{
  std::string postfix;
  std::cout << "Infix form: " << infix << '\n';
  if (getPostfixFromInfix(infix, postfix))
  {
    std::cout << "Postfix form: "
      << postfix << '\n' << "Result: "
      << evaluatePostfix(postfix) << '\n';
    return true;
  }
  return false;
}

int main()
{
  std::cout << "Test of Check Balance Brackets function\n";
  testCheckBalanceBrackets();
  createBorder();

  std::cout << "Test of stack functionality\n";
  try
  {
    StackArray <int> stack_test(-5);
  }
  catch (std::exception& ex)
  {
    std::cout << ex.what() << '\n';
  }
  StackArray <int> stack_test(5);
  stack_test.push(5);
  std::cout << "Push " << stack_test.top() << '\n';
  stack_test.push(-2);
  std::cout << "Push " << stack_test.top() << '\n';
  stack_test.push(7);
  std::cout << "Push " << stack_test.top() << '\n';
  stack_test.push(23);
  std::cout << "Push " << stack_test.top() << '\n';
  stack_test.push(9);
  std::cout << "Push " << stack_test.top() << '\n';
  try
  {
    stack_test.push(10);
    std::cout << "Push " << stack_test.top() << '\n';
  }
  catch (std::exception& ex)
  {
    std::cout << ex.what() << '\n';
  }
  std::cout << "Copy: \n";
  StackArray<int> stack_test2(stack_test);
  try
  {
    while (true)
    {
      std::cout << "Pop " << stack_test2.pop() << '\n';
    }
  }
  catch (std::exception& ex)
  {
    std::cout << ex.what() << '\n';
  }
  createBorder();

  std::cout << "Test of postfix notation\n";
  std::string infix1 = "((1+2)*(3+4))-5";
  testInfixPostfixEvaluation(infix1);

  std::string infix2 = "(7+2)/3+2-(7*(1-8)+5)";
  testInfixPostfixEvaluation(infix2);

  std::string infix3 = "(3+5)(";
  testInfixPostfixEvaluation(infix3);

  std::string infix4 = "(a+b-c)*2";
  testInfixPostfixEvaluation(infix4);

  try
  {
    std::string infix5 = "(3+9)*1/0";
    testInfixPostfixEvaluation(infix5);
  }
  catch (const char* error)
  {
    std::cout << error << '\n';
  }

  return 0;
}

bool isDigit(char symbol)
{
  if (symbol >= '0' && symbol <= '9') {
    return true;
  }
  return false;
}

bool isOperator(char symbol)
{
  if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/')
  {
    return true;
  }
  return false;
}

int getPriority(char symbol)
{
  if (symbol == '+' || symbol == '-')
  {
    return 1;
  }
  if (symbol == '*' || symbol == '/')
  {
    return 2;
  }
  return 0;
}

bool checkBalanceBrackets(const std::string& text, size_t maxDeep)
{
  StackArray<char> stack(maxDeep);
  char symbol = '\0';
  for (int i = 0; i < text.size(); i++)
  {
    symbol = text[i];
    if (symbol == '(' || symbol == '[' || symbol == '{')
    {
      stack.push(symbol);
      continue;
    }
    switch (symbol)
    {
    case ')':
      if (stack.isEmpty() || stack.pop() != '(')
      {
        return false;
      }
      break;
    case ']':
      if (stack.isEmpty() || stack.pop() != '[')
      {
        return false;
      }
      break;
    case '}':
      if (stack.isEmpty() || stack.pop() != '{')
      {
        return false;
      }
      break;
    }
  }
  return stack.isEmpty();
}

bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize)
{
  char symbol = '\0';
  if (!checkBalanceBrackets(infix))
  {
    std::cout << "Invalid parameters\n";
    return false;
  }
  for (int i = 0; i < infix.size(); i++)
  {
    symbol = infix[i];
    if (symbol != '(' && symbol != ')' && !isOperator(symbol) && !isDigit(symbol))
    {
      std::cout << "Invalid parameters\n";
      return false;
    }
  }
  StackArray<char> stack(stackSize);
  postfix = "";
  for (int i = 0; i < infix.size(); i++)
  {
    symbol = infix[i];
    if (isDigit(symbol))
    {
      postfix += symbol;
      continue;
    }
    else if (symbol == '(')
    {
      stack.push(symbol);
      continue;
    }
    else if (symbol == ')')
    {
      char top = stack.pop();
      while (top != '(')
      {
        postfix += top;
        top = stack.pop();
      }
      continue;
    }
    else if (!stack.isEmpty())
    {
      if (isOperator(symbol))
      {
        char top = stack.top();
        int symPriority = getPriority(symbol);
        while (getPriority(top) >= symPriority)
        {
          stack.pop();
          postfix += top;
          if (!stack.isEmpty())
          {
            top = stack.top();
          }
          else
          {
            break;
          }
        }
      }
    }
    stack.push(symbol);
  }
  while (!stack.isEmpty())
  {
    postfix += stack.pop();
  }
  if (postfix == "")
  {
    return false;
  }
  else
  {
    return true;
  }
}

int evaluatePostfix(const std::string& postfix, size_t stackSize)
{
  StackArray<char> stack(stackSize);
  char symbol = '\0';
  int num1 = 0, num2 = 0;
  for (int i = 0; i < postfix.size(); i++)
  {
    symbol = postfix[i];
    if (isDigit(symbol))
    {
      stack.push(symbol - '0');
      continue;
    }
    if (isOperator(symbol))
    {
      num2 = stack.pop();
      num1 = stack.pop();
      switch (symbol)
      {
      case '+':
        stack.push(num1 + num2);
        continue;
      case '-':
        stack.push(num1 - num2);
        continue;
      case '*':
        stack.push(num1 * num2);
        continue;
      case '/':
        if (num2 == 0)
        {
          throw "Division by zero";
        }
        stack.push(num1 / num2);
        continue;
      }
    }
  }
  return stack.pop();
}
