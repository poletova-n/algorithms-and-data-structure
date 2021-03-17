#include <iostream>
#include <string>
#include "stackArray.h"

bool checkBalanceBrackets(const std::string& text, int maxDeep = 30);
bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize = 30);
int evaluatePostfix(const std::string& postfix, size_t stackSize = 30);

int main()
{
    const std::string text00 = " ok ";
    std::cout << text00 << ": " << (checkBalanceBrackets(text00) ? "right" : "wrong") << '\n';
    const std::string text01 = "( ) ok ";
    std::cout << text01 << ": " << (checkBalanceBrackets(text01) ? "right" : "wrong") << '\n';
    const std::string text02 = "( ( [] ) ) ok ";
    std::cout << text02 << ": " << (checkBalanceBrackets(text02) ? "right" : "wrong") << '\n';
    const std::string text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) OK";
    std::cout << text03 << ": " << (checkBalanceBrackets(text03) ? "right" : "wrong") << '\n';
    const std::string text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
    std::cout << text04 << ": " << (checkBalanceBrackets(text04) ? "right" : "wrong") << '\n';
    const std::string text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
    std::cout << text05 << ": " << (checkBalanceBrackets(text05) ? "right" : "wrong") << '\n';
    const std::string text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
    std::cout << text06 << ": " << (checkBalanceBrackets(text06) ? "right" : "wrong") << '\n';
    std::string txt1 = "(4-1)*6-8";
    std::string txt2(txt1.length(),' ');
    getPostfixFromInfix(txt1, txt2, 30);
    std::cout << "infix-form string:  " <<txt1 <<"    prefix-form string:   " << txt2 << '\n';
    std::cout << "Value of expression:  " <<evaluatePostfix(txt2, 30) << '\n';
    std::string txt3 = "((5+7)/4+5)/8*2";
    std::string txt4(txt3.length(), ' ');
    getPostfixFromInfix(txt3, txt4, 30);
    std::cout << "infix-form string:  " << txt3 << "    prefix-form string:   " << txt4 << '\n';
    std::cout << "Value of expression:  " << evaluatePostfix(txt4, 30) << '\n';
    std::string txt5 = "6/0+3-5";
    std::string txt6(txt5.length(), ' ');
    getPostfixFromInfix(txt5, txt6, 30);
    std::cout << "infix-form string:  " << txt5 << "    prefix-form string:   " << txt6 << '\n';
    std::cout << "Value of expression:  " << evaluatePostfix(txt6, 30) << '\n';
    std::string txt7 = "(5*6-9)/3+2";
    std::string txt8(txt7.length(), ' ');
    getPostfixFromInfix(txt7, txt8, 30);
    std::cout << "infix-form string:  " << txt7 << "    prefix-form string:   " << txt8 << '\n';
    std::cout << "Value of expression:  " << evaluatePostfix(txt8, 30) << '\n';
    return 0;
}

bool checkBalanceBrackets(const std::string& text, int maxDeep)
{
    StackArray<char> stack(maxDeep);
    for (size_t i = 0; i < text.size(); i++)
    {
        if ((text[i] == '(') || (text[i] == '{') || (text[i] == '['))
        {
            stack.push(text[i]);
            continue;
        }
        if (text[i] == ')')
        {
            if (stack.getTop() == '(')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        if (text[i] == '}')
        {
            if (stack.getTop() == '{')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
        if (text[i] == ']')
        {
            if (stack.getTop() == '[')
            {
                stack.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (stack.isEmpty())
    {
        return true;
    }
    else return false;
}


bool getPostfixFromInfix(const std::string& infix, std::string& postfix, size_t stackSize)
{
    StackArray<char> stack(stackSize);
    StackArray<char> stackPostfix(stackSize);
    checkBalanceBrackets(infix);
    for (size_t i = 0; i < infix.size(); i++)
    {
        if (infix[i] == '(')
        {
            stack.push(infix[i]);
        }
        else if (infix[i] == ')')
        {
            while (stack.getTop() != '(')
            {
                stackPostfix.push(stack.pop());
            }
            stack.pop();
        }
        else if (((infix[i] == '+') || (infix[i] == '-') || (infix[i] == '*') || (infix[i] == '/')) && ((stack.isEmpty()) || (stack.getTop() == '(')))
        {
            stack.push(infix[i]);
        }
        else if (((infix[i] == '*') || (infix[i] == '/')) && ((stack.getTop() == '*') || (stack.getTop() == '/')))
        {
            stackPostfix.push(stack.pop());
            stack.push(infix[i]);
        }
        else if (((stack.getTop() == '+') || (stack.getTop() == '-')) && ((infix[i] == '*') || (infix[i] == '/')))
        {
            stack.push(infix[i]);
        }
        else if ((infix[i] == '+') || (infix[i] == '-'))
        {
            while ((stack.isEmpty() == 0) && (stack.getTop() != '('))
            {
                stackPostfix.push(stack.pop());
            }
            stack.push(infix[i]);
        }
        else if ((infix[i] >= '0') && (infix[i] <= '9'))
        {
            stackPostfix.push(infix[i]);
        }
    }
    int i = stackPostfix.getSize();
    int size = i;
    stackPostfix.push(stack.pop());
    while (stackPostfix.isEmpty() == 0)
    {
        postfix[i--] = stackPostfix.pop();
    }
    postfix.resize(size+1);
    return 1;
}


int evaluatePostfix(const std::string& postfix, size_t stackSize)
{
    StackArray<char> stack(stackSize);
    int out = 0, temp1 = 0, temp2 = 0;
    for (int i=0;i<postfix.size();i++)
    {
        if ((postfix[i] >= '0') && (postfix[i] <= '9'))
        {
            stack.push(postfix[i] - '0');
        }
        if (postfix[i] == '+')
        {
            temp2 = stack.pop();
            temp1 = stack.pop();
            out = temp1 + temp2;
            stack.push(out);
        }
        if (postfix[i] == '-')
        {
            temp2 = stack.pop();
            temp1 = stack.pop();
            out = temp1 - temp2;
            stack.push(out);
        }
        if (postfix[i] == '*')
        {
            temp2 = stack.pop();
            temp1 = stack.pop();
            out = temp1 * temp2;
            stack.push(out);
        }
        if (postfix[i] == '/')
        {
            temp2 = stack.pop();
            temp1 = stack.pop();
            if (temp2 == 0.0)
            {
              throw ("You can't divide by zero\n");
            }
            out = temp1 / temp2;
            stack.push(out);
        }
    }
    out = stack.pop();
    return out;
}
