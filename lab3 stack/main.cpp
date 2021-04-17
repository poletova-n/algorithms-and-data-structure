#include <iostream>
#include "stack.h"
#include "stackArray.h"

bool checkBalanceBrackets(const char* text, int maxDeep = 30);
bool isOperator(char C);
bool isDigit(char C);
int evaluatePostfix(const std::string& infix, size_t stackSize = 30);
bool getPostfix(const std::string& infix, std::string& postfix, size_t stackSize = 30);

int main()
{
  try {
    const char* text00 = " ok ";
    std::cout << text00 << ": "
              << (checkBalanceBrackets(text00) ? "right" : "wrong") << '\n';

    const char* text01 = "( ) ok ";
    std::cout << text01 << ": "
              << (checkBalanceBrackets(text01) ? "right" : "wrong") << '\n';

    const char* text02 = "( ( [] ) ) ok ";
    std::cout << text02 << ": "
              << (checkBalanceBrackets(text02) ? "right" : "wrong") << '\n';

    const char* text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) OK";
    std::cout << text03 << ": "
              << (checkBalanceBrackets(text03) ? "right" : "wrong") << '\n';

    const char* text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
    std::cout << text04 << ": "
              << (checkBalanceBrackets(text04) ? "right" : "wrong") << '\n';

    const char* text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
    std::cout << text05 << ": "
              << (checkBalanceBrackets(text05) ? "right" : "wrong") << '\n';

    const char* text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
    std::cout << text06 << ": "
              << (checkBalanceBrackets(text06) ? "right" : "wrong") << '\n';

    std::cout << "Test reverse Polish notation\n";
    std::string expression = "((7*5)-(3*5))*2";
    std::string expression2;
    getPostfix(expression, expression2);
    std::cout << "infix form: " << expression << std::endl << "postfix form: " <<
              expression2 << std::endl;
    std::cout << "Result: " << evaluatePostfix(expression2) << std::endl;
    std::string expression3 = "(1+2)/3";
    std::string expression4;
    getPostfix(expression3, expression4);
    std::cout << "infix form: " << expression3 << std::endl << "postfix form: " <<
              expression4 << std::endl;
    std::cout << "Result: " << evaluatePostfix(expression4) << std::endl;

    std::string expression5 = "(1+2)/1";
    std::string expression6;
    getPostfix(expression5, expression6);
    std::cout << "infix form: " << expression5 << std::endl << "postfix form: " <<
              expression6 << std::endl;
    std::cout << "Result: " << evaluatePostfix(expression6) << std::endl;
  } catch (const StackUnderflow& e) {
    std::cerr << e.what();
    return 1;
  } catch (const StackOverflow& e) {
    std::cerr << e.what();
    return 1;
  } catch (const WrongStackSize& e) {
    std::cerr << e.what();
    return 1;
  }
  return 0;
}

bool checkBalanceBrackets(const char* text, int maxDeep)
{
  Stack<char>* stack = new StackArray<char>(maxDeep);
  bool isBalanceBrackets = true;
  try {
    char cText = '\0';

    for (int i = 0; ((cText = text[i]) != '\0') && isBalanceBrackets; i++) {
      switch (cText) {
        case '(':
        case '[':
        case '{':
          stack->push(cText);
          break;
        case ')':
          if (stack->pop() != '(') {
            isBalanceBrackets = false;
          }
          break;
        case ']':
          if (stack->pop() != '[') {
            isBalanceBrackets = false;
          }
          break;
        case '}':
          if (stack->pop() != '{') {
            isBalanceBrackets = false;
          }
          break;
      }
    }
    isBalanceBrackets = isBalanceBrackets && stack->isEmpty();
  } catch (StackUnderflow&) {
    isBalanceBrackets = false;
  } catch (StackOverflow&) {
    isBalanceBrackets = false;
  }

  delete stack;
  return isBalanceBrackets;
}

bool isOperator(char C)
{
    if (C == '+' || C == '-' || C == '*' || C == '/') {
        return true;
    }
    return false;
}

bool isDigit(char C)
{
    if (C >= '0' && C <= '9') {
        return true;
    }
    return false;
}

int evaluatePostfix(const std::string& infix, size_t stackSize)
{
    StackArray<int> stack(stackSize);
    const char* temp = infix.c_str();

    if(!(checkBalanceBrackets(temp)))
    {
      throw std::logic_error("Check the brackets!");
    }
    for (int i = 0; i < infix.length(); i++)
    {
        if (isDigit(infix[i]))
        {
            int num = 0;
            while (i < infix.length() && isDigit(infix[i]))
            {
              num = (int) infix[i] - '0';
              stack.push(num);
              i++;
            }
        }
        if (isOperator(infix[i]))
        {
            int op_b = stack.top();
            stack.pop();
            int op_a = stack.top();
            stack.pop();
            switch (infix[i])
            {
                case '+':
                    stack.push(op_a + op_b);
                    break;
                case '-':
                    stack.push(op_a - op_b);
                    break;
                case '*':
                    stack.push(op_a * op_b);
                    break;
                case '/':
                  if(op_b == 0)
                  {
                    throw std::logic_error ("Zero deleting is forbidden\n");
                  }
                  stack.push(op_a / op_b);
                  break;
                default:
                  break;
            }
        }
    }
    return stack.pop();
}

bool getPostfix(const std::string& infix, std::string& postfix, size_t stackSize)
{
    char temp;
    for (char i : infix)
    {
        temp = i;
        if (temp != '(' && temp != ')' && temp != '+' && temp != '/'
            && temp != '-' && temp != '*' && (temp < '0' || temp > '9'))
        {
            std::cout << "Error! Invalid parameters!\n";
            return false;
        }
    }
    StackArray<char> stack;
    for (char i : infix)
    {
        if (isDigit(i)) {
            postfix += i;
        }
        else if (i == '(') {
            stack.push(i);
        }
        else if (isOperator(i))
        {
            if (stack.isEmpty() || stack.top() == '(')
            {
                stack.push(i);
            }
            else {
                postfix += stack.top();
                stack.pop();
                stack.push(i);
            }
        }
        else if (i == ')') {
            while (stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }
            if (stack.top() == '(')
                stack.pop();
        }
    }
    while (!stack.isEmpty())
    {
        postfix += stack.top();
        stack.pop();
    }
    if (!postfix.empty())
        return true;
    else
        return false;
}