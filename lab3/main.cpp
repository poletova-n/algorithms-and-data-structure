#include <iostream>
#include "Stack.h"
#include "StackArray.h"

// Проверка баланса скобок
bool checkBalanceBrackets(const std::string& str, int maxDeep = 30)
{
  StackArray<char> stack(maxDeep);
  char sym = str.at(0);
  for (int i = 0; i < str.size(); i++)
  {
    sym = str.at(i);
    if (sym == '(' || sym == '[' || sym == '{')
    {
      if (stack.isFull() == true)
      {
        throw "The nesting depth of the brackets is greater than the maximum";
      }
      else
      {
        stack.push(sym);
      }
    }
    else if (sym == ')')
    {
      char bracket = '\0';
      do
      {
        if (stack.isEmpty() == 0)
          bracket = stack.pop();
        else
          return false;
        if (bracket == '{' || bracket == '[')
          return false;
      } while (bracket != '(');
    }
    else if (sym == ']')
    {
      char bracket = '\0';
      do
      {
        if (stack.isEmpty() == 0)
          bracket = stack.pop();
        else
          return false;
        if (bracket == '{' || bracket == '(')
          return false;
      } while (bracket != '[');
    }
    else if (sym == '}')
    {
      char bracket = '\0';
      do
      {
        if (stack.isEmpty() == 0)
          bracket = stack.pop();
        else
          return false;
        if (bracket == '(' || bracket == '[')
          return false;
      } while (bracket != '{');
    }
  }
  return stack.isEmpty();
}

void testCheckBalanceBrackets()
{
  std::string text00 = " ok ";
  std::cout << text00 << ": " << (checkBalanceBrackets(text00) ? "right" : "wrong") << std::endl;
  std::string text01 = "( ) ok ";
  std::cout << text01 << ": " << (checkBalanceBrackets(text01) ? "right" : "wrong") << std::endl;
  std::string text02 = "( ( [] ) ) ok ";
  std::cout << text02 << ": " << (checkBalanceBrackets(text02) ? "right" : "wrong") << std::endl;
  std::string text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) OK";
  std::cout << text03 << ": " << (checkBalanceBrackets(text03) ? "right" : "wrong") << std::endl;
  std::string text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
  std::cout << text04 << ": " << (checkBalanceBrackets(text04) ? "right" : "wrong") << std::endl;
  std::string text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
  std::cout << text05 << ": " << (checkBalanceBrackets(text05) ? "right" : "wrong") << std::endl;
  std::string text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
  std::cout << text06 << ": " << (checkBalanceBrackets(text06) ? "right" : "wrong") << std::endl;
}

// Получение постфиксной формы
bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize = 30)
{
  postfix = "";
  if (checkBalanceBrackets(infix) == 0)
    throw "Error in the postfix expression";
  StackArray<char> stack(stackSize);
  char sym = infix.at(0);
  for (int i = 0; i < infix.size(); i++)
  {
    sym = infix.at(i);
    if (sym >= '0' && sym <= '9')
    {
      postfix += sym;
    }
    else
    {
      if (stack.isEmpty() == 1 || sym == '(')
      {
        stack.push(sym);
      }
      else if (sym == ')')
      {
        char stackSym = '\0';
        while (stackSym != '(')
        {
          stackSym = stack.pop();
          if (stackSym != '(')
          {
            postfix += stackSym;
          }
        }
      }
      else
      {
        if (sym == '+' || sym == '-')
        {
          char stackSym = stack.getTop();
          while (stackSym == '+' || stackSym == '-' || stackSym == '*' || stackSym == '/')
          {
            postfix += stack.pop();
            stackSym = stack.getTop();
          }
        }
        else if (sym == '*' || sym == '/')
        {
          char stackSym = stack.getTop();
          while (stackSym == '*' || stackSym == '/')
          {
            postfix += stack.pop();
            stackSym = stack.getTop();
          }
        }
        stack.push(sym);
      }
    }
  }
  while (stack.isEmpty() == 0)
  {
    postfix += stack.pop();
  }
  return true;
}

// Вычисление выражения в постфиксной форме
double evaluatePostfix(const std::string& postfix, size_t stackSize = 30)
{
  try
  {
    double num1 = 0.0, num2 = 0.0;
    StackArray<double> stack(stackSize);
    char sym = postfix.at(0);
    for (int i = 0; i < postfix.size(); i++)
    {
      sym = postfix.at(i);
      if (sym >= '0' && sym <= '9')
      {
        stack.push(double(sym - '0'));
      }
      else
      {
        num1 = stack.pop();
        num2 = stack.pop();
        if (sym == '+')
          stack.push(num2 + num1);
        else if (sym == '-')
          stack.push(num2 - num1);
        else if (sym == '*')
          stack.push(num2 * num1);
        else if (sym == '/')
        {
          if (num1 == 0.0)
          {
            throw "Zero division error.\n";
          }
          stack.push(num2 / num1);
        }
      }
    }
    return stack.pop();
  }
  catch (const char* err)
  {
    throw;
  }
  catch (...)
  {
    throw "Error in the postfix expression";
  }
}

int main()
{
  try
  {
    // Раскомментировать для демонстрации работы исключений
    /*// StackUnderflow test
    StackArray<char> stackTest(2);
    stackTest.pop();
    */
    /*// StackOverflow test
    StackArray<char> stackTest(2);
    stackTest.push(1); stackTest.push(1); stackTest.push(1);
    */
    /*// WrongStackSize test
    StackArray<char> stackTest(-2);
    */
    /*// Проверка работы контроля максимального уровня вложенности скобок
    checkBalanceBrackets("([{}])", 2);
    */

    std::string infix;
    std::string postfix;

    infix = "(1+2)*(3+4)-5"; // 16
    getPostfixFromInfix(infix, postfix);
    std::cout << infix << " = " << postfix << " = " << evaluatePostfix(postfix) << "\n";

    infix = "((1+9)*(3+4)-5)-9*3"; // 38
    getPostfixFromInfix(infix, postfix);
    std::cout << infix << " = " << postfix << " = " << evaluatePostfix(postfix) << "\n";

    infix = "((1+9)*(3+4)-5)*9-3"; // 582
    getPostfixFromInfix(infix, postfix);
    std::cout << infix << " = " << postfix << " = " << evaluatePostfix(postfix) << "\n";

    infix = "(1-9)*(7*3+5)/((5+5)-(1*9))"; // -208
    getPostfixFromInfix(infix, postfix);
    std::cout << infix << " = " << postfix << " = " << evaluatePostfix(postfix) << "\n";

    infix = "((2-1)*(7+9)/(3/2))+8"; // 18.(6)
    getPostfixFromInfix(infix, postfix);
    std::cout << infix << " = " << postfix << " = " << evaluatePostfix(postfix) << "\n";

    infix = "((2-1)*(7+9)/(3/0))+8"; // Zero division error
    getPostfixFromInfix(infix, postfix);
    std::cout << infix << " = " << postfix << " = " << evaluatePostfix(postfix) << "\n";

    infix = "((1+9)*(3+4)-5"; // Error, для демонстрации работы закомментировать предыдущий блок
    getPostfixFromInfix(infix, postfix);
    std::cout << infix << " = " << postfix << " = " << evaluatePostfix(postfix) << "\n";
  }
  catch (Stack<char>::StackException& e)
  {
    std::cerr << e.getMessage();
  }
  catch (const char* errMsg)
  {
    std::cerr << errMsg;
  }
  return 0;
}
