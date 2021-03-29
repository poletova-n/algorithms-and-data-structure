#ifndef QUEUE_OVERFLOW
#define QUEUE_OVERFLOW

#include <exception>

class QueueOverflow : public std::exception
{
public:
  QueueOverflow() : reason("Queue Underflow")
  {}
  const char *what()
  { return reason; }

private:
  const char *reason;
};

#endif
