#include <cmath>
#include <iostream>
#include <stack>
#include <stdexcept>
#include "operator.hpp"

bool isDigit(char ch);
std::string translateToPostfix(const std::string& expression);
int evaluatePostfix(const std::string& expression);

int main()
{
  std::ios::sync_with_stdio(false);
  try {
    std::string expression = translateToPostfix("(3 + 2) * 4");
    std::cout << "Postfix form:" << expression << '\n'
              << "Result:";
    std::cout << evaluatePostfix(expression) << '\n';
  } catch (const std::invalid_argument& ex) {
    std::cerr << ex.what();
  }
  try {
    std::string expression2 = translateToPostfix("((3 + 2) * 4) / 2");
    std::cout << "Postfix form:" << expression2 << '\n'
              << "Result:";
    std::cout << evaluatePostfix(expression2) << '\n';
  } catch (const std::invalid_argument& ex) {
    std::cerr << ex.what();
  }
  try {
    std::string expression3 = translateToPostfix("(((3 + 2) * 4) / 2) - 1");
    std::cout << "Postfix form:" << expression3 << '\n'
              << "Result:";
    std::cout << evaluatePostfix(expression3) << '\n';
  } catch (const std::invalid_argument& ex) {
    std::cerr << ex.what();
  }
  try {
    std::string expression4 = translateToPostfix("((((3 + 2) * 4) / 2) - 1) ^ 2");
    std::cout << "Postfix form:" << expression4 << '\n'
              << "Result:";
    std::cout << evaluatePostfix(expression4) << '\n';
  } catch (const std::invalid_argument& ex) {
    std::cerr << ex.what();
  }
  try {
    std::string expression5 = translateToPostfix("(((((3 + 2) * 4) / 2) - 1) ^ 2) / 0");
    std::cout << "Postfix form:" << expression5 << '\n'
              << "Result:";
    std::cout << evaluatePostfix(expression5) << '\n';
  } catch (const std::invalid_argument& ex) {
    std::cerr << ex.what();
  }
  return 0;
}

bool isDigit(char ch)
{
  if (ch >= '0' && ch <= '9') {
    return true;
  }
  return false;
}

std::string translateToPostfix(const std::string& expression)
{
  for (size_t i = 0; i < expression.size(); ++i) {
    if (expression[i] != ' ' && expression[i] != '^'
        && expression[i] != '-' && expression[i] != '+'
        && expression[i] != '*' && expression[i] != '/'
        && expression[i] != '(' && expression[i] != ')'
        && (expression[i] < '0' || expression[i] > '9')) {
      throw std::invalid_argument("Unexpected operand!");
    }
  }
  std::stack<char> stack;
  std::string result;
  for (size_t i = 0; i < expression.size(); ++i) {
    if (expression[i] == ' ') {
      continue;
    }
    if (isDigit(expression[i])) {
      result += expression[i];
    } else if (expression[i] == '(') {
      stack.push(expression[i]);
    } else if (expression[i] == ')') {
      while (stack.top() != '(') {
        if (stack.top() != '(' && stack.top() != ')') {
          result += stack.top();
        }
        stack.pop();
      }
      if (stack.top() == '(')
        stack.pop();
    } else if (Operator(expression[i]).getOrder() != -1) {
      if (stack.empty() || stack.top() == '(') {
        stack.push(expression[i]);
      } else {
        if (stack.top() != '(' && stack.top() != ')') {
          result += stack.top();
        }
        stack.pop();
        stack.push(expression[i]);
      }
    }
  }
  while (!stack.empty()) {
    if (stack.top() != '(' && stack.top() != ')') {
      result += stack.top();
    }
    stack.pop();
  }
  return result;
}

int evaluatePostfix(const std::string& expression)
{
  std::stack<int> stack;
  for (int i = 0; i < expression.size(); i++) {
    if (isDigit(expression[i])) {
      int num;
      while (i < expression.length() && isDigit(expression[i])) {
        num = expression[i] - '0';
        stack.push(num);
        i++;
      }
    }
    if (Operator(expression[i]).getOrder() != -1) {
      int second = stack.top();
      stack.pop();
      int first = stack.top();
      stack.pop();
      switch (expression[i]) {
        case '+':
          stack.push(first + second);
          break;
        case '-':
          stack.push(first - second);
          break;
        case '*':
          stack.push(first * second);
          break;
        case '/':
          if (second == 0) {
            throw std::invalid_argument("You cannot divide by zero!");
          }
          stack.push(first / second);
          break;
        case '^':
          stack.push(std::pow(first, second));
      }
    }
  }
  return stack.top();
}
