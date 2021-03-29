#ifndef WRONG_QUEUE_SIZE
#define WRONG_QUEUE_SIZE

#include <stdexcept>

class WrongQueueSize : public std::exception
{
public:
  WrongQueueSize() : reason("Wrong Size Queue Size")
  {}
  const char *what()
  { return reason; }

private:
  const char *reason;
};

#endif
