#ifndef wrongStackSize_h
#define wrongStackSize_h

#include <exception>

class WrongStackSize : public std::exception
{
public:
  WrongStackSize():
  reason("Wrong stack size")
  {}

  [[nodiscard]] const char *what() const noexcept override
  {
    return reason;
  }

private:
  const char* reason;
};

#endif
