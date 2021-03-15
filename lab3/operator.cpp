#include "operator.hpp"

Object::Object(char data)
{
  switch (data)
  {
    case '(':
      priority = 1;
      break;
    case ')':
      priority = 1;
      break;
    case '+':
      priority = 2;
      break;
    case '-':
      priority = 2;
      break;
    case '*':
      priority = 3;
      break;
    case '/':
      priority = 3;
      break;
    case '^':
      priority = 4;
      break;
  }
}

int Object::getPriority()
{
  return priority;
}
