#ifndef LAB2_EXCEPTION_HPP
#define LAB2_EXCEPTION_HPP
#include <exception>

#include <exception>

class StackOverflow: public std::exception
{
public:
  StackOverflow():
    reason("Stack overflow.")
  {}
  const char* what() { return reason; }
private:
  const char* reason;
};

class StackUnderflow: public std::exception
{
public:
  StackUnderflow():
    reason("Stack underflow.")
  {}
  const char* what() { return reason; }
private:
  const char* reason;
};

class WrongStackSize: public std::exception
{
public:
  WrongStackSize():
    reason("Wrong stack size.")
  {}
  const char* what() { return reason; }
private:
  const char* reason;
};

#endif
