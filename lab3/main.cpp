#include "stackArray.h"
#include "operator.h"

#include <iostream>

std::string infIntoPost(std::string &src);
bool testBalanceBrackets(std::string str, int maxDeep);

int main()
{
  std::string str1 = "5 * 7 + 7 / 2";
  std::string str2 = "4 * 5 * 7 + 7 / 2";
  std::string str3 = "8 / 2 * (9 + 1)";
  std::string str4 = "6 - 3 + 5 * 2";
  std::cout << "Expression in infix form: " << str1 << "\n" << "Expression in postfix form: " <<infIntoPost(str1) << "\n\n";
  std::cout << "Expression in infix form: " << str2 << "\n" << "Expression in postfix form: " <<infIntoPost(str2) << "\n\n";
  std::cout << "Expression in infix form: " << str3 << "\n" << "Expression in postfix form: " <<infIntoPost(str3) << "\n\n";
  std::cout << "Expression in infix form: " << str4 << "\n" << "Expression in postfix form: " <<infIntoPost(str4) << "\n\n";
  return 0;
}

std::string infIntoPost(std::string &src)
{
  if (!testBalanceBrackets(src, 30)) {
    std::string error = "Brackets in this expression are incorrect";
    return error;
  }
  std::string str = "";
  StackArray<char> stack;
  for (int i = 0; i < src.length(); i++) {
    switch (src[i]) {
      case '(':
        stack.push(src[i]);
        break;
      case '0': case '1': case '2': case '3': case '4': case '5': case '6': case '7': case '8': case '9':
        str += src[i];
        break;
      case '*': case '-': case '+': case'/': case '^':
        for (int j = stack.getTop(); j > 0; j--) {
          if (stack.getElement(j) == '(') {
            break;
          }
          else {
            Operator operat(src[i]);
            Operator temp(stack.getElement(j));
            if (operat.getPriority()<=temp.getPriority()) {
              str += stack.getElement(j);
              stack.pop();
            }
          }
        }
        stack.push(src[i]);
        break;
      case ')':
        for (int j = stack.getTop(); j > 0; j--) {
          if (stack.getElement(j) != '(') {
            str += stack.getElement(j);
            stack.pop();
          }
          if (stack.getElement(j) == '(')
            stack.pop();
        }
        break;
    }
  }
  if (!stack.isEmpty())
    for (int i = stack.getTop(); i > 0; i--) {
      str+=stack.getElement(i);
    }
  return str;
}

bool testBalanceBrackets(std::string str, int maxDeep)
{
  Stack<char>* stack = new StackArray<char>(maxDeep);
  bool isBalanceBrackets = true;
  try
  {
    char cText = '\0';
    for (int i = 0; ((cText = str[i]) != '\0') && (isBalanceBrackets == true); i++)
    {
      switch (cText)
      {
        case '(': case '[': case '{':
          stack->push(cText);
          break;
        case ')':
          if (stack->pop() != '(')
          {
            isBalanceBrackets = false;
          }
          break;
        case ']':
          if (stack->pop() != '[')
          {
            isBalanceBrackets = false;
          }
          break;
        case '}':
          if (stack->pop() != '{')
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
