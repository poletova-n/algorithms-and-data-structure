#include "operator.hpp"
#include "stack.hpp"
#include "stackArray.hpp"
#include <iostream>
#include <string>

std::string transformInfixToPostfix(const std::string& txt);
int considerPostfix(const std::string& txt);
void checkString(const std::string& txt);

int main()
{
  try
    {
      std::string txt1 = "((9-5)*8)/2"; // ans: 16
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

      std::string txt5 = "(9*9*9)/(3*3)"; // ans: 81
      std::cout << transformInfixToPostfix(txt5) << " ==> "
                << considerPostfix(transformInfixToPostfix(txt5))
                << '\n';

      std::string txt6 = "((3+7)*5)+((2+8)*(7-1))"; // ans: 110
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
      else
        {
          if (i == ')')
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
          else if (Operator(i).getPriority() != -1)
            {
              stack.push(i);
            }
        }
    }
  while (!(stack.isEmpty()))
    {
      newExpression += stack.pop();
    }
  return newExpression;
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

              default:
                break;
            }
          stack.push(res);
        }
    }
  return stack.pop();
}