#ifndef EXCEPTIONSTACK_HPP
#define EXCEPTIONSTACK_HPP

#include <iostream>
#include <exception>

class StackOverFlow
  : public std::exception
{
  public:
  StackOverFlow() : reason_("Stack Overflow")
  {}

  const char *what() const noexcept override
  { return reason_.c_str(); }

  private:
  std::string reason_;
};

class StackUnderFlow
  : public std::exception
{
  public:
  StackUnderFlow() : reason_("Stack Underflow")
  {}

  const char *what() const noexcept override
  { return reason_.c_str(); }

  private:
  std::string reason_;
};

class StackWrongSize
  : public std::exception
{
  public:
  StackWrongSize() : reason_("Stack wrong size")
  {}

  const char *what() const noexcept override
  { return reason_.c_str(); }

  private:
  std::string reason_;
};

#endif
