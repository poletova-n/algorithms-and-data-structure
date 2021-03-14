#ifndef STACKUNDERFLOW_H
#define STACKUNDERFLOW_H

#include <exception>

class StackUnderflow: public std::exception
{
public:
  StackUnderflow():reason("Stack Underflow") {}
  const char* what() {return reason;}
private:
  const char* reason;
};

#endif