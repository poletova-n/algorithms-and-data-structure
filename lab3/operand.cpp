#include "operand.hpp"

char Operand::get_operation() {
  return operation_;
}

int Operand::get_priority() {
  return priority_;
}

Operand::Operand(char simv) {
	switch (simv)
	{
	case '(':
		priority_ = 1;
		break;
	case ')':
		priority_ = 1;
		break;
	case '-':
		priority_ = 2;
		break;
	case '+':
		priority_ = 3;
		break;
	case '/':
		priority_ = 4;
		break;
	case '*':
		priority_ = 5;
		break;
	case '^':
		priority_ = 6;
		break;
	}
}