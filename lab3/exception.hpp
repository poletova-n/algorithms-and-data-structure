#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class StackOverFlow : public std::exception
{
public:
  StackOverFlow() : exception_("Stack Overflow") { }
  const char * what() const noexcept override;
private:
  const char* exception_;
};

const char *StackOverFlow::what() const noexcept { return exception_; }

class StackUnderFlow : public std::exception
{
public:
  StackUnderFlow() : exception_("Stack Underflow") { }
  const char* what()const noexcept override { return exception_; }
private:
  const char* exception_;
};

class WrongStackSize : public std::exception
{
public:
  WrongStackSize() : exception_("Wrong stack size") { }
  const char* what()const noexcept override { return exception_; }
private:
  const char* exception_;
};

#endif