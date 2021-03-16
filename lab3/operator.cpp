#include "operator.h"

Operator::Operator() :
        priority_(0),
        operation_('\0')
{}

void Operator::setOperation(char operation)
{
  if ((operation == '+') || (operation == '-'))
  {
    operation_ = operation;
    priority_ = 1;
  }
  if ((operation == '*') || (operation == '/'))
  {
    operation_ = operation;
    priority_ = 2;
  }
  if (operation == '^')
  {
    operation_ = operation;
    priority_ = 3;
  }
}

char Operator::getOperation()
{
  return operation_;
}


int Operator::getPriority()
{
  return priority_;
}