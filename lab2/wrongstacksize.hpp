#ifndef WORKING_WRONGSTACKSIZE_HPP
#define WORKING_WRONGSTACKSIZE_HPP

#include <exception>

class WrongStackSize: std::exception
{
public:
  WrongStackSize():
    exceptionName("Wrong Stack size!") {}
  const char* what() const noexcept override { return exceptionName; }

private:
  const char* exceptionName;
};

#endif
