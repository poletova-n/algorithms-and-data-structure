#include <iostream>

#include "stackArray.h"
#include "stackList.h"


bool checkBalanceBrackets(const std::string& text, Stack<char>* tempStack);
int main()
{
	try
	{
		StackArray<char> stackArray;
		std::cout << "Run checkBalanceBrackets() on StackArray\n";
		std::string text0 = " ok ";
		std::cout << text0 << ": " << (checkBalanceBrackets(text0, &stackArray) ? "right" : "wrong") << std::endl;
		std::string text1 = "( ) ok ";
		std::cout << text1 << ": " << (checkBalanceBrackets(text1, &stackArray) ? "right" : "wrong") << std::endl;
		std::string text2 = "( ( [] ) ) ok ";
		std::cout << text2 << ": " << (checkBalanceBrackets(text2, &stackArray) ? "right" : "wrong") << std::endl;
		std::string text3 = "( ( [ { } [ ] ( [ ] ) ] ) ) ok ";
		std::cout << text3 << ": " << (checkBalanceBrackets(text3, &stackArray) ? "right" : "wrong") << std::endl;
		std::string text4 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis";
		std::cout << text4 << ": " << (checkBalanceBrackets(text4, &stackArray) ? "right" : "wrong") << std::endl;
		std::string text5 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
		std::cout << text5 << ": " << (checkBalanceBrackets(text5, &stackArray) ? "right" : "wrong") << std::endl;
		std::string text6 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
		std::cout << text6 << ": " << (checkBalanceBrackets(text6, &stackArray) ? "right" : "wrong") << std::endl;
	}
	catch (StackOverFlow)
	{
		std::cerr << StackOverFlow().what();
	}
	try
	{
		StackList<char> stackList;
		std::cout << "\nRun checkBalanceBrackets() on StackList\n";
		std::string text0 = " ok ";
		std::cout << text0 << ": " << (checkBalanceBrackets(text0, &stackList) ? "right" : "wrong") << std::endl;
		std::string text1 = "( ) ok ";
		std::cout << text1 << ": " << (checkBalanceBrackets(text1, &stackList) ? "right" : "wrong") << std::endl;
		std::string text2 = "( ( [] ) ) ok ";
		std::cout << text2 << ": " << (checkBalanceBrackets(text2, &stackList) ? "right" : "wrong") << std::endl;
		std::string text3 = "( ( [ { } [ ] ( [ ] ) ] ) ) ok ";
		std::cout << text3 << ": " << (checkBalanceBrackets(text3, &stackList) ? "right" : "wrong") << std::endl;
		std::string text4 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis";
		std::cout << text4 << ": " << (checkBalanceBrackets(text4, &stackList) ? "right" : "wrong") << std::endl;
		std::string text5 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
		std::cout << text5 << ": " << (checkBalanceBrackets(text5, &stackList) ? "right" : "wrong") << std::endl;
		std::string text6 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
		std::cout << text6 << ": " << (checkBalanceBrackets(text6, &stackList) ? "right" : "wrong") << std::endl;
	}
	catch (StackOverFlow)
	{
		std::cerr << StackOverFlow().what();
	}
	return 0;
}

bool checkBalanceBrackets(const std::string& text, Stack<char>* tempStack)
{
	int tempCountOpenBrackets = 0;
	for (int i = 0; text[i] != '\0'; i++)
	{
		if ((text[i] == '(') || (text[i] == '{') || (text[i] == '[') || (text[i] == ')') || (text[i] == '}') || (text[i] == ']'))
		{
			if ((text[i] == '(') || (text[i] == '{') || (text[i] == '['))
			{
				tempStack->push(text[i]);
				tempCountOpenBrackets += 1;
			}
			else
			{
				try
				{
					char temp = tempStack->pop();
					if ((temp == '[') && (text[i] != ']'))
					{
						return false;
					}
					if ((temp == '{') && (text[i] != '}'))
					{
						return false;
					}
					if ((temp == '(') && (text[i] != ')'))
					{
						return false;
					}
					tempCountOpenBrackets -= 1;
				}
				catch (StackUnderFlow)
				{
					return false;
				}
			}
		}
	}
	if (tempCountOpenBrackets != 0)
	{
		return false;
	}
	return true;
}