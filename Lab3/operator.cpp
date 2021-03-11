#include "operator.h"

Operator::Operator():
		operand_(),
		order_(-1)
{}

Operator::Operator(const char& operand):
  operand_(operand),
  order_(-1)
{
		switch (operand)
		{
				case '(':
						order_ = 0;
						break;
				case ')':
						order_ = 1;
						break;
				case '+':
						order_ = 2;
						break;
				case '-':
						order_ = 2;
						break;
				case '*':
						order_ = 3;
						break;
				case '/':
						order_ = 3;
						break;
				case '^':
						order_ = 4;
						break;

				default:
						break;
		}
}

char Operator::getOperand() const
{
		return operand_;
}

int Operator::getOrder() const
{
		return order_;
}
