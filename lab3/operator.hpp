#ifndef OPERATOR_HPP
#define OPERATOR_HPP

class Operator {
public:
  explicit Operator(char operand);
  [[nodiscard]] char getOperator() const;
  [[nodiscard]] int getOrder() const;

private:
  char operand_;
  int order_;
};

#endif
