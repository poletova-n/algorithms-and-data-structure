#ifndef WRONGSTACKSIZE_H
#define WRONGSTACKSIZE_H

#include <exception>

class WrongStackSize: public std::exception
{
public:
  WrongStackSize():reason("Wrong Stack Size") {}
  const char* what() { return reason; }
private:
  const char* reason;
};
#endif
