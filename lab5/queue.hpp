#ifndef QUEUE_QUEUE_HPP
#define QUEUE_QUEUE_HPP

template<class T>
class Queue
{
public:
  virtual ~Queue() = default;
  virtual void enQueue(const T &element) = 0;
  virtual const T& deQueue() = 0;
  virtual bool isEmpty() = 0;
};

#endif //QUEUE_QUEUE_HPP
