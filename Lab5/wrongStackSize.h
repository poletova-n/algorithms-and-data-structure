#ifndef WRONGSTACKSIZE_H
#define WRONGSTACKSIZE_H

#include <exception>

class WrongStackSize : public std::exception
{
public:
  WrongStackSize() :
    reason("Wrong stack size")
  {}

  [[nodiscard]] const char* what() const noexcept override
  {
    return reason;
  }

private:
  const char* reason;
};

#endif
