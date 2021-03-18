#include <iostream>
#include <regex>
#include "stack.h"
#include "stackArray.h"
#include "stackOverflow.h"
#include "stackUnderflow.h"
#include "wrongStackSize.h"

bool testBalanceBrackets(const char *text, int maxDeep = 30);

int main()
{
  const char *text00 = " ok ";
  std::cout << text00 << ": "
            << (testBalanceBrackets(text00, flag) ? "right" : "wrong") << '\n';

  const char *text01 = "( ) ok ";
  std::cout << text01 << ": "
            << (testBalanceBrackets(text01, flag) ? "right" : "wrong") << '\n';

  const char *text02 = "( ( [] ) ) ok ";
  std::cout << text02 << ": "
            << (testBalanceBrackets(text02, flag) ? "right" : "wrong") << '\n';

  const char *text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) OK";
  std::cout << text03 << ": "
            << (testBalanceBrackets(text03, flag) ? "right" : "wrong") << '\n';

  const char *text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
  std::cout << text04 << ": "
            << (testBalanceBrackets(text04, flag) ? "right" : "wrong") << '\n';

  const char *text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
  std::cout << text05 << ": "
            << (testBalanceBrackets(text05, flag) ? "right" : "wrong") << '\n';

  const char *text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
  std::cout << text06 << ": "
            << (testBalanceBrackets(text06, flag) ? "right" : "wrong") << '\n';
 return 0;
}

bool testBalanceBrackets(const char *text, int maxDeep) {
  Stack<char> *stack = new StackArray<char>(maxDeep);

  bool isBalanceBrackets = true;
  try
     {
    char cText = '\0';

    for (int i = 0; ((cText = text[i]) != '\0') && isBalanceBrackets; i++) {
      switch (cText) {
      case '(':
      case '[':
      case '{':
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
  } catch (StackUnderflow &) {
    isBalanceBrackets = false;
  } catch (StackOverflow &) {
    isBalanceBrackets = false;
  }

  delete stack;
  return isBalanceBrackets;
}
