#include <iostream>
#include <string>
#include "exception.hpp"
#include "Stack.hpp"
#include "StackArray.hpp"
#include "Operator.hpp"

std::string translationInfixExpressionToPostfix(const std::string& text);
int calculatePostfixForm(const std::string& text);
void checkString(const std::string& text);

int main()
{
  try
  {
    std::string text1 = "(7 + 1) * 4";
    std::cout << translationInfixExpressionToPostfix(text1) << " --> " << calculatePostfixForm(translationInfixExpressionToPostfix(text1)) << '\n';
    std::string text2 = "(3 + 5) * ((1 + 2) - 4)";
    std::cout << translationInfixExpressionToPostfix(text2) << " --> " << calculatePostfixForm(translationInfixExpressionToPostfix(text2)) << '\n';
    std::string text3 = "((5 + 5) * 4) / 1";
    std::cout << translationInfixExpressionToPostfix(text3) << " --> " << calculatePostfixForm(translationInfixExpressionToPostfix(text3)) << '\n';
    std::string text4 = "((3 + 9) * 3) / (2 + 10)";
    std::cout << translationInfixExpressionToPostfix(text4) << " --> " << calculatePostfixForm(translationInfixExpressionToPostfix(text4)) << '\n';
    std::string text5 = "((3 + 2) * 4) * (2 - 1)";
    std::cout << translationInfixExpressionToPostfix(text5) << " --> " << calculatePostfixForm(translationInfixExpressionToPostfix(text5)) << '\n';
    std::string text6 = "((3 + 1) * 3) + ((3 + 1) + (7 - 1))";
    std::cout << translationInfixExpressionToPostfix(text6) << " --> " << calculatePostfixForm(translationInfixExpressionToPostfix(text6)) << '\n';
  }
  catch(const std::invalid_argument &error)
  {
    std::cout << error.what() << '\n';
  }
  catch(const std::logic_error &error)
  {
    std::cout << error.what() << '\n';
  }
  return 0;
}

std::string translationInfixExpressionToPostfix(const std::string& text)
{
  StackArray<char> stack(text.size());
  std::string newExpression = "";
  checkString(text);

  for (int i = 0; i < text.size(); ++i)
  {
    if (text[i] == ' ')
    {
      continue;
    }
    if (text[i] >= '0' && text[i] <= '9')
    {
      newExpression += text[i];
      continue;
    }
    else
    {
      if (text[i] == ')')
      {
        while (stack.top() != '(')
        {
          newExpression += stack.pop();
        }
        if (stack.top() == '(')
        {
          stack.pop();
        }
        continue;
      }
      else if (Operator(text[i]).getPriority() != -1)
      {
        stack.push(text[i]);
      }
    }
  }
  while (!(stack.isEmpty()))
  {
    newExpression += stack.pop();
  }
  return newExpression;
}

int calculatePostfixForm(const std::string& text)
{
  StackArray<int> stack(text.size());
  int valueOne = 0;
  int valueTwo = 0;
  int result = 0;

  for (int i = 0; i < text.size(); ++i)
  {
    if (text[i] >= '0' && text[i] <= '9')
    {
      stack.push(text[i] - '0');
    }
    else
    {
      valueTwo = stack.pop();
      valueOne = stack.pop();
      switch (text[i])
      {
        case '+':
          result = valueOne + valueTwo;
          break;
        case '-':
          result = valueOne - valueTwo;
          break;
        case '/':
          if (valueTwo == 0)
          {
            throw std::logic_error("Can't be divided by 0.");
          }
          result = valueOne / valueTwo;
          break;
        case '*':
          result = valueOne * valueTwo;
          break;

        default:
          break;
      }
      stack.push(result);
    }
  }
  return stack.pop();
}

void checkString(const std::string& text)
{
  for (int i = 0; i < text.size(); ++i)
  {
    if (!(text[i] >= '0' && text[i] <= '9')
        && text[i] != '(' && text[i] != ')'
        && text[i] != ' ' && text[i] != '^'
        && text[i] != '-' && text[i] != '+'
        && text[i] != '*' && text[i] != '/')
    {
      throw std::invalid_argument("Invalid string specified.");
    }
  }
}