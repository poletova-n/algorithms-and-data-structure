#ifndef EXCEPTIONARRAY_HPP
#define EXCEPTIONARRAY_HPP

#include <iostream>
#include <exception>

class ArrayUnderflow
  : public std::exception
{
  public:
  ArrayUnderflow() : reason_("Array Underflow")
  {}

  const char *what() const noexcept override
  { return reason_.c_str(); }

  private:
  std::string reason_;
};
#endif
