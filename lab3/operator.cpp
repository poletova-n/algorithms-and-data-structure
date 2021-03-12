#include "operator.hpp"

Operator::Operator(char operand):
  operand_(operand),
  order_(-1)
{
  switch (operand_) {
    case '(':
      order_ = 0;
      break;
    case ')':
      order_ = 0;
      break;
    case '^':
      order_ = 1;
      break;
    case '*':
      order_ = 2;
      break;
    case '/':
      order_ = 2;
      break;
    case '+':
      order_ = 3;
      break;
    case '-':
      order_ = 3;
      break;
  }
}

char Operator::getOperator() const
{
  return operand_;
}

int Operator::getOrder() const
{
  return order_;
}
