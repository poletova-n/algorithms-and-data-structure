#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

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

#endif // !EXCEPTIONS_H
