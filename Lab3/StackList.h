#ifndef STACK_LIST_H
#define STACK_LIST_H

#include < exception >

template <typename T>
class Stack
{
public:
  class StackOverflow : public std::exception
  {
  public:
    StackOverflow() = default;
    const std::string& problem() const { return reason_; }
  private:
    const std::string reason_ = "Stack Overflow";
  };
  class StackUnderflow : public std::exception
  {
  public:
    StackUnderflow()  = default;
    const std::string& problem() const { return reason_; }
  private:
    const std::string& reason_ = "Stack Underflow";
  };
  class WrongStackSize : public std::exception
  {
  public:
    WrongStackSize() = default;
    const std::string& problem() const { return reason_; }
  private:
    const std::string& reason_ = "Wrong stack size";
  };
  virtual ~Stack() = default;
  virtual void push(const T& e) = 0;
  virtual T& pop() =0;
  virtual bool isEmpty() const = 0;
  virtual void print() = 0;
};
#endif
