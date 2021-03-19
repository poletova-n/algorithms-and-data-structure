#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class StackOverFlow : public std::exception
{
public:
  StackOverFlow() : exception_("Stack Overflow") { }
  const char * what()
  {
    return exception_;
  }
private:
  const char* exception_;
};

class StackUnderFlow : public std::exception
{
public:
  StackUnderFlow() : exception_("Stack Underflow") { }
  const char * what()
  {
    return exception_;
  }
private:
  const char * exception_;
};

class WrongStackSize : public std::exception
{
public:
  WrongStackSize() : exception_("Wrong stack size") { }
  const char* what()
  {
    return exception_;
  }
private:
  const char* exception_;
};

#endif