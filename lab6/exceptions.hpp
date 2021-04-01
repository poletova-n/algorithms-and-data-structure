#ifndef LAB6_EXCEPTIONS_HPP
#define LAB6_EXCEPTIONS_HPP

#include <exception>

class StackOverflow : public std::exception
{
public:
  StackOverflow():
    exceptionName("Stack Overflow!") {}
  const char* what() const noexcept override { return exceptionName; }

private:
  const char* exceptionName;
};

class StackUnderflow: public std::exception
{
public:
  StackUnderflow():
    exceptionName("Stack Underflow!") {}
  const char* what() const noexcept override { return exceptionName; }

private:
  const char* exceptionName;
};

class WrongStackSize: std::exception
{
public:
  WrongStackSize():
    exceptionName("Wrong Stack size!") {}
  const char* what() const noexcept override { return exceptionName; }

private:
  const char* exceptionName;
};

class QueueOverflow: public std::exception
{
public:
  QueueOverflow():
    exceptionName("Queue overflow.")
  {}
  const char* what() { return exceptionName; }

private:
  const char* exceptionName;
};

class QueueUnderflow: public std::exception
{
public:
  QueueUnderflow():
    exceptionName("Queue underflow.")
  {}
  const char* what() { return exceptionName; }

private:
  const char* exceptionName;
};

class WrongQueueSize: public std::exception
{
public:
  WrongQueueSize():
    exceptionName("Wrong queue size.")
  {}
  const char* what() { return exceptionName; }

private:
  const char* exceptionName;
};

#endif
