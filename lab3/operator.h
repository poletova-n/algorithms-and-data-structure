#ifndef OPERATOR_H
#define OPERATOP_H

class Operator
{
public:
	Operator(char opr):
		operator_(opr),
		priority_(0)
	{
		if (opr == '^') priority_ = 1;
		if (opr == '*' || opr == '/') priority_ = 2;
		if (opr == '+' || opr == '-') priority_ = 3;
		if (opr == '(' || opr == ')') priority_ = 4;

	}
	~Operator() {}

	char getOperator();

	int getPriority();
private:
	char operator_;
	int priority_;
};

#endif
