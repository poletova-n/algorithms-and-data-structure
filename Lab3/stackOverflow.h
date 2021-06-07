#ifndef STACKOVERFLOW_H
#define STACKOVERFLOW_H

#include <exception>

class StackOverflow : public std::exception
{
public:
  StackOverflow()
    : reason("Stack Overflow")
  {}

  [[nodiscard]] const char* what() const noexcept override
  {
    return reason;
  }
private:
  const char* reason;
};

#endif
