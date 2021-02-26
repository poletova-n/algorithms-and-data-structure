#include <iostream>
#include "stackarray.hpp"
#include "stacklist.hpp"

bool testByArray = 1;

bool testBalanceBracketsByArray(const char* text, int maxDeep = 30)
{
    StackArray<char>* stack = new StackArray<char>(maxDeep);
    bool isBalanceBrackets = true;
    try {
        char cText = '\0';
        for (int i = 0; ((cText = text[i]) != '\0') && (isBalanceBrackets == true); i++) {
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

bool testBalanceBracketsByList(const char* text, int maxDeep = 30)
{
  StackList<char> stack;
  bool isBalanceBrackets = true;
  try {
    char cText = '\0';
    for (int i = 0; ((cText = text[i]) != '\0') && (isBalanceBrackets == true); i++) {
      switch (cText) {
        case '(': case '[': case '{':
          stack.push(cText);
          break;
        case ')':
          if (stack.pop() != '(') {
            isBalanceBrackets = false;
          }
          break;
        case ']':
          if (stack.pop() != '[') {
            isBalanceBrackets = false;
          }
          break;
        case '}':
          if (stack.pop() != '{') {
            isBalanceBrackets = false;
          }
          break;
      }
    }
    isBalanceBrackets = isBalanceBrackets && stack.isEmpty();
  }
  catch (StackUnderflow) {
    isBalanceBrackets = false;
  }
  catch (StackOverflow) {
    isBalanceBrackets = false;
  }
  return isBalanceBrackets;
}

bool testBalanceBrackets(const char* text, int maxDeep = 30)
{
  if (testByArray == 0)
  {
    return testBalanceBracketsByArray(text, maxDeep);
  }
  else
  {
    return testBalanceBracketsByList(text, maxDeep);
  }
}

int main()
{
  if (testByArray == 0)
    std::cout << "Test balance brackets by array\n";
  else
    std::cout << "Test balance brackets by list\n";

  const char* text00 = " ok ";
  std::cout << text00 << ": " << (testBalanceBrackets(text00) ? "right" : "wrong") << std::endl;
  const char* text01 = "( ) ok ";
  std::cout << text01 << ": " << (testBalanceBrackets(text01) ? "right" : "wrong") << std::endl;
  const char* text02 = "( ( [] ) ) ok ";
  std::cout << text02 << ": " << (testBalanceBrackets(text02) ? "right" : "wrong") << std::endl;
  const char* text03 = "( ( [ { } [ ] ( [ ] ) ] ) ) OK";
  std::cout << text03 << ": " << (testBalanceBrackets(text03) ? "right" : "wrong") << std::endl;
  const char* text04 = "( ( [ { } [ ] ( [ ] ) ] ) ) ) extra right parenthesis ";
  std::cout << text04 << ": " << (testBalanceBrackets(text04) ? "right" : "wrong") << std::endl;
  const char* text05 = "( ( [{ }[ ]([ ])] ) extra left parenthesis ";
  std::cout << text05 << ": " << (testBalanceBrackets(text05) ? "right" : "wrong") << std::endl;
  const char* text06 = "( ( [{ ][ ]([ ])]) ) unpaired bracket ";
  std::cout << text06 << ": " << (testBalanceBrackets(text06) ? "right" : "wrong") << std::endl;

  return 0;
}


