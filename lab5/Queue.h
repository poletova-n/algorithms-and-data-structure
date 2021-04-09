#ifndef LAB5_QUEUE_H
#define LAB5_QUEUE_H

template <class T>
class Queue
{
public:
  virtual ~Queue () = default;
  virtual void enQueue(const T& e) = 0;
  virtual T deQueue () = 0;
  virtual bool isEmpty() const = 0;
};

#endif
