#include <iostream>
#include <string>
#include "exception.hpp"
#include "stack.hpp"
#include "stackarray.hpp"
#include "stacklist.hpp"

bool arrayBalanceBrackets(const std::string &text);

bool listBalanceBrackets(const std::string &string);

bool isCorrect(const std::string &str, bool stackType);

int main() {
    StackArray<int> testArr;
    testArr.push(5);
    testArr.push(10);
    testArr.push(2);
    testArr.push(1);

    std::cout << "StackArray: " << testArr.pop() << ' ' << testArr.pop()
              << ' ' << testArr.pop() << ' ' << testArr.pop() << "\n";

    std::string text1 = "( ) OK ";
    std::cout << text1 << ": " << (isCorrect(text1, false) ? "Right" : "Wrong") << "\n";
    std::string text2 = "( ( [ ] ) ) OK ";
    std::cout << text2 << ": " << (isCorrect(text2, false) ? "Right" : "Wrong") << "\n";
    std::string text3 = "( ( [{}]([ ]) ) ) OK";
    std::cout << text3 << ": " << (isCorrect(text3, false) ? "Right" : "Wrong") << "\n";
    std::string text4 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) Extra right parenthesis ";
    std::cout << text4 << ": " << (isCorrect(text4, true) ? "Right" : "Wrong") << "\n";
    std::string text5 = "( ( [{ }[ ]([ ])] ) Extra left parenthesis ";
    std::cout << text5 << ": " << (isCorrect(text5, true) ? "Right" : "Wrong") << "\n";
    std::string text6 = "( ( [{ ][ ]([ ])]) ) Unpaired bracket ";
    std::cout << text6 << ": " << (isCorrect(text6, true) ? "Right" : "Wrong") << "\n";
}

bool arrayBalanceBrackets(const std::string &text)
{
    StackArray<char> stack(text.size());

    try
    {
        for (char i : text)
        {
            if ((i == '(') || (i == '[') || (i == '{'))
            {
                stack.push(i);
                continue;
            } else if ((i == ')') || (i == ']') || (i == '}'))
            {
                if (i == ')')
                {
                    if (stack.top() == '(' && (!stack.isEmpty()))
                    {
                        stack.pop();
                        continue;
                    } else
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
                    } else
                    {
                        return false;
                    }
                }
                if (stack.top() == '{' && (!stack.isEmpty()))
                {
                    stack.pop();
                    continue;
                } else
                {
                    return false;
                }
            }
        }
        if (stack.isEmpty())
        {
            return true;
        } else
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

bool listBalanceBrackets(const std::string &string)
{
    Stack<char> *stack = new StackList<char>();

    bool isBalanceBrackets = true;
    try
    {
        char cText = '\0';

        for (int i = 0;
             ((cText = string[i]) != '\0') && isBalanceBrackets;
             i++)
        {
            switch (cText)
            {
                case '(':
                case '[':
                case '{':
                    stack->push(cText);
                    break;
                case ')':
                    if (stack->pop() != '(')
                    {
                        isBalanceBrackets = false;
                    }
                    break;
                case ']':
                    if (stack->pop() != '[')
                    {
                        isBalanceBrackets = false;
                    }
                    break;
                case '}':
                    if (stack->pop() != '{')
                    {
                        isBalanceBrackets = false;
                    }
                    break;
            }
        }
        isBalanceBrackets = isBalanceBrackets && stack->isEmpty();
    } catch (StackUnderflow &)
    {
        isBalanceBrackets = false;
    } catch (StackOverflow &)
    {
        isBalanceBrackets = false;
    }
    return isBalanceBrackets;
}

bool isCorrect(const std::string &str, bool stackType)
{
    if (stackType)
    {
        return arrayBalanceBrackets(str);
    } else
    {
        return listBalanceBrackets(str);
    }
}