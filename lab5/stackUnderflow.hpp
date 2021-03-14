#ifndef STACKUNDERFLOW_HPP
#define STACKUNDERFLOW_HPP

#include <exception> 

class StackUnderflow : public std::exception
{
public:
  StackUnderflow() : error_("Stack Underflow") {};
  const char* getError() const
  {
    return error_;
  }

private:
  const char* error_;
};
#endif
