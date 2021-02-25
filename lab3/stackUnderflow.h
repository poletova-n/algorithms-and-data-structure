#ifndef STACK_UNDERFLOW
#define STACK_UNDERFLOW

#include <exception>

class StackUnderflow : public std::exception
{
public:
  StackUnderflow() : reason_("Stack Underflow") {}
  const char* what() const { return reason_; }
private:
  const char* reason_;
};

#endif
