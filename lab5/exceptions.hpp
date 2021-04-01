#ifndef LAB5_EXCEPTIONS_HPP
#define LAB5_EXCEPTIONS_HPP

#include <exception>

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

#endif //LAB5_EXCEPTIONS_HPP
