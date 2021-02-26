#include <iostream>
#include "array_stack.hpp"
#include "list_stack.hpp"

bool right_balanced_br(std::string str, bool mode = false);
bool array_balance(std::string str);
bool list_balance(std::string str);

int main()
{
  std::string test1 = "( )"; // true
  std::string test2 = "( { } )"; // true
  std::string test3 = "( { [ ] } )"; // true
  std::string test4 = "( { [ ]  )"; // false
  std::string test5 = "( [ {} { [] { () } ] )"; // false
  std::cout << right_balanced_br(test1, true) << std::endl;
  std::cout << right_balanced_br(test2, true) << std::endl;
  std::cout << right_balanced_br(test3) << std::endl;
  std::cout << right_balanced_br(test4) << std::endl;
  std::cout << right_balanced_br(test5) << std::endl;
}

bool right_balanced_br(std::string str, bool mode) {
  if (mode) {
    return array_balance(str);
  }
  else {
    return list_balance(str);
  }
};

bool array_balance(std::string str)
{
  StackArray<char> array_stack(str.length());
  for (int i = 0; i < (int)str.length(); ++i) {
    if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
      array_stack.push(str[i]);
    }
    else if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
      if (array_stack.is_empty()) {
        return false;
      }
      if ((str[i]==')' && array_stack.get_top()=='(') || (str[i] == '}' && array_stack.get_top() == '{') || (str[i] == ']' && array_stack.get_top() == '[')) {
        array_stack.pop();
      }
      else {
        return false;
      }
    }
  }
  return array_stack.is_empty();
}

bool list_balance(std::string str)
{
  StackList<char> list_stack;
  for (int i = 0; i < (int)str.length(); ++i) {
    if (str[i] == '{' || str[i] == '(' || str[i] == '[') {
      list_stack.push(str[i]);
    }
    else if (str[i] == '}' || str[i] == ')' || str[i] == ']') {
      if (list_stack.is_empty()) {
        return false;
      }
      if ((str[i] == ')' && list_stack.get_top() == '(') || (str[i] == '}' && list_stack.get_top() == '{') || (str[i] == ']' && list_stack.get_top() == '[')) {
        list_stack.pop();
      }
      else {
        return false;
      }
    }
  }
  return list_stack.is_empty();
}