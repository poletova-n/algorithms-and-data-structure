#include <iostream>
#include "StackArray.h"

bool checkBalanceBrackets(const std::string& text, int maxDeep = 30)
{
  try {
    if (text.size() >= 30 ){
      throw "The number of brackets is greater than the maximum allowed(30)! ";
    }
  }
  catch (const char * err) {
    std::cerr << err << std::endl;
    return false;
  }
  StackArray <char> stack(maxDeep) ;
  char n1, n2;
  for (int i = 0; text[i] != '\0'; i++) {
    n1 = text[i];
    if (n1 == '{' || n1 == '(' || n1 == '[')
      stack.push(n1);
    else if (n1 == '}' || n1 == ')' || n1 == ']')
    {
      if (n1 == '}')
        n2 = '{';
      if (n1 == ')')
        n2 = '(';
      if (n1 == ']')
        n2 = '[';
      if ((n2 == stack.top())&& (!stack.isEmpty()))
        stack.pop();
      else
        return false;
    }
  }
  if (stack.isEmpty())
    return true;
  else
    return false;
}
int evaluatePostfix(const std::string& postfix, size_t stackSize =30) {
  StackArray<int> temp(stackSize);
  int result = 0;
  try {
    if (postfix.empty())
      throw "\nAn empty string is passed\n";
    if (stackSize <= 0)
      throw "Non-positive stack dimension is introduced";
  }
  catch (const char* err) {
    std::cerr << err << std::endl;
    return 0;
  }
  for (char i : postfix) {
    try {
      if (((int)i < 48 || (int)i >57) && (int)i != 42 && (int)i != 43 && (int)i != 45 && (int)i != 47 || (int)i == 48 || (int)i == 41) {
        throw "Extraneous characters!";
      }
    }
    catch (const char* err) {
      std::cerr << err << std::endl;
      return -1;
    }
    if ((int)i != 42 && (int)i != 43 && (int)i != 45 && (int)i != 47 )
      temp.push((int)i - 48);
    else {
      try {
        if (temp.isEmpty())
          throw "Error in writing the postfix form!";
      }
      catch (const char * err) {
        std::cerr <<  err << std::endl;
        return -1;
      }
      int n2 = temp.pop();
      try {
        if (temp.isEmpty())
          throw "Error in writing the postfix form!";
      }
      catch (const char* err) {
        std::cerr << err << std::endl;
        return -1;
      }
      int n1 = temp.pop();
      if (i == '*')
        result = n1 * n2;
      else if (i == '/')
        result = n1 / n2;
      else if (i == '-')
        result = n1 - n2;
      else
        result = n1 + n2;
      temp.push(result);
    }
  }
  return result;
}
bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize = 30) {
  {
    postfix = "";
    StackArray<char> stack(stackSize);
    if (!checkBalanceBrackets(infix))
      return false;
    for (int i = 0; i < infix.size(); i++)
    {
      if (infix[i] == '(')
      {
        stack.push(infix[i]);
      }
      else if (infix[i] == ')')
      {
        while (stack.top() != '(')
        {
          postfix.push_back(stack.pop());
        }
        stack.pop();
      }
      else if ((infix[i] > 48) && (infix[i] <= 57))
      {
        postfix.push_back(infix[i]);
      }
      else if (((infix[i] == 43) || (infix[i] == 42) || (infix[i] == 47) || (infix[i] == 45)) && (stack.isEmpty()) || (stack.top() == 40))
      {
        stack.push(infix[i]);
      }
      else if (((infix[i] == 42) || (infix[i] == 47)) && ((stack.top() == 42) || (stack.top() == 47)))
      {
        postfix.push_back(stack.pop());
        stack.push(infix[i]);
      }
      else if (((infix[i] == 42) || (infix[i] == 47)) && ((stack.top() == 43) || (stack.top() == 45)))
      {
        stack.push(infix[i]);
      }

      else if ((infix[i] == 43) || (infix[i] == 45))
      {
        while ((stack.isEmpty() == 0) && (stack.top() != 40))
        {
          postfix.push_back(stack.pop());
        }
        stack.push(infix[i]);
      }
      try {
        if (infix[i] == '/' && infix[i+1] == '0')
          throw "Division by zero is not possible!";
      }
      catch (const char * err) {
        std::cerr << err << std::endl;
        return false;
      }
    }
    while (!stack.isEmpty())
    {
      postfix.push_back(stack.pop());
    }
    return 1;
  }

}
bool testCheckBalanceBrackets()
{
  const char* text00 = " ";
  std::cout << text00 << ": " << (checkBalanceBrackets(text00) ? "right" : "wrong") <<'\n';
  const char* text01 = "()";
  std::cout << text01 << ": " << (checkBalanceBrackets(text01) ? "right" : "wrong") << '\n';
  const char* text02 = "(([]))";
  std::cout << text02 << ": " << (checkBalanceBrackets(text02) ? "right" : "wrong") << '\n';
  const char* text03 = "(([{}[]([])]))";
  std::cout << text03 << ": " << (checkBalanceBrackets(text03) ? "right" : "wrong") << '\n';
  const char* text04 = "(([{}[]([])])))";
  std::cout << text04 << ": " << (checkBalanceBrackets(text04) ? "right" : "wrong") << '\n';
  const char* text05 = "(([{}[]([])]) ";
  std::cout << text05 << ": " << (checkBalanceBrackets(text05) ? "right" : "wrong") << '\n';
  const char* text06 = "(([{][]([])])) ";
  std::cout << text06 << ": " << (checkBalanceBrackets(text06) ? "right" : "wrong") << '\n';
  const char* text07 = "()()()()()()()()()()()()()()()( ";
  std::cout << text07 << ": " << (checkBalanceBrackets(text06) ? "right" : "wrong") << '\n';
  return true;
}
bool testGetPostfix() {
  std::string text00 = "1+2";
  std::string postfix00;
  if (getPostfixFromInfix(text00, postfix00) )
    std::cout << "Infix form: " << text00 << " Postfix form: " << postfix00 <<" = " <<evaluatePostfix(postfix00) << '\n';
  std::string text01 = "(1+2)*(4-1)";
  std::string postfix01;
  if (getPostfixFromInfix(text01, postfix01))
    std::cout << "Infix form: " << text01 << " Postfix form: " << postfix01 << " = " << evaluatePostfix(postfix01) << '\n';
  std::string text02 = " ";
  std::string postfix02;
  if (getPostfixFromInfix(text02, postfix02))
    std::cout << "Infix form: " << text02 << " Postfix form: " << postfix02 << " = " << evaluatePostfix(postfix02) << '\n';
  std::string text03 = "((6-7)/8)+5*4";
  std::string postfix03;
  if (getPostfixFromInfix(text03, postfix03))
    std::cout << "Infix form: " << text03 << " Postfix form:  " << postfix03 << " = " << evaluatePostfix(postfix03) << '\n';
  std::string text04 = "(2-4*3)/0";
  std::string postfix04;
  if (getPostfixFromInfix(text04, postfix04))
    std::cout << "Infix form: " << text04 << " Postfix form: " << postfix04 << " = " << evaluatePostfix(postfix04) << '\n';
  std::string text05 = "(6-8)*(7+3)/((7-9)-6)";
  std::string postfix05;
  if (getPostfixFromInfix(text05, postfix05))
    std::cout << "Infix form: " << text05 << " Postfix form: " << postfix05 << " = " << evaluatePostfix(postfix05) << '\n';
  std::string text06 = "(3-4*(6+3)*8+6-2)/(2-4)*5+(4*5+(5+6))/2";
  std::string postfix06;
  if (getPostfixFromInfix(text06, postfix06))
    std::cout << "Infix form: " << text06 << " Postfix form: " << postfix06 << " = " << evaluatePostfix(postfix06) << '\n';
  std::string text07 = "(4-5)*7-(5+6)*3";
  std::string postfix07;
  if (getPostfixFromInfix(text07, postfix07))
    std::cout << "Infix form: " << text07 << " Postfix form: " << postfix07 << " = " << evaluatePostfix(postfix07) << '\n';
  return true;
}
int main()
{
  StackArray<int> b(3);
  Stack<int>* a = &b;
  a->push(1);
  a->push(3);
  a->push(2);
  a->print();
  std::cout <<'\n'<< "Testing exceptions: "<<'\n';
  try {
    StackArray<int> c(0);
  }
  catch (const Stack<int>::WrongStackSize& e) {
    std::cout << '\n' << e.problem() ;
  }
  try {
    a->pop();
  }
  catch (const Stack<int>::StackUnderflow& e ){
    std::cout << '\n' << e.problem();
  }
  for (int i = 0; i < 3; i++) {
    a->push(i);
  }
  try {
    a->push(0);
  }
  catch (const Stack<int>::StackOverflow& e) {
    std::cout << '\n' << e.problem() << '\n';
  }
  testCheckBalanceBrackets();
  testGetPostfix();
}