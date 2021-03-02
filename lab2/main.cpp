#include "stackArray.h"
#include "stackList.h"

#include <iostream>

void TestBalanceBrackets();
bool isBalanceBrackets(const char* text, bool isArray = false);
bool testBalanceBracketsList(const char* text);
bool testBalanceBracketsArray(const char* text, int maxDeep);

int main()
{
  std::cout << "Are parentheses in stack balanced?\n";
  TestBalanceBrackets();
  return 0;
}

void TestBalanceBrackets()
{
  const char* text00 = "START";
  std::cout << text00 << ": " << (isBalanceBrackets(text00, true) ? "YES" : "NO") << "\n";
  const char* text01 = "( TEST )";
  std::cout << text01 << ": " << (isBalanceBrackets(text01) ? "YES" : "NO") << "\n";
  const char* text02 = "( ( [] ) )  ";
  std::cout << text02 << ": " << (isBalanceBrackets(text02, true) ? "YES" : "NO") << "\n";
  const char* text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) ";
  std::cout << text03 << ": " << (isBalanceBrackets(text03) ? "YES" : "NO") << "\n";
  const char* text04 = "Extra right parentheses ( ( [ { } [ ] ( [ ] ) ] ) ) ) ";
  std::cout << text04 << ": " << (isBalanceBrackets(text04, true) ? "YES" : "NO") << "\n";
  const char* text05 = "Extra left parentheses  ( ( [{ }[ ]([ ])] )";
  std::cout << text05 << ": " << (isBalanceBrackets(text05) ? "YES" : "NO") << "\n";
  const char* text06 = "Unpaired parentheses ( ( [{ ][ ]([ ])]) ) ";
  std::cout << text06 << ": " << (isBalanceBrackets(text06) ? "YES" : "NO") << "\n";
}

bool isBalanceBrackets( const char* text, bool isArray )
{
  if (isArray)
  {
	return testBalanceBracketsArray( text, 30);
  }
  else
  {
	return testBalanceBracketsList(text);
  }
}

bool testBalanceBracketsArray(const char* text, const int maxDeep)
{
	Stack <char>* stack = new StackArray<char>(maxDeep);
	bool isBalanceBrackets = true;
	try {
		char cText = '\0'; 
			for (int i = 0; ((cText = text[i]) != '\0') && (isBalanceBrackets == true); i++) 
			{
			switch (cText) {
			case '(': case '[': case '{':
				stack->push(cText); 
				break;
			case ')':
					if (stack->pop() != '(') {
						isBalanceBrackets = false;
					}
				break;
			case ']':
				if (stack->pop() != '[') {
					isBalanceBrackets = false;
				}
				break;
			case '}':
				if (stack->pop() != '{') {
					isBalanceBrackets = false;
				}
				break;
			}
		}
			isBalanceBrackets = isBalanceBrackets && stack->isEmpty();
	}

	catch (StackUnderflow) {
		isBalanceBrackets = false; 
	}
	catch (StackOverflow) {
		isBalanceBrackets = false;
	}

	delete stack;
	return isBalanceBrackets;
}

bool testBalanceBracketsList(const char* text)
{

  Stack <char> *stack = new StackList <char>;
  bool isBalanceBrackets = true; 
  try {
	char cText = '\0';
	for (int i = 0; ((cText = text[i]) != '\0') && (isBalanceBrackets == true); i++) 
	{
	  switch (cText) 
	  {
	  case '(': case '[': case '{':
		stack->push(cText); 
		break;
	  case ')':
		if (stack->pop() != '(') {
		  isBalanceBrackets = false;
		}
		break;
	  case ']':
		if (stack->pop() != '[') {
		  isBalanceBrackets = false;
		}
		break;
	  case '}':
		if (stack->pop() != '{') {
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
