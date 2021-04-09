#ifndef stackUnderflow_h
#define stackUnderflow_h

#include <exception>

class StackUnderflow : public std::exception
{
public:
  StackUnderflow():
  reason("Stack Underflow")
  {}

  [[nodiscard]] const char *what() const noexcept override
  {
    return reason;
  }

private:
  const char* reason;
};

#endif
