#include <iostream>
#include <string>
#include "StackArray.h"
bool checkBalanceBrackets(const std::string& text, size_t maxDeep = 30);
int evaluatePostfix(const std::string& infix, size_t stackSize = 30);
bool getPostfix(const std::string& infix, std::string& postfix, size_t stackSize = 30);
bool testCheckBalanceBrackets();
bool isOperator(const char C);
bool isDigit(const char C);

int main()
{
	testCheckBalanceBrackets();
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
	StackArray <int> stack_test;
	stack_test.push(5);
	std::cout << stack_test.top() << std::endl;
	stack_test.push(-6);
	std::cout << stack_test.top() << std::endl;
	stack_test.push(1);
	std::cout << stack_test.top() << std::endl;
	stack_test.push(8);
	std::cout << stack_test.top() << std::endl;
	stack_test.push(0);
	std::cout << stack_test.top() << std::endl;
	stack_test.pop();
	std::cout << "delete 0\n";
	std::cout << "Copy: \n";
	StackArray<int> stack_test2(stack_test);
	std::cout << stack_test2.top() << std::endl;
	stack_test2.pop();
	std::cout << stack_test2.top() << std::endl;
	stack_test2.pop();
	std::cout << stack_test2.top() << std::endl;
	stack_test2.pop();
	std::cout << stack_test2.top() << std::endl;
	stack_test2.pop();
	return 0;
}

bool checkBalanceBrackets(const std::string& text, size_t maxDeep)
{
	StackArray <char> brackets;
	brackets.push(text[0]);
	for (size_t i = 1; i < text.length(); i++)
	{
		if (text[i] == '(' || text[i] == '{' || text[i] == '[') {
			brackets.push(text[i]);
		}
		else if (text[i] == ')') {
			if (brackets.top() == '(')
				brackets.pop();
			else
				break;
		}
		else if (text[i] == ']') {
			if (brackets.top() == '[')
				brackets.pop();
			else
				break;;
		}
		else if (text[i] == '}') {
			if (brackets.top() == '{')
				brackets.pop();
			else
				break;;
		}
	}
	if (brackets.isEmpty())
		return true;
	else
		return false;
}

bool testCheckBalanceBrackets()
{
	std::string text00 = " ";
	std::cout << text00 << ": " << (checkBalanceBrackets(text00) ? "right" : "wrong") << std::endl; 

	std::string text01 = "( )";
	std::cout << text01 << ": " << (checkBalanceBrackets(text01) ? "right" : "wrong") << std::endl; 

	std::string text02 = "( ( [] ) )";
	std::cout << text02 << ": " << (checkBalanceBrackets(text02) ? "right" : "wrong") << std::endl; 

	std::string text03 = "( ( [ { } [ ] ( [ ] ) ] ) )";
	std::cout << text03 << ": " << (checkBalanceBrackets(text03) ? "right" : "wrong") << std::endl;

	std::string text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) )";
	std::cout << text04 << ": " << (checkBalanceBrackets(text04) ? "right" : "wrong") << std::endl; 

	std::string text05 = "( ( [{ }[ ]([ ])] )";
	std::cout << text05 << ": " << (checkBalanceBrackets(text05) ? "right" : "wrong") << std::endl; 

	std::string text06 = "( ( [{ ][ ]([ ])]) )";
	std::cout << text06 << ": " << (checkBalanceBrackets(text06) ? "right" : "wrong") << std::endl; 

	return true;
}

bool isOperator(const char C)
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
				stack.push(op_a / op_b);
				break;
			}
		}
	}
	return stack.top();
}bool getPostfix(const std::string& infix, std::string& postfix, size_t stackSize)
{
	char temp;
	for (size_t i = 0; i < infix.size(); i++)
	{
		temp = infix[i];
		if (temp != '(' && temp != ')' && temp != '+' && temp != '/'
			&& temp != '-' && temp != '*' && (temp < '0' || temp > '9'))
		{
			std::cout << "Error! Invalid parameters!\n";
			return false;
		}
	}
	StackArray<char> stack;
	for (int i = 0; i < infix.length(); i++)
	{
		if (isDigit(infix[i])) {
			postfix += infix[i];
		}
		else if (infix[i] == '(') {
			stack.push(infix[i]);
		}
		else if (isOperator(infix[i]))
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