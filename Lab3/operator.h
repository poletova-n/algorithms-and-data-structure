#ifndef OPERATOR_H
#define OPERATOR_H

class Operator
{
public:
  Operator();
  Operator(const char& operand);

  char getOperand() const;
  int getOrder() const;

private:
  char operand_;
  int order_;
};

#endif // 
