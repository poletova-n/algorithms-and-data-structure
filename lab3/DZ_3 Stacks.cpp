#include <string>
#include <iostream>
#include "StackArray.h"


bool isDigit(const char& c);

bool isOperation(const char& c);

bool isCorrect(const std::string& infix);

bool getPostfixFromInfix(const std::string& infix, std::string& postfix, std::size_t stackSize = 30);

int evaluatePostfix(const std::string& postfix, std::size_t stackSize = 30);

void test();

bool checkBalanceBrackets(const std::string& text, int maxDeep = 30);

void testCheckBalanceBrackets();



int main()
{
  test();

  std::cout << "Create intStack\n";
  try {
    StackArray<int> intStack;
    try {
      std::cout << "Push 4\n"; intStack.push(4);
      std::cout << "Push 5\n"; intStack.push(5);
      std::cout << "Push 1\n"; intStack.push(1);
    } 
    catch (StackOverflow &exceptionOver) {
      std::cerr << "Error: " << exceptionOver.getError() << std::endl;
    }
    std::cout << "Return value of current top: " << intStack.peek() << std::endl;
    try {
      std::cout << "Pop top: " << intStack.pop() << std::endl;
      std::cout << "Pop top: " << intStack.pop() << std::endl;
      std::cout << "Pop top: " << intStack.pop() << std::endl;
      std::cout << "Pop top: " << intStack.pop() << std::endl;
    }
    catch (StackUnderflow &exceptionUnder) {
      std::cerr << "Error: " << exceptionUnder.getError() << std::endl;
    }
  }
  catch (WrongStackSize& exceptionWrong) {
    std::cerr << "Error: " << exceptionWrong.getError() << std::endl;
  }
  std::cout << "----------------------------------------\n";


  std::cout << "Create dblStack with pointer\n";
  try {
    StackArray<double> dblStack(2);
    Stack<double>* d = &dblStack;
    try {
      std::cout << "Push 10\n"; d->push(10);
      std::cout << "Push 20\n"; d->push(20);
      std::cout << "Push 30\n"; d->push(30);
    }
    catch (StackOverflow& exceptionOver) {
      std::cerr << "Error: " << exceptionOver.getError() << std::endl;
    }
    try {
      std::cout << "Pop top: " << d->pop() << std::endl;
      std::cout << "Pop top: " << d->pop() << std::endl;
    }
    catch (StackUnderflow& exceptionUnder) {
      std::cerr << "Error: " << exceptionUnder.getError() << std::endl;
    }
  }
  catch (WrongStackSize& exceptionWrong) {
    std::cerr << "Error: " << exceptionWrong.getError() << std::endl;
  }
  std::cout << "----------------------------------------\n";


  std::cout << "Create charStack\n";
  try {
    StackArray<char> charStack(-3);
    try {
      std::cout << "Push W\n"; charStack.push('W');
    }
    catch (StackOverflow& exceptionOver) {
      std::cerr << "Error: " << exceptionOver.getError() << std::endl;
    }
    std::cout << "Return value of current top: " << charStack.peek() << std::endl;
    try {
      std::cout << "Pop top: " << charStack.pop() << std::endl;
    }
    catch (StackUnderflow& exceptionUnder) {
      std::cerr << "Error: " << exceptionUnder.getError() << std::endl;
    }
  }
  catch (WrongStackSize& exceptionWrong) {
    std::cerr << "Error: " << exceptionWrong.getError() << std::endl;
  }
  std::cout << "----------------------------------------\n";

  testCheckBalanceBrackets();
  std::cout << "----------------------------------------\n";

  return 0;
}



bool isDigit(const char& c)
{
  if (c >= '0' && c <= '9') {
    return true;
  }
  return false;
}


bool isOperation(const char& c)
{
  if (c == '+' || c == '-' || c == '*' || c == '/') {
    return true;
  }
  return false;
}


