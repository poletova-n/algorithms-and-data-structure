#ifndef OPERAND_HPP
#define OPERAND_HPP

class Operand
{
public:
  Operand(char simv);
  int get_priority();
  char get_operation();
private:
  char operation_;
  int priority_;
};

#endif