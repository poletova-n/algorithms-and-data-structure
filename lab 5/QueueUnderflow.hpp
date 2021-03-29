#ifndef QUEUE_UNDERFLOW
#define QUEUE_UNDERFLOW

#include <exception>

class QueueUnderflow : public std::exception
{
public:
  QueueUnderflow() : reason("Queue Underflow")
  {}
  const char *what()
  { return reason; }

private:
  const char *reason;
};

#endif
