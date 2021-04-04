#ifndef LAB5_EXCEPTION_HPP
#define LAB5_EXCEPTION_HPP

#include <exception>

class QueueOverflow: public std::exception
{
public:
  QueueOverflow():
    reason("Queue overflow.")
  {}
  const char* what() { return reason; }
private:
  const char* reason;
};

class QueueUnderflow: public std::exception
{
public:
  QueueUnderflow():
    reason("Queue underflow.")
  {}
  const char* what() { return reason; }
private:
  const char* reason;
};

class WrongQueueSize: public std::exception
{
public:
  WrongQueueSize():
    reason("Wrong queue size.")
  {}
  const char* what() { return reason; }
private:
  const char* reason;
};

#endif
