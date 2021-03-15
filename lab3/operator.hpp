#ifndef LAB3_OPERATOR_HPP
#define LAB3_OPERATOR_HPP

class Object
{
public:
  Object(char data);
  int getPriority();

private:
  int priority;
};
#endif
