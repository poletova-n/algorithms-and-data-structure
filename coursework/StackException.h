#ifndef STACKEXCEPTION_H
#define STACKEXCEPTION_H

#include <exception>
#include <string>

class StackOverflow : public std::exception
{
public:
  StackOverflow() :
    reason("Stack Overflow")
  {};
  const char* reason;
};

class StackUnderflow : public std::exception
{
public:
  StackUnderflow() :
    reason("Stack Underflow")
  {};
  const char* reason;
};

class WrongStackSize : public std::exception
{
public:
  WrongStackSize() :
    reason("Wrong stack size")
  {};
  const char* reason;
};

#endif
