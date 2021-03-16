#include <iostream>
//#include <string>

#include "stackArray.h"
#include "operator.h"

bool checkBalanceBrackets(const std::string &text, Stack<char> *tempStack);
bool checkInvalidElement(const std::string &text);
void infixToPostfix(std::string &text, Stack<char> *stack);
bool checkInvalidExpression(const std::string &text);
int calculatePostfix(const std::string &text);

int main()
{
  try
  {
    std::string text1 = "5 * 7 + 7 / 2";
    std::string text2 = "4 * 5 + 7 + 7 / 2";
    std::string text3 = "8 / 2 * (9 + 1)";
    std::string text4 = "6 - 3 + 5 * 2";
    StackArray<char> stack(100);
    std::cout << "Infix expression: " << text1 << "\n";
    infixToPostfix(text1, &stack);
    std::cout << "Postfix expression: " << text1 << "\n";
    std::cout << "Result: " << calculatePostfix(text1) << "\n\n";
    std::cout << "Infix expression: " << text2 << "\n";
    infixToPostfix(text2, &stack);
    std::cout << "Postfix expression: " << text2 << "\n";
    std::cout << "Result: " << calculatePostfix(text2) << "\n\n";
    std::cout << "Infix expression: " << text3 << "\n";
    infixToPostfix(text3, &stack);
    std::cout << "Postfix expression: " << text3 << "\n";
    std::cout << "Result: " << calculatePostfix(text3) << "\n\n";
    std::cout << "Infix expression: " << text4 << "\n";
    infixToPostfix(text4, &stack);
    std::cout << "Postfix expression: " << text4 << "\n";
    std::cout << "Result: " << calculatePostfix(text4) << "\n\n";
  }
  catch (std::invalid_argument &exception)
  {
    std::cerr << exception.what();
  }
  return 0;
}

bool checkBalanceBrackets(const std::string &text, Stack<char> *tempStack)
{
  int tempCountOpenBrackets = 0;
  for (int i = 0; text[i] != '\0'; i++)
  {
    if ((text[i] == '(') || (text[i] == '{') || (text[i] == '[') || (text[i] == ')') || (text[i] == '}') ||
        (text[i] == ']'))
    {
      if ((text[i] == '(') || (text[i] == '{') || (text[i] == '['))
      {
        tempStack->push(text[i]);
        tempCountOpenBrackets += 1;
      }
      else
      {
        try
        {
          char temp = tempStack->pop();
          if ((temp == '[') && (text[i] != ']'))
          {
            return false;
          }
          if ((temp == '{') && (text[i] != '}'))
          {
            return false;
          }
          if ((temp == '(') && (text[i] != ')'))
          {
            return false;
          }
          tempCountOpenBrackets -= 1;
        }
        catch (StackUnderFlow)
        {
          return false;
        }
      }
    }
  }
  if (tempCountOpenBrackets != 0)
  {
    return false;
  }
  return true;
}

bool checkInvalidElement(const std::string &text)
{
  for (int i = 0; text[i] != '\0'; i++)
  {
    if ((text[i] == '(') || (text[i] == ')') || ((text[i] >= '0') && (text[i] <= '9')) || (text[i] == ' ') ||
        (text[i] == '*') || (text[i] == '+') || (text[i] == '-') || (text[i] == '/') || (text[i] == '^'))
    {}
    else
    {
      return false;
    }
  }
  return true;
}

