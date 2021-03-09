#include "operator.h"
#include "stackArray.h"

#include <string> 


//function to test parentheses
bool checkParentheses(const std::string&);

//function to test infix expressions
bool testText(const std::string&);

//function to convert infix expressions to postfix
std::string convertInfixToPostfix(const std::string&);

//function to compute the postfix expression
int calculateValueExpresPostfix(const std::string&);

int main()
{
	std::cout << "========Error Cases========\n";
	try
	{
		std::string str1 = "((3+4-2)/5";
		std::cout << "Expression ((3+4-2)/5 " << calculateValueExpresPostfix(convertInfixToPostfix(str1)) << '\n';
	}
	catch (const std::exception& exp)
	{
		std::cerr << exp.what() << '\n';
	}
	try
	{
		std::string str2 = "3+-4+1";
		std::cout << "Expression 3+-4+1 " << calculateValueExpresPostfix(convertInfixToPostfix(str2)) << '\n';
	}
	catch (const std::exception& exp)
	{
		std::cerr << exp.what() << '\n';
	}
	try
	{
		std::string str3 = "(5%2+4)";
		std::cout << "Expression (5&2+4) " << calculateValueExpresPostfix(convertInfixToPostfix(str3)) << '\n';
	}
	catch (const std::exception& exp)
	{
		std::cerr << exp.what() << '\n';
	}
	std::cout << "===========================\n";
	try
	{
		std::string strInfix1 = "(3+4*2-2)-(9-8*3/4+4)/7";
		std::cout << strInfix1 << '\n';
		std::cout << "Value of Infix expression: " << (3 + 4 * 2 - 2) - (9 - 8 * 3 / 4 + 4) / 7 << '\n';
		
		std::string strPostfiz1 = convertInfixToPostfix(strInfix1);
		std::cout << strPostfiz1 << '\n';
		std::cout << "Value of Postfix expression: " << calculateValueExpresPostfix(strPostfiz1) << '\n';

	}
	catch (const std::exception& exp)
	{
		std::cerr << exp.what() << '\n';
	}
	return 0;
}

bool checkParentheses(const std::string& text)
{
	size_t sizeText = text.length();
	size_t sizeStack = sizeText / 2;
	StackArray<char> stack(sizeStack);
	try
	{
		for (size_t i = 0; i < sizeText; ++i)
		{
			if (text[i] == '(')
			{
				char e = text[i];
				stack.push(e);
			}
			if (text[i] == ')')
			{
				if (stack.isEmpty())
				{
					return 0;
				}
				char c = stack.pop();
				if (c != '(')
				{
					return 0;
				}
			}
		}
		if (!stack.isEmpty())
		{
			return 0;
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << exp.what() << '\n';
	}
	return 1;
}

bool testText(const std::string& text)
{
	size_t lengthStr = text.length();
	for (size_t i = 0; i < lengthStr; i++)
	{
		char c = text[i];
		if (c != ')' && c != '(' && c != '+' && c != '-' && c != '*' && c != '/' && c != '^' && (c < '0' || c>'9'))
		{
			return 0;
		}
		if (text[i] == '+' || text[i] == '-' || text[i] == '*' || text[i] == '/' || text[i] == '^')
		{
			if (i != lengthStr - 1)
			{
				if (text[i + 1] == '+' || text[i + 1] == '-' || text[i + 1] == '*' || text[i + 1] == '/' || text[i + 1] == '^')
				{
					return 0;
				}
			}
		}
		if (text[i] >= '0' && text[i] <= '9')
		{
			if (i != lengthStr - 1)
			{
				if (text[i + 1] >= '0' && text[i + 1] <= '9')
				{
					return 0;
				}
			}
		}
	}
	if (checkParentheses(text) == 0)
	{
		return 0;
	}
	return 1;
}

std::string convertInfixToPostfix(const std::string& str)
{
	if (testText(str) == 0)
	{
		throw std::invalid_argument("Arithmetic expression did not satisfy the problem requirement.");
	}
	StackArray<char> stackOprator(50);
	std::string balanExpression;
	size_t length = str.length();
	try
	{
		for (size_t i = 0; i < length; i++)
		{
			char c = str[i];
			if (c >= '0' && c <= '9')
			{
				balanExpression.push_back(str[i]);
			}
			else
			{
				Operator opr(str[i]);
				if (c == '(')
				{
					stackOprator.push(c);
				}
				if (c == ')')
				{
					bool isCharacterParentheses = false;
					for (int i = 0; (i < stackOprator.lengthStack()) && (isCharacterParentheses == false); i++)
					{
						char temp = stackOprator.pop();
						if (temp == '(')
						{
							isCharacterParentheses = true;
						}
						else
						{
							balanExpression.push_back(temp);
						}
					}
				}
				if (c == '^')
				{
					if (stackOprator.isEmpty() == 0)
					{
						if (stackOprator.getTop() == '^')
						{
							balanExpression.push_back(stackOprator.pop());
						}
					}
					stackOprator.push(c);
				}
				if (c == '*' || c == '/')
				{
					if (stackOprator.isEmpty() == 0)
					{
						bool breakWhile = false;
						while (breakWhile == false)
						{
							if (stackOprator.isEmpty() == 0)
							{
								Operator oprTop(stackOprator.getTop());
								if (opr.getPriority() >= oprTop.getPriority())
								{
									balanExpression.push_back(stackOprator.pop());
								}
								else
								{
									breakWhile = true;
								}
							}
							else
							{
								breakWhile = true;
							}
						}
					}
					stackOprator.push(c);
				}
				if (c == '+' || c == '-')
				{
					if (stackOprator.isEmpty() == 0)
					{
						bool breakWhile = false;
						while (breakWhile == false)
						{
							if (stackOprator.isEmpty() == 0)
							{
								Operator oprTop(stackOprator.getTop());
								if (opr.getPriority() >= oprTop.getPriority())
								{
									char top = stackOprator.pop();
									balanExpression.push_back(top);
								}
								else
								{
									breakWhile = true;
								}
							}
							else
							{
								breakWhile = true;
							}
						}
					}
					stackOprator.push(c);
				}
			}
		}
		while (stackOprator.isEmpty() == 0)
		{
			if (stackOprator.getTop() == '(')
			{
				stackOprator.pop();
			}
			else
			{
				balanExpression.push_back(stackOprator.pop());
			}
		}
	}
	catch (const std::exception& exp)
	{
		std::cerr << exp.what() << '\n';
	}
	return balanExpression;
}

int calculateValueExpresPostfix(const std::string& str)
{
	StackArray<int> stack(50);
	try
	{
		for (size_t i = 0; i < str.length(); i++)
		{
			if (str[i] <= '9' && str[i] >= '0')
			{
				int temp = str[i] - '0';
				stack.push(temp);
			}
			else
			{
				if (str[i] == '+')
				{
					int b = stack.pop();
					int a = stack.pop();
					int temp = a + b;
					stack.push(temp);
				}
				if (str[i] == '-')
				{
					int b = stack.pop();
					int a = stack.pop();
					int temp = (a - b);
					stack.push(temp);
				}
				if (str[i] == '/')
				{
					int b = stack.pop();
					if (b == 0)
					{
						throw std::logic_error("The denominator of division cannot be 0.");
					}
					int a = stack.pop();
					int temp = (a / b);
					stack.push(temp);
				}
				if (str[i] == '*')
				{
					int b = stack.pop();
					int a = stack.pop();
					int temp = (a * b);
					stack.push(temp);
				}
			}
		}
	}
	catch (const std::exception& exp)
	{
		std::cout << exp.what() << '\n';
	}
	return stack.pop();
}
