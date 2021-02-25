#ifndef STACK_OVERFLOW
#define STACK_OVERFLOW

#include < exception >

class StackOverflow : public std::exception
{
public:
  StackOverflow() : reason_("Stack Overflow") {}
  const char* what() const { return reason_; }
private:
  const char* reason_; 
};

#endif 
