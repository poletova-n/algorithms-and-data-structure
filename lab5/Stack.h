#ifndef STACK
#define STACK

#include <exception>

template <typename T>
class Stack
{
public:

  class StackOverflow : public std::exception
  {
  public:
    StackOverflow() = default;

    const char* what() const noexcept override{ return message_; }

  private:
    const char* message_ = "Stack overflow";
  };

  class StackUnderflow : public std::exception
  {
  public:
    StackUnderflow() = default;

    const char* what() const noexcept override{ return message_; }

  private:
    const char* message_ = "Stack underflow";
  };

  class WrongStackSize : public std::exception
  {
  public:
    WrongStackSize() = default;

    const char* what() const noexcept override { return message_; }

  private:
    const char* message_ = "Wrong stack size";
  };

  virtual ~Stack() = default;

  virtual void push(const T&) = 0;
  virtual T pop() = 0;
  virtual bool isEmpty() const = 0;
  virtual void print() = 0;
};

#endif
