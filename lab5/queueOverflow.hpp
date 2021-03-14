#ifndef QUEUEOVERFLOW_HPP
#define QUEUEOVERFLOW_HPP

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
#endif
