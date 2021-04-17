#ifndef stackOverflow_h
#define stackOverflow_h

#include <exception>

class StackOverflow : public std::exception
{
public:
  StackOverflow()
  : reason("Stack Overflow")
  {}

  [[nodiscard]] const char *what() const noexcept override
  {
    return reason;
  }
private:
    const char* reason;
  };

#endif
