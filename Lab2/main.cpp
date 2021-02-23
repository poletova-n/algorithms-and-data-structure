#include"stackArray.h"
#include"stackLinkedList.h"

bool balanceStackArray(const char*);
bool balanceStackLinkedList(const char*);
bool testCheckBalanceBrackets(const char*, bool(*selectTypeStack)(const char*));

int main()
{
	const char* text1 = " ok ";
	std::cout << "Check text 1(right): " << (testCheckBalanceBrackets(text1, balanceStackArray) ? "true" : "false") << '\n';
	const char* text2 = "{ ( ) [ ( ) [ ] ( [ { } ] ) ] } ok ";
	std::cout << "Check text 2(right): " << (testCheckBalanceBrackets(text2, balanceStackArray) ? "true" : "false") << '\n';
	const char* text3 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis";
	std::cout << "Check text 3(wrong): " << (testCheckBalanceBrackets(text3, balanceStackArray) ? "true" : "false") << '\n';
	const char* text4 = "( ( [{ }[ ]([ ])] ) extra left parenthesis";
	std::cout << "Check text 4(wrong): " << (testCheckBalanceBrackets(text4, balanceStackArray) ? "true" : "false") << '\n';
	const char* text5 = " ok ()";
	std::cout << "Check text 5(right): " << (testCheckBalanceBrackets(text5, balanceStackLinkedList) ? "true" : "false") << '\n';
	const char* text6 = "{ ( ) [ ( ) [ ] ( [ { } ] ) ] } ok ";
	std::cout << "Check text 6(right): " << (testCheckBalanceBrackets(text6, balanceStackLinkedList) ? "true" : "false") << '\n';
	const char* text7 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis";
	std::cout << "Check text 7(wrong): " << (testCheckBalanceBrackets(text7, balanceStackLinkedList) ? "true" : "false") << '\n';
	const char* text8 = "( ( [{ }[ ]([ ])] ) extra left parenthesis";
	std::cout << "Check text 8(wrong): " << (testCheckBalanceBrackets(text8, balanceStackLinkedList) ? "true" : "false") << '\n';

	return 0;
}

bool balanceStackArray(const char* text)
{
	size_t sizeText = 0;
	for (int i = 0; text[i] != '\0'; ++i)
	{
		++sizeText;
	}
	size_t sizeStack = sizeText / 2;
	Stack<char>* stack = new StackArray<char>(sizeStack);
	for (size_t i = 0; i < sizeText; ++i)
	{
		if (text[i] == '(' || text[i] == '{' || text[i] == '[')
		{
			try
			{
				char e = text[i];
				stack->push(e);
			}
			catch (StackOverflow& exp)
			{
				std::cout << exp.what() << '\n';
			}
		}
		if (text[i] == ')')
		{
			char c;
			try
			{
				if (stack->isEmpty())
				{
					return 0;
				}
				c = stack->pop();
			}
			catch (StackUnderflow& exp)
			{
				std::cout << exp.what() << '\n';
				return 0;
			}
			if (c != '(')
			{
				return 0;
			}
		}
		if (text[i] == '}')
		{
			char c;
			try
			{
				if (stack->isEmpty())
				{
					return 0;
				}
				c = stack->pop();
			}
			catch (StackUnderflow& exp)
			{
				std::cout << exp.what() << '\n';
				return 0;
			}
			if (c != '{')
			{
				return 0;
			}
		}
		if (text[i] == ']')
		{
			char c;
			try
			{
				if (stack->isEmpty())
				{
					return 0;
				}
				c = stack->pop();
			}
			catch (StackUnderflow& exp)
			{
				std::cout << exp.what() << '\n';
				return 0;
			}
			if (c != '[')
			{
				return 0;
			}
		}
	}
	if (!stack->isEmpty())
	{
		return 0;
	}
	return 1;
}
bool balanceStackLinkedList(const char* text)
{
	size_t sizeText = 0;
	for (int i = 0; text[i] != '\0'; ++i)
	{
		++sizeText;
	}
	Stack<char>* stack = new StackLinkedList<char>;
	for (size_t i = 0; i < sizeText; ++i)
	{
		if (text[i] == '(' || text[i] == '{' || text[i] == '[')
		{
			try
			{
				char e = text[i];
				stack->push(e);
			}
			catch (StackOverflow& exp)
			{
				std::cout << exp.what() << '\n';
			}
		}
		if (text[i] == ')')
		{
			char c;
			try
			{
				if (stack->isEmpty())
				{
					return 0;
				}
				c = stack->pop();
			}
			catch (StackUnderflow& exp)
			{
				std::cout << exp.what() << '\n';
				return 0;
			}
			if (c != '(')
			{
				return 0;
			}
		}
		if (text[i] == '}')
		{
			char c;
			try
			{
				if (stack->isEmpty())
				{
					return 0;
				}
				c = stack->pop();
			}
			catch (StackUnderflow& exp)
			{
				std::cout << exp.what() << '\n';
				return 0;
			}
			if (c != '{')
			{
				return 0;
			}
		}
		if (text[i] == ']')
		{
			char c;
			try
			{
				if (stack->isEmpty())
				{
					return 0;
				}
				c = stack->pop();
			}
			catch (StackUnderflow& exp)
			{
				std::cout << exp.what() << '\n';
				return 0;
			}
			if (c != '[')
			{
				return 0;
			}
		}
	}
	if (!stack->isEmpty())
	{
		return 0;
	}
	return 1;
}
bool testCheckBalanceBrackets(const char* text, bool(*selectTypeStack)(const char*))
{
	return selectTypeStack(text);
}
