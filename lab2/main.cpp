#include "stackArray.h"
#include "exception.h"
#include "stackList.h"

#include <iostream>

bool testBalanceBracketsArray(std::string str, int maxDeep = 30);
bool testBalanceBracketsList(std::string str);

int main()
{
    std::string text00 = " ";
    std::cout << text00 << ": " << testBalanceBracketsList(text00) << std::endl;
    std::string text01 = "( )";
    std::cout << text01 << ": " << testBalanceBracketsArray(text01) << std::endl;
    std::string text02 = "( ( [] ) )";
    std::cout << text02 << ": " << testBalanceBracketsList(text02) << std::endl;
    std::string text03 = "( ( [ { } [ ] ( [ ] ) ] ) )";
    std::cout << text03 << ": " << testBalanceBracketsArray(text03) << std::endl;
    std::string text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) )";
    std::cout << text04 << ": " << testBalanceBracketsList(text04) << std::endl;
    std::string text05 = "( ( [{ }[ ]([ ])] )";
    std::cout << text05 << ": " << testBalanceBracketsArray(text05) << std::endl;
    std::string text06 = "( ( [{ ][ ]([ ])]) )";
    std::cout << text06 << ": " << testBalanceBracketsList(text06) << std::endl;
    return 0;
}

bool testBalanceBracketsArray(std::string str, int maxDeep)
{
    Stack<char>* stack = new StackArray<char>(maxDeep);
    bool isBalanceBrackets = true;
    try
    {
        char cText = '\0';
        for (int i = 0; ((cText = str[i]) != '\0') && (isBalanceBrackets == true); i++)
        {
            switch (cText)
            {
                case '(': case '[': case '{':
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
    }
    catch (StackUnderflow)
    {
        isBalanceBrackets = false;
    }
    catch (StackOverflow)
    {
        isBalanceBrackets = false;
    }
    delete stack;
    return isBalanceBrackets;
}

bool testBalanceBracketsList(std::string str)
{
    StackList<char> list;
    Stack<char>* stack = &list;
    bool isBalanceBrackets = true;
    try
    {
        char cText = '\0';
        for (int i = 0; ((cText = str[i]) != '\0') && (isBalanceBrackets == true); i++)
        {
            switch (cText)
            {
                case '(': case '[': case '{':
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
    }
    catch (StackUnderflow)
    {
        isBalanceBrackets = false;
    }
    return isBalanceBrackets;
}

