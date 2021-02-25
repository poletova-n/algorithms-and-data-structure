#ifndef WRONG_STACK_SIZE
#define WRONG_STACK_SIZE

#include <exception>

class WrongStackSize : public std::exception
{
public:
  WrongStackSize() : reason_("Wrong stack size!") {}
  const char* what() const { return reason_; }
private:
  const char* reason_;
};

#endif
