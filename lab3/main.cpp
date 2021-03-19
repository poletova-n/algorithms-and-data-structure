#include "operator.hpp"
#include "stack.hpp"
#include "stackArray.hpp"
#include <iostream>
#include <string>
#include <cmath>

std::string transformInfixToPostfix(const std::string& txt);
int considerPostfix(const std::string& txt);
void checkString(const std::string& txt);
bool isBracersMatch(const std::string &txt);

int main()
{
  try
    {
      std::string txt1 = "((9-5)*8)/2^2"; // ans: 8
      std::cout << transformInfixToPostfix(txt1) << " ==> "
                << considerPostfix(transformInfixToPostfix(txt1))
                << '\n';

      std::string txt2 = "((9+9)*((9+9)-2))/3"; // ans: 96
      std::cout << transformInfixToPostfix(txt2) << " ==> "
                << considerPostfix(transformInfixToPostfix(txt2))
                << '\n';

      std::string txt3 = "((1+1*(1+1*(1+1)))*(2+2*(2+2*(2+2))))/2"; // ans: 44
      std::cout << transformInfixToPostfix(txt3) << " ==> "
                << considerPostfix(transformInfixToPostfix(txt3))
                << '\n';

      std::string txt4 = "((9+8)*8)/((3+5)/2)"; // ans: 34
      std::cout << transformInfixToPostfix(txt4) << " ==> "
                << considerPostfix(transformInfixToPostfix(txt4))
                << '\n';

      std::string txt5 = "( ( 3 + 7 ) * 5 ) ^ 2"; // ans: 2500
      std::cout << transformInfixToPostfix(txt5) << " ==> "
                << considerPostfix(transformInfixToPostfix(txt5))
                << '\n';

      std::string txt6 = "(((5+3)/2)^2)"; // ans: 16
      std::cout << transformInfixToPostfix(txt6) << " ==> "
                << considerPostfix(transformInfixToPostfix(txt6))
                << '\n';
    }
  catch (const std::invalid_argument& exception)
    {
      std::cout << exception.what() << '\n';
    }
  catch (const std::logic_error& exception)
    {
      std::cout << exception.what() << '\n';
    }
  return 0;
}

std::string transformInfixToPostfix(const std::string& txt)
{
    StackArray<char> stack(txt.size());
    std::string newExpression;
    checkString(txt);
    if(!(isBracersMatch(txt)))
    {
        std::cout << txt << '\n';
        throw std::logic_error("Check the brackets!");
    }

    for (char i : txt)
    {
        if (i == ' ')
        {
            continue;
        }
        if (i >= '0' && i <= '9')
        {
            newExpression += i;
            continue;
        }
        else if (i == '+' || i == '-' || i == '*' || i == '/' || i == '^')
        {
            Operator currentOperand(i);
            Operator topOperand(stack.top());

            if ((stack.isEmpty()) || (stack.top() == '('))
            {
                stack.push(i);
            }
            else if (currentOperand.getPriority() > topOperand.getPriority())
            {
                stack.push(i);
            }
            else if (currentOperand.getPriority() <= topOperand.getPriority())
            {
                char temp = stack.top();
                while ((temp != '(' || Operator(temp).getPriority() > Operator(stack.top()).getPriority()) && !(stack.isEmpty()))
                {
                    temp = stack.top();
                    stack.push(stack.pop());
                    newExpression += temp;
                }
                stack.push(i);
            }
        }
        else if (i == '(')
        {
            stack.push(i);
            continue;
        }
        else if (i == ')')
        {
            while (stack.top() != '(' && !(stack.isEmpty()))
            {
                newExpression += stack.pop();
            }
            if (stack.top() == '(')
            {
                stack.pop();
            }
            continue;
        }
    }
    while (!(stack.isEmpty()))
    {
        newExpression += stack.pop();
    }
    return newExpression;
}

bool isBracersMatch(const std::string &txt)
{
    StackArray<char> stack(txt.size());
    try
    {
        for (char i : txt)
        {
            if ((i == '(') || (i == '[') || (i == '{'))
            {
                stack.push(i);
                continue;
            }
            else if ((i == ')') || (i == ']') || (i == '}'))
            {
                if (i == ')')
                {
                    if ((!stack.isEmpty()) && stack.top() == '(')
                    {
                        stack.pop();
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (i == ']')
                {
                    if (stack.top() == '[' && (!stack.isEmpty()))
                    {
                        stack.pop();
                        continue;
                    }
                    else
                    {
                        return false;
                    }
                }
                if (stack.top() == '{' && (!stack.isEmpty()))
                {
                    stack.pop();
                    continue;
                } else {
                    return false;
                }
            }
        }
        if (stack.isEmpty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    catch (StackUnderflow)
    {
        return false;
    }
    catch (StackOverflow)
    {
        return false;
    }
}

void checkString(const std::string& txt)
{
  for (char i : txt)
    {
      if (!(i >= '0' && i <= '9') && i != '(' && i != ')' && i != ' ' && i != '^' && i != '-' && i != '+' && i != '*' && i != '/')
        {
          throw std::invalid_argument("Invalid string specified.");
        }
    }
}

int considerPostfix(const std::string& txt)
{
  StackArray<int> stack(txt.size());
  int val1;
  int val2;
  int res = 0;
  for (char i : txt)
    {
      if (i >= '0' && i <= '9')
        {
          stack.push(i - '0');
        }
      else
        {
          val2 = stack.pop();
          val1 = stack.pop();
          switch (i)
            {
              case '+':
                res = val1 + val2;
                break;
              case '-':
                res = val1 - val2;
                break;
              case '/':
                if (val2 == 0)
                  {
                    throw std::logic_error("Can't be divided by 0.");
                  }
                res = val1 / val2;
                break;
              case '*':
                res = val1 * val2;
                break;
              case '^':
                res = std::pow(val1, val2);
                break;

              default:
                break;
            }
          stack.push(res);
        }
    }
  return stack.pop();
}