bool isCorrect(const std::string& infix)
{
  int openBracket = 0;
  int closeBracket = 0;
  char current, next;
  
  for (int i = 0; i < infix.size(); i++)
  {
    current = infix[i];

    if ((infix[0] != '(') && (!isDigit(infix[0])))
      throw "Fisrt symbol is uncorrected!";

    if (!isDigit(infix[infix.size() - 1]) && (infix[infix.size() - 1] != ')'))
      throw "Last symbol is uncorrected!";

    if ((current != '(') && (current != ')') && (!isOperation(current)) && (!isDigit(current)))
      throw "Uncorrected symbols at this string!";
     
    if (current == '(')
      openBracket++;
    if (current == ')')
      closeBracket++;
  }

  if (openBracket != closeBracket)
    throw "Extra brackets!";

  for (int i = 0; i < infix.size()-1; i++)
  {
    current = infix[i];
    next = infix[i + 1];

    if (isOperation(current) && isOperation(next))
      throw "Two operations near!";

    if (isDigit(current) && isDigit(next))
      throw "Two digits near!";

    if ((current == ')' && isDigit(next)) || (next == '(' && isDigit(current)))
      throw "Default symbols near";
  }
  return true;
}


bool getPostfixFromInfix(const std::string& infix, std::string& postfix, std::size_t stackSize)
{
  char current;
  std::string temp = infix;
  StackArray<char> operators_stack;
  
  try
  {
    if (isCorrect(infix))
    {
      int k = 0;
      for (int j = 0; j < infix.size(); j++)
      {
        current = infix[j];

        if (current >= '0' && current <= '9')
        {
          postfix.insert(k, 1, current);
          k++;
          continue;
        }

        if (current == '(')
        {
          operators_stack.push(current);
          continue;
        }

        if (current == ')') 
        {
          while (operators_stack.peek() != '(') {
            postfix.insert(k, 1, operators_stack.pop());
            k++;
          }
          operators_stack.pop(); 
          continue;
        }

        if (current == '+' || current == '-')
        {
          if (operators_stack.peek() == '(' || operators_stack.isEmpty()) 
          {
            operators_stack.push(current); 
            continue;
          }

          if (operators_stack.peek() == '+' || operators_stack.peek() == '-' || operators_stack.peek() == '*' || operators_stack.peek() == '/') 
          {
            while (operators_stack.peek() == '+' || operators_stack.peek() == '-' || operators_stack.peek() == '*' || operators_stack.peek() == '/') 
            {
              postfix.insert(k, 1, operators_stack.pop());
              k++;
            }
            operators_stack.push(current);
            continue;
          }
        }

        if (current == '*' || current == '/')
        {
          if (operators_stack.peek() == '(' || operators_stack.isEmpty() || operators_stack.peek() == '+' || operators_stack.peek() == '-') 
          {
            operators_stack.push(current);
            continue;
          }

          if (operators_stack.peek() == '*' || operators_stack.peek() == '/') 
          {
            while (operators_stack.peek() == '*' || operators_stack.peek() == '/') 
            {
              postfix.insert(k, 1, operators_stack.pop());
              k++;
            }
            operators_stack.push(current);
            continue;
          }
        }
      }
      if (!operators_stack.isEmpty())
      {
        while (!operators_stack.isEmpty()) {
          postfix.insert(k, 1, operators_stack.pop());
          k++;
        }
      }
    }
  }
  catch (const char* exception)
  {
    std::cerr << "Error: " << exception << std::endl;
    return false;
  }

  return true;
}


int evaluatePostfix(const std::string& postfix, std::size_t stackSize)
{
  StackArray<int> value_stack;
  int n1 = 0, n2 = 0, res = 0;

  for (int i = 0; i < postfix.size(); ++i) {
    if (isDigit(postfix[i])) {
      value_stack.push((int)postfix[i]-48);
    }
    else {
      n2 = value_stack.pop();
      n1 = value_stack.pop();
      switch (postfix[i]) {
      case '+': 
        res = n1 + n2;
        break;
      case '-':
        res = n1 - n2;
        break;
      case '*':
        res = n1 * n2;
        break;
      case '/':
        res = n1 / n2;
        break;
      default:
        std::cerr << "Default operation symbol!\n";
      }
      value_stack.push(res);
    }
  }
  return value_stack.pop();
}


