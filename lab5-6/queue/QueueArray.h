#ifndef QUEUE_QUEUEARRAY_H
#define QUEUE_QUEUEARRAY_H

#include <iostream>

#include "exception.h"
#include "queue.h"

template<class T>
class QueueArray : public Queue<T>
{
public:
  QueueArray(int size = 100);
  //QueueArray(const QueueArray<T> &object);
  ~QueueArray();
  void enQueue(const T &element) override;
  T deQueue() override;
  bool isEmpty() const override;
  void print(std::ostream &output) const override;
private:
  int size_;
  int head_;
  T *array_;
};

template<class T>
QueueArray<T>::QueueArray(int size)
{
  if (size <= 0)
  {
    throw WrongQueueSize();
  }
  size_ = size;
  head_ = 0;
  array_ = new T[size_];
}

/*template<class T>
QueueArray<T>::QueueArray(const QueueArray<T> &object):
  size_(object.size_),
  head_(object.head_)
{
  array_ = new T(size_);
  for (int i = 0; i < size_; i++)
  {
    array_[i] = object.array_[i];
  }
}*/

template<class T>
QueueArray<T>::~QueueArray()
{
  delete[] array_;
}

template<class T>
void QueueArray<T>::enQueue(const T &element)
{
  if (head_ >= size_)
  {
    throw QueueOverflow();
  }
  array_[head_] = element;
  head_++;
}

template<class T>
T QueueArray<T>::deQueue()
{
  if (head_ == 0)
  {
    throw QueueUnderflow();
  }
  T temp = array_[0];
  for (int i = 0; i < head_ - 1; i++)
  {
    array_[i] = array_[i + 1];
  }
  head_--;
  return temp;
}

template<class T>
bool QueueArray<T>::isEmpty() const
{
  if (head_ == 0)
  {
    return true;
  }
  else
  {
    return false;
  }
}

template<class T>
void QueueArray<T>::print(std::ostream &output) const
{
  if (head_ == 0)
  {
    throw QueueUnderflow();
  }
  output << "QueueArray: ";
  for (int i = 0; i < head_; i++)
  {
    output << array_[i] << " ";
  }
}

#endif
