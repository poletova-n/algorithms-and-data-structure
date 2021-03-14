#ifndef WRONGQUEUESIZE_HPP
#define WRONGQUEUESIZE_HPP

#include <exception> 

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
