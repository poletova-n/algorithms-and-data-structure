#ifndef WORKING_STACKUNDERFLOW_HPP
#define WORKING_STACKUNDERFLOW_HPP

#include <exception>

class StackUnderflow: public std::exception
{
public:
  StackUnderflow():
    exceptionName("Stack Underflow!") {}
  const char* what() const noexcept override { return exceptionName; }

private:
  const char* exceptionName;
};

#endif
