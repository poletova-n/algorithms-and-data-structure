#include <iostream>
#include "operand.hpp"
#include "array_stack.hpp"

bool is_operand(char ch);
bool is_bracket(char ch);
std::string erase_brackets(std::string str);
int calculate(int left, int right, char oper);
std::string inf_to_post(std::string& str);
int calculate_post(const std::string& str);
bool bracket_balance(std::string str);

int main()
{
  try
  {
    std::string str1 = "3 * 5 + (9 * 2)";
    std::string str2 = "2 * 9 / (9 + 9)";
    std::string str3 = "(1 / 1 + 2 / 2) / 1";
    std::string str4 = "(6^2) / 6*6";
    std::string str5 = "( 1^2 ) / ( 5^0 - 1 )";

    std::cout << "CHECKING BRACKETS: \n"
              << "String1: " << str1 << "\n"
              << "Bracket status: " << bracket_balance(str1) << "\n"
              << "-----------------------------------" << "\n"
              << "String2: " << str2 << "\n"
              << "Bracket status: " << bracket_balance(str2) << "\n"
              << "-----------------------------------" << "\n"
              << "String3: " << str3 << "\n"
              << "Bracket status: " << bracket_balance(str3) << "\n"
              << "-----------------------------------" << "\n"
              << "String4: " << str4 << "\n"
              << "Bracket status: " << bracket_balance(str4) << "\n"
              << "-----------------------------------" << "\n"
              << "String5: " << str5 << "\n"
              << "Bracket status: " << bracket_balance(str5) << "\n"
              << "-----------------------------------" << "\n";
    std::cout << "WORK WITH STR_1: \n"
              << "Original: " << str1 << "\n"
              << "Postfix-form: " << inf_to_post(str1) << "\n"
              << "result: " << calculate_post(inf_to_post(str1)) << "\n"
              << "-----------------------------------" << "\n";
    std::cout << "WORK WITH STR_2: \n"
              << "Original: " << str2 << "\n"
              << "Postfix-form: " << inf_to_post(str2) << "\n"
              << "result: " << calculate_post(inf_to_post(str2)) << "\n"
              << "-----------------------------------" << "\n";
    std::cout << "WORK WITH STR_3: \n"
              << "Original: " << str3 << "\n"
              << "Postfix-form: " << inf_to_post(str3) << "\n"
              << "result: " << calculate_post(inf_to_post(str3)) << "\n"
              << "-----------------------------------" << "\n";
    std::cout << "WORK WITH STR_4: \n"
              << "Original: " << str4 << "\n"
              << "Postfix-form: " << inf_to_post(str4) << "\n"
              << "result: " << calculate_post(inf_to_post(str4)) << "\n"
              << "-----------------------------------" << "\n";
    std::cout << "WORK WITH STR_5: \n"
              << "Original: " << str5 << "\n"
              << "Postfix-form: " << inf_to_post(str5) << "\n"
              << "result: " << calculate_post(inf_to_post(str5)) << "\n"
              << "-----------------------------------" << "\n";
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << std::endl <<"ERROR: " << e.what() << std::endl;
    return 1;
  }
  return 0;
}

bool is_operand(char ch) {
  if (ch == '+' || ch == '-' || ch == '*' || ch == '^' || ch == '/') {
    return true;
  }
  return false;
}

bool is_bracket(char ch) {
  if (ch == '(' || ch == ')') {
    return true;
  }
  return false;
}

std::string erase_brackets(std::string str) {
  std::string no_brack;
  for (int i = 0; i < str.length(); i++) {
    if (!is_bracket(str[i])) {
      no_brack.push_back(str[i]);
    }
  }
  return no_brack;
}

int calculate(int left, int right, char oper) {
  switch (oper)
  {
  case '-':
    return left - right;
    break;
  case '+':
    return left + right;
    break;
  case '/':
    if (right == 0) {
      throw std::invalid_argument("the denominator must be greater than zero!");
    }
    return left / right;
    break;
  case '*':
    return left * right;
    break;
  case '^':
    return pow(left, right);
    break;
  }
}

int calculate_post(const std::string& str) {
  const int ch_zero = '0';
  const int ch_nine = '9';
  StackArray<char> stack(str.length());
  for (int i = 0; i < str.length(); i++) {
    if (((int)str[i] >= ch_zero) && ((int)str[i] <= ch_nine)) {
      stack.push((int)str[i] - ch_zero);
    }
    else if (is_operand(str[i])) {
      stack.push(calculate(stack.pop(), stack.pop(), str[i]));
    }
  }
  return stack.get_top();
}

std::string inf_to_post(std::string& str) {
  const int ch_zero = '0';
  const int ch_nine = '9';
  std::string postfix = "";
  StackArray<char> stack(str.length());
  for (int i = 0; i < str.length(); i++) {
    if (((int)str[i] >= ch_zero) && ((int)str[i] <= ch_nine)) {
      postfix.push_back(str[i]);
      postfix.push_back(' ');
    }
    else if (is_operand(str[i])) {
      Operand curr(str[i]);
      Operand top_oper(stack.get_top());
      if ((stack.get_top() == '(') || (stack.is_empty())) {
        stack.push(str[i]);
      }
      else if (curr.get_priority() > top_oper.get_priority()) {
        stack.push(str[i]);
      }
      else if (curr.get_priority() <= top_oper.get_priority()) {
        char counter = stack.get_top();
        while ((counter != '(' || Operand(counter).get_priority() > Operand(stack.get_top()).get_priority()) &&
          !stack.is_empty())
        {
          counter = stack.get_top();
          postfix.push_back(stack.pop());
          postfix.push_back(' ');
        }
        stack.push(str[i]);
      }
    }
    else if (str[i] == '(') {
      stack.push(str[i]);
    }
    else if (str[i] == ')') {
      char counter = stack.get_top();
      while ((counter != '(') && (!stack.is_empty()))
      {
        counter = stack.get_top();
        postfix.push_back(stack.pop());
        if ((counter != '(') && (counter != ')')) {
          postfix.push_back(' ');
        }
      }
    }
  }
  while (!stack.is_empty())
  {
    postfix.push_back(stack.pop());
    postfix.push_back(' ');
  }
  postfix = erase_brackets(postfix);
  return postfix;
}

bool bracket_balance(std::string str)
{
  StackArray<char> array_stack(str.length());
  for (int i = 0; i < (int)str.length(); ++i) {
    if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
      array_stack.push(str[i]);
    }
    else if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
      if (array_stack.is_empty()) {
        throw std::invalid_argument("Brackets disbalanced!");
        return false;
      }
      if ((str[i] == ')' && array_stack.get_top() == '(') || (str[i] == '}' && array_stack.get_top() == '{') || (str[i] == ']' && array_stack.get_top() == '[')) {
        array_stack.pop();
      }
      else {
        throw std::invalid_argument("Brackets disbalanced!");
        return false;
      }
    }
  }
  return array_stack.is_empty();
}