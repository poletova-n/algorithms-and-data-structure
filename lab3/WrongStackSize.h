#ifndef WRONGSTACKSIZE_H
#define WRONGSTACKSIZE_H

#include <exception> 

class WrongStackSize: public std::exception
{
public:
  WrongStackSize() = default;
  const char* getError() const
  {
    return error_;
  }

private:
  const char* error_ = "Wrong Stack size";
};
#endif