#ifndef WRONGQUEUESIZE
#define WRONGQUEUESIZE
class WrongQueueSize : public std::exception
{
  public:
    WrongQueueSize():reason("Wrong Size Queue Size") {}
    const char* what() {return reason;}
  private:
    const char* reason;
};
#endif
