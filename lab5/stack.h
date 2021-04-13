#ifndef STACK_H
#define STACK_H

#include <exception>

template <class T>
class Stack
{
public:
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

  virtual ~Stack() = default;
  virtual void push(const T& e) = 0;
  virtual const T& pop() = 0;
  virtual bool isEmpty() = 0;
};

#endif
