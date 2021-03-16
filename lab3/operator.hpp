#ifndef ALGORITHMS_AND_DATA_STRUCTURE_OPERATOR_HPP
#define ALGORITHMS_AND_DATA_STRUCTURE_OPERATOR_HPP

class Operator
{
public:
  Operator();
  explicit Operator(char operand);

  [[maybe_unused]] [[nodiscard]] char getOperand() const;
  [[nodiscard]] int getPriority() const;

private:
  char operand_;
  int priority_;
};

#endif
