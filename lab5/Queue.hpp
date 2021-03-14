#ifndef QUEUE
#define QUEUE

template <class T>
class Queue
{
public:
  virtual ~Queue() {}
  virtual void enQueue(const T& e) = 0;
  virtual T deQueue() = 0;
  virtual bool isEmpty() const = 0;
};
#endif