void test()
{
  std::cout << "---------------------------------------------\n";
  std::string infix, postfix;
  infix = "1+2+3+4+5+6+7+8";
  std::cout << "Infix: " << infix << std::endl;
  if (getPostfixFromInfix(infix, postfix)) {
    std::cout << "Postfix: " << postfix << " = " << evaluatePostfix(postfix) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix1, postfix1;
  infix1 = "(5*(2+3)+6)*(2-4)";
  std::cout << "Infix: " << infix1 << std::endl;
  if (getPostfixFromInfix(infix1, postfix1)) {
    std::cout << "Postfix: " << postfix1 << " = " << evaluatePostfix(postfix1) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix2, postfix2;
  infix2 = "((3/3)*8+9*(4-2))";
  std::cout << "Infix: " << infix2 << std::endl;
  if (getPostfixFromInfix(infix2, postfix2)) {
    std::cout << "Postfix: " << postfix2 << " = " << evaluatePostfix(postfix2) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix3, postfix3;
  infix3 = "(((5*4-6/2)/2)+(1*4)-(5+2)/7*4)*2";
  std::cout << "Infix: " << infix3 << std::endl;
  if (getPostfixFromInfix(infix3, postfix3)) {
    std::cout << "Postfix: " << postfix3 << " = " << evaluatePostfix(postfix3) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix4, postfix4;
  infix4 = "1+2/3";
  std::cout << "Infix: " << infix4 << std::endl;
  if (getPostfixFromInfix(infix4, postfix4)) {
    std::cout << "Postfix: " << postfix4 << " = " << evaluatePostfix(postfix4) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix5, postfix5;
  infix5 = "8-2+4-6+5*4/2";
  std::cout << "Infix: " << infix5 << std::endl;
  if (getPostfixFromInfix(infix5, postfix5)) {
    std::cout << "Postfix: " << postfix5 << " = " << evaluatePostfix(postfix5) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix6, postfix6;
  infix6 = "(((5+6)*8+(4/2)-5*(7/2))+2)*7";
  std::cout << "Infix: " << infix6 << std::endl;
  if (getPostfixFromInfix(infix6, postfix6)) {
    std::cout << "Postfix: " << postfix6 << " = " << evaluatePostfix(postfix6) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix7, postfix7;
  infix7 = "((((9/3)*7*2+2-(2/(5+6)-1)+3*4)+7)*(6-8))-5";
  std::cout << "Infix: " << infix7 << std::endl;
  if (getPostfixFromInfix(infix7, postfix7)) {
    std::cout << "Postfix: " << postfix7 << " = " << evaluatePostfix(postfix7) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix8, postfix8;
  infix8 = "A((4/2)-(3+6)*2)";
  std::cout << "Infix: " << infix8 << std::endl;
  if (getPostfixFromInfix(infix8, postfix8)) {
    std::cout << "Postfix: " << postfix8 << " = " << evaluatePostfix(postfix8) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix9, postfix9;
  infix9 = "(3+5)*7*(6+2)-3R";
  std::cout << "Infix: " << infix9 << std::endl;
  if (getPostfixFromInfix(infix9, postfix9)) {
    std::cout << "Postfix: " << postfix9 << " = " << evaluatePostfix(postfix9) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix10, postfix10;
  infix10 = "((1+4*5)/3+Ts)";
  std::cout << "Infix: " << infix10 << std::endl;
  if (getPostfixFromInfix(infix10, postfix10)) {
    std::cout << "Postfix: " << postfix10 << " = " << evaluatePostfix(postfix10) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix11, postfix11;
  infix11 = "(((((3-6)*2+(5*9))";
  std::cout << "Infix: " << infix11 << std::endl;
  if (getPostfixFromInfix(infix11, postfix11)) {
    std::cout << "Postfix: " << postfix11 << " = " << evaluatePostfix(postfix11) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix12, postfix12;
  infix12 = "4*+5+2-1";
  std::cout << "Infix: " << infix12 << std::endl;
  if (getPostfixFromInfix(infix12, postfix12)) {
    std::cout << "Postfix: " << postfix12 << " = " << evaluatePostfix(postfix12) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix13, postfix13;
  infix13 = "(02-4/2+7*(9-2))";
  std::cout << "Infix: " << infix13 << std::endl;
  if (getPostfixFromInfix(infix13, postfix13)) {
    std::cout << "Postfix: " << postfix13 << " = " << evaluatePostfix(postfix13) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix14, postfix14;
  infix14 = "(7*2)7+6*2";
  std::cout << "Infix: " << infix14 << std::endl;
  if (getPostfixFromInfix(infix14, postfix14)) {
    std::cout << "Postfix: " << postfix14 << " = " << evaluatePostfix(postfix14) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";

  std::string infix15, postfix15;
  infix15 = "5+8/2-4*7(2*2)";
  std::cout << "Infix: " << infix15 << std::endl;
  if (getPostfixFromInfix(infix15, postfix15)) {
    std::cout << "Postfix: " << postfix15 << " = " << evaluatePostfix(postfix15) << std::endl;
  }
  else {
    std::cout << "Not converted :c\n";
  }
  std::cout << "---------------------------------------------\n";
}


bool checkBalanceBrackets(const std::string& text, int maxDeep)
{
  StackArray<char> brackets; 
  char start, fin;
  for (size_t i = 0; i < text.size(); i++)
  {
    start = text[i];
    if (start == '(' || start == '{' || start == '[') 
    {
      brackets.push(start); 
      continue;
    }

    if (start == ')' || start == '}' || start == ']')
    {
      if (start == ')')
        fin = '(';
      if (start == '}')
        fin = '{';
      if (start == ']')
        fin = '[';
      if ((fin = brackets.peek()) && (!brackets.isEmpty())) {
        brackets.pop(); 
        continue;
      }
      else {
        return false;
      }
    }
  }
  if (brackets.isEmpty()) {
    return true;
  }
  else {
    return false;
  }
}


void testCheckBalanceBrackets()
{
  std::string test00 = " "; 
  std::cout << test00 << (checkBalanceBrackets(test00) ? " right" : " wrong") << std::endl;
  std::string test01 = "( )"; 
  std::cout << test01 << (checkBalanceBrackets(test01) ? " right" : " wrong") << std::endl;
  std::string test02 = "(([]))";
  std::cout << test02 << (checkBalanceBrackets(test02) ? " right" : " wrong") << std::endl;
  std::string test03 = "((([])"; 
  std::cout << test03 << (checkBalanceBrackets(test03) ? " right" : " wrong") << std::endl;
  std::string test04 = "[[((((()))))]]"; 
  std::cout << test04 << (checkBalanceBrackets(test04) ? " right" : " wrong") << std::endl;
  std::string test05 = "((((()))))"; 
  std::cout << test05 << (checkBalanceBrackets(test05) ? " right" : " wrong") << std::endl;
  std::string test06 = "{{(([[]]))}}"; 
  std::cout << test06 << (checkBalanceBrackets(test06) ? " right" : " wrong") << std::endl;
  std::string test07 = "(())"; 
  std::cout << test07 << (checkBalanceBrackets(test07) ? " right" : " wrong") << std::endl;
  std::string test08 = "(((((((((((()";
  std::cout << test08 << (checkBalanceBrackets(test08) ? " right" : " wrong") << std::endl;
  std::string test09 = "(]]]}}})"; 
  std::cout << test09 << (checkBalanceBrackets(test09) ? " right" : " wrong") << std::endl;
  std::string test10 = "{}[()]()))))))))))))";
  std::cout << test10 << (checkBalanceBrackets(test10) ? " right" : " wrong") << std::endl;
  std::string test11 = "()()(())((()))";
  std::cout << test11 << (checkBalanceBrackets(test11) ? " right" : " wrong") << std::endl;
}
