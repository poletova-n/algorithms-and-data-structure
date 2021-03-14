#ifndef QUEUE_HPP
#define QUEUE_HPP

template<class T>
class Queue
{
public:
  virtual ~Queue() = default;
  virtual void enQueue(const T& data) = 0;
  virtual const T& deQueue() = 0;
  virtual bool isEmpty() const = 0;
};

#endif
