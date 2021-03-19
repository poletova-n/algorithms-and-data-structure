#ifndef OPERATOR_HPP
#define OPERATOR_HPP

class Operator
{
public:
  Operator();
  Operator(const char& operand);

  char getOperand() const;
  int getPriority() const;

private:
  char operand_;
  int priority_;
};

#endif