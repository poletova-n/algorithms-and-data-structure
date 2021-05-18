#include <iostream>
#include <string>
#include <cmath>
#include <stdexcept>
#include "StackArray.h"
bool isDigit(const char& c);
bool isOperation(const char& c);
bool testCheckBalanceBrackets();
int evaluatePostfix(const std::string& infix, size_t stackSize = 30);
bool checkBalanceBrackets(const std::string& text, size_t maxDeep = 30);
bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize = 30);

int main()
{
    std::string a = "(7*((8)/6-4)+6)*3";
    std::string b;
    getPostfixFromInfix(a, b);
    std::cout << "infix: " << a << "\n";
    std::cout << "postfix: " << b << "\n" << "\n";
    std::cout << "result: " << evaluatePostfix(b) << "\n\n";
    try
    {
      evaluatePostfix("20/");
    }
    catch (const std::logic_error& e)
    {
      std::cout << e.what() << "\n\n";
    }
    a = "5*6+2";
    getPostfixFromInfix(a, b);
    std::cout << "infix: " << a << "\n";
    std::cout << "postfix: " << b << "\n" << "\n";
    std::cout << "result: " << evaluatePostfix(b) << "\n\n";
    a = "2*9+(2^5+4)";
    getPostfixFromInfix(a, b);
    std::cout << "infix: " << a << "\n";
    std::cout << "postfix: " << b << "\n" << "\n";
    std::cout << "result: " << evaluatePostfix(b) << "\n\n";
    StackArray <int> test;
    test.push(1);
    test.push(2);
    test.push(3);
    std::cout << "Elements output: " << test.pop() << " " << test.pop() << " " << test.pop() << "\n";
    test.push(7);
    std::cout << test.top() << "\n";
    test.push(8);
    std::cout << test.top() << "\n";
    test.push(9);
    std::cout << test.top() << "\n";
    StackArray<int> test2(test);
    std::cout << test2.top() << "\n";
    test2.pop();
    std::cout << test2.top() << "\n";
    test2.pop();
    std::cout << test2.top() << "\n";
    test2.pop();
    testCheckBalanceBrackets();
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
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^') {
        return true;
    }
    return false;
}

bool testCheckBalanceBrackets()
{
    std::string text00 = " ";
    std::cout << text00 << ": " << (checkBalanceBrackets(text00) ? "right" : "wrong") << std::endl;

    std::string text01 = "( )";
    std::cout << text01 << ": " << (checkBalanceBrackets(text01) ? "right" : "wrong") << std::endl;

    std::string text02 = "( ( [] )";
    std::cout << text02 << ": " << (checkBalanceBrackets(text02) ? "right" : "wrong") << std::endl;

    std::string text03 = "( { [ ( ( ) ) { } [ ] ( [ ] ) ] } )";
    std::cout << text03 << ": " << (checkBalanceBrackets(text03) ? "right" : "wrong") << std::endl;

    std::string text04 = "( ( ( [ { } ] ) ( [ ] ) ) )";
    std::cout << text04 << ": " << (checkBalanceBrackets(text04) ? "right" : "wrong") << std::endl;

    std::string text05 = "( ( [{ }[ ]([ ])] )";
    std::cout << text05 << ": " << (checkBalanceBrackets(text05) ? "right" : "wrong") << std::endl;

    std::string text06 = "( ( ) ) ) [ ) { ) ( ) ) )";
    std::cout << text06 << ": " << (checkBalanceBrackets(text06) ? "right" : "wrong") << std::endl;

    return true;
}

int evaluatePostfix(const std::string& infix, size_t stackSize)
{
    StackArray<int> stack(stackSize);
    for (int i = 0; i < infix.length(); i++) {
        if (isDigit(infix[i]))
        {
            int num = 0;
            while (i < infix.length() && isDigit(infix[i]))
            {
                num = (int)infix[i] - '0';
                stack.push(num);
                i++;
            }
        }
        if (isOperation(infix[i]))
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
            case '^':
                stack.push((int)std::pow(op_a, op_b));
                break;
            case '*':
                stack.push(op_a * op_b);
                break;
            case '/':
                if (op_b == 0)
                {
                  throw std::logic_error("Attempt to divide by zero");
                }
                stack.push(op_a / op_b);
                break;
            }
        }
    }
    return stack.top();
}

bool checkBalanceBrackets(const std::string& text, size_t maxDeep)
{
    StackArray <char> brackets;
    for (size_t i = 0; i < text.size(); i++)
    {

        if ((text[i] == '(') || (text[i] == '{') || (text[i] == '['))
        {
            brackets.push(text[i]);
        }
        if (text[i] == ')')
        {
            if (brackets.top() == '(')
            {
                brackets.pop();
            }
            else
            {
                return false;
            }
        }
        if (text[i] == '}')
        {
            if (brackets.top() == '{')
            {
                brackets.pop();
            }
            else
            {
                return false;
            }
        }
        if (text[i] == ']')
        {
            if (brackets.top() == '[')
            {
                brackets.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (brackets.isEmpty())
    {
        return true;
    }
    return false;
}

bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize)
{
    char temp;
    for (size_t i = 0; i < infix.size(); i++)
    {
        temp = infix[i];
        if (temp != '(' && temp != ')' && temp != '+' && temp != '/'
            && temp != '-' && temp != '*' && temp != '^' && (temp < '0' || temp > '9'))
        {
            std::cout << "Error! Invalid parameters!\n";
            return false;
        }
    }

    postfix.clear();
    StackArray<char> stack;
    for (int i = 0; i < infix.length(); i++)
    {
        if (isDigit(infix[i])) {
            postfix += infix[i];
        }
        else if (infix[i] == '(') {
            stack.push(infix[i]);
        }
        else if (isOperation(infix[i]))
        {
            if (stack.isEmpty() || stack.top() == '(')
            {
                stack.push(infix[i]);
            }
            else {
                postfix += stack.top();
                stack.pop();
                stack.push(infix[i]);
            }
        }
        else if (infix[i] == ')') {
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
    if (postfix != "")
        return true;
    else
        return false;
}
