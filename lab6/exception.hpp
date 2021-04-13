#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>

class QueueOverFlow : public std::exception
{
public:
  QueueOverFlow() : reason_("Queue overflow") {}
  const char* what() const { return reason_; }
private:
  const char* reason_;
};

class QueueUnderFlow : public std::exception
{
public:
  QueueUnderFlow() : reason_("Queue underflow") {}
  const char* what() const { return reason_; }
private:
  const char* reason_;
};

class WrongQueueSize : public std::exception
{
public:
  WrongQueueSize() : reason_("Wrong queue size") {}
  const char* what() const { return reason_; }
private:
  const char* reason_;
};

class StackOverFlow : public std::exception
{
public:
  StackOverFlow() : exception_("Stack Overflow") { }
  const char* what() const override { return exception_; }
private:
  const char* exception_;
};

class StackUnderFlow : public std::exception
{
public:
  StackUnderFlow() : exception_("Stack Underflow") { }
  const char* what() const override { return exception_; }
private:
  const char* exception_;
};

class WrongStackSize : public std::exception
{
public:
  WrongStackSize() : exception_("Wrong stack size") { }
  const char* what() const override { return exception_; }
private:
  const char* exception_;
};

#endif