bool checkInvalidExpression(const std::string &text)
{
  std::string tempText;
  for (int i = 0; text[i] != '\0'; i++)  //remove spaces from the original expression
  {
    if (text[i] != ' ')
    {
      tempText += text[i];
    }
  }
  for (int i = 0; tempText[i] != '\0'; i++)
  {
    if (tempText[i] == '(')  //checking the open bracket
    {
      if (i == 0)  //if the bracket is the first
      {
        if ((tempText[i + 1] <= '9') && (tempText[i + 1] >= '0'))
        {}
        else
        {
          return false;
        }
      }
      else  //if the bracket is not the first
      {
        if (((tempText[i + 1] <= '9') && (tempText[i + 1] >= '0')) && ((tempText[i - 1] == '+') ||
                                                                       (tempText[i - 1] == '-') ||
                                                                       (tempText[i - 1] == '*') ||
                                                                       (tempText[i - 1] == '/')))
        {
        }
        else
        {
          return false;
        }
      }
    }
    if (tempText[i] == ')')  //checking the close bracket
    {
      if (tempText[i + 1] == '\0')  //if the bracket is the last
      {
        if ((tempText[i - 1] <= '9') && (tempText[i - 1] >= '0'))
        {}
        else
        {
          return false;
        }
      }
      else  //if the bracket is not the last
      {
        if (((tempText[i - 1] <= '9') && (tempText[i - 1] >= '0')) &&
            ((tempText[i + 1] == '+') || (tempText[i + 1] == '-') || (tempText[i + 1] == '*') ||
             (tempText[i + 1] == '/')))
        {}
        else
        {
          return false;
        }
      }
    }
    if ((tempText[i] == '*') || (tempText[i] == '/') || (tempText[i] == '+') ||
        (tempText[i] == '-'))  //check the situation with the mathematical sign
    {
      if ((tempText[i - 1] >= '0') && (tempText[i - 1] <= '9') && (tempText[i + 1] >= '0') &&
          (tempText[i + 1] <= '9'))  //situation when the number is on the left, the number on the right
      {}
      else if ((tempText[i - 1] >= '0') && (tempText[i - 1] <= '9') &&
               (tempText[i + 1] == '('))  //situation when the digit is on the left, the open bracket on the right
      {}
      else if ((tempText[i + 1] >= '0') && (tempText[i + 1] <= '9') &&
               (tempText[i - 1] == ')'))  //situation when the digit is on the right, the close bracket on the left
      {}
      else if ((tempText[i - 1] == ')') && (tempText[i + 1] ==
                                            '('))  //situation when the open bracket is on the right, the close bracket on the left
      {}
      else
      {
        return false;
      }
    }
    if ((tempText[i] == '/') && (tempText[i + 1] == '0'))  //eliminate division by zero situation
    {
      throw std::invalid_argument("Attempt to divide by zero");
    }
    if (i == 0)  //the first character can be a open bracket or a number
    {
      if ((tempText[i] == '(') || ((tempText[i] >= '0') && (tempText[i] <= '9')))
      {}
      else
      {
        return false;
      }
    }
    if (tempText[i + 1] == '\0')  //the last character can be a close bracket or a number
    {
      if ((tempText[i] == ')') || ((tempText[i] >= '0') && (tempText[i] <= '9')))
      {}
      else
      {
        return false;
      }
    }
  }
}

void infixToPostfix(std::string &text, Stack<char> *stack)
{
  if (checkInvalidElement(text) && checkBalanceBrackets(text, stack) && checkInvalidExpression(text))
  {
    std::string tempString;
    Operator operation;
    for (int i = 0; text[i] != '\0'; i++)
    {
      if ((text[i] >= '0') && (text[i] <= '9'))  //add the number to the output string
      {
        tempString += text[i];
      }
      if ((text[i] == '+') || (text[i] == '-') || (text[i] == '*') || (text[i] == '/') ||
          (text[i] == '^'))  //processing operators
      {
        if (stack->isEmpty())
        {
          stack->push(text[i]);
        }
        else
        {
          Operator tempOperation;
          tempOperation.setOperation(stack->getTop());
          operation.setOperation(text[i]);
          while (operation.getPriority() <= tempOperation.getPriority() && (stack->isEmpty() == false))
          {
            tempString += stack->pop();
            if (stack->isEmpty() == false)
            {
              tempOperation.setOperation(stack->getTop());
            }
          }
          stack->push(operation.getOperation());
        }
      }
      if (text[i] == '(')  //add an open bracket to the stack
      {
        stack->push(text[i]);
      }
      if (text[i] == ')')  //having fun when the bracket is closed
      {
        while (stack->getTop() != '(')
        {
          tempString += stack->pop();
        }
        stack->deleteTop();
      }
    }
    while (stack->isEmpty() == false) //add to the output string everything that is left on the stack
    {
      tempString += stack->pop();
    }
    text = tempString;
  }
  else
  {
    throw std::invalid_argument("The expression was written incorrectly");
  }
}

int calculatePostfix(const std::string &text)
{
  StackArray<char> stack;
  for (int i = 0; text[i] != '\0'; i++)
  {
    stack.push(text[i]);
    if ((text[i] == '*') || (text[i] == '/') || (text[i] == '+') || (text[i] == '-'))
    {
      if (stack.getTop() == '*')
      {
        stack.deleteTop();
        int operand1 = stack.pop() - '0';
        int operand2 = stack.pop() - '0';
        int value = operand2 * operand1;
        stack.push(value + '0');
      }
      if (stack.getTop() == '/')
      {
        stack.deleteTop();
        int operand1 = stack.pop() - '0';
        int operand2 = stack.pop() - '0';
        int value = operand2 / operand1;
        stack.push(value + '0');
      }
      if (stack.getTop() == '-')
      {
        stack.deleteTop();
        int operand1 = stack.pop() - '0';
        int operand2 = stack.pop() - '0';
        int value = operand2 - operand1;
        stack.push(value + '0');
      }
      if (stack.getTop() == '+')
      {
        stack.deleteTop();
        int operand1 = stack.pop() - '0';
        int operand2 = stack.pop() - '0';
        int value = operand2 + operand1;
        stack.push(value + '0');
      }
    }
  }
  return stack.getTop() - '0';
}