#ifndef EXCEPTIONSQUEUE_HPP
#define EXCEPTIONSQUEUE_HPP

#include <exception>

class QueueOverflow : public std::exception
{
public:
  QueueOverflow() : error_("Queue Overflow") {};
  const char* getError() const
  {
    return error_;
  }

private:
  const char* error_;
};

class QueueUnderflow : public std::exception
{
public:
  QueueUnderflow() : error_("Queue Underflow") {};
  const char* getError() const
  {
    return error_;
  }

private:
  const char* error_;
};

class WrongQueueSize : public std::exception
{
public:
  WrongQueueSize() = default;
  const char* getError() const
  {
    return error_;
  }

private:
  const char* error_ = "Wrong Stack size";
};

#endif
