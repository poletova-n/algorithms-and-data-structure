#ifndef QUEUEUNDERFLOW_HPP
#define QUEUEUNDERFLOW_HPP

#include <exception> 

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
#endif

