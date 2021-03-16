#ifndef STACK3_OPERATOR_H
#define STACK3_OPERATOR_H

class Operator
{
public:
  Operator();
  void setOperation(char operation);
  char getOperation();
  int getPriority();
private:
  int priority_;
  char operation_;
};

#endif