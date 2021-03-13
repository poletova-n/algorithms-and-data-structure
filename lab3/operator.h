#ifndef STACKS_OPERATOR_H
#define STACKS_OPERATOR_H
class Operator
{
public:
  Operator(char oper);
  int getPriority();
  char getOperand();

private:
  char operand;
  int priority;
};

Operator::Operator(char oper) {
  operand = oper;
  if(oper == '^')
    priority = 4;
  if(oper == '*')
    priority = 3;
  if(oper == '/')
    priority = 3;
  if(oper == '+')
    priority = 2;
  if(oper == '-')
    priority = 2;
  if(oper == '(')
    priority = 0;
  if(oper == ')')
    priority = 1;
}

int Operator::getPriority() {
  return priority;
}

char Operator::getOperand() {
  return operand;
}

#endif //STACKS_OPERATOR_H
