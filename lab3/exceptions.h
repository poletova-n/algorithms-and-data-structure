#ifndef EXEPTIONS_H
#define EXEPTIONS_H

#include <exception>

class StackOverFlow : public std::exception
{
public:
  StackOverFlow() : reason_("Stack Overflow") { }
  const char* what() const override { return reason_; }
private:
  const char* reason_;
};

class StackUnderFlow : public std::exception
{
public:
  StackUnderFlow() : reason_("Stack Underflow") { }
  const char* what() const override { return reason_; }
private:
  const char* reason_;
};

class WrongStackSize : public std::exception
{
public:
  WrongStackSize() : reason_("Wrong stack size") { }
  const char* what() const override { return reason_; }
private:
  const char* reason_;
};

#endif
