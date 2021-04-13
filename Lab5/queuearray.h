#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include "queue.h"
#include "exceptions.h"

template <class T>
class QueueArray : public Queue<T>
{
public:
  QueueArray(size_t size = 25);
  QueueArray(const QueueArray<T>& copy);
  QueueArray(QueueArray<T>&& moved) noexcept;

  virtual ~QueueArray();

  void enQueue(const T& elem);
  T deQueue();
  bool isEmpty();
private:
  T* array_;
  size_t tail_ = 1;
  size_t size_;
};

template <class T>
QueueArray<T>::QueueArray(size_t size) :
  tail_(1),
  size_(size)
{
  try
  {
    array_ = new T[size_];
  }
  catch (...)
  {
    throw WrongQueueSize();
  }
}

template <class T>
QueueArray<T>::QueueArray(const QueueArray<T>& copy) :
  tail_(copy.tail_),
  size_(copy.size_)
{
  try
  {
    array_ = new T[size_];
  }
  catch (...)
  {
    throw WrongQueueSize();
  }
  for (size_t i = 1; i < size_; ++i)
  {
    array_[i] = copy.array_[i];
  }
}

template <class T>
QueueArray<T>::QueueArray(QueueArray<T>&& moved) noexcept:
  tail_(moved.tail_),
  size_(moved.size_)
{
  array_ = new T[size_];
  for (size_t i = 0; i < size_; ++i)
  {
    array_[i] = std::move(moved.array_[i]);
  }
  moved.tail_ = 1;
  moved.size_ = 0;
}

template <class T>
QueueArray<T>::~QueueArray()
{
  delete[] array_;
}

template <class T>
void QueueArray<T>::enQueue(const T& element)
{
  if (size_ == tail_)
  {
    throw QueueOverFlow();
  }
  array_[tail_++] = element;
}

template <class T>
T QueueArray<T>::deQueue()
{
  if (isEmpty())
  {
    throw QueueUnderFlow();
  }
  T element = array_[1];
  for (size_t i = 1; i < tail_; ++i)
  {
    array_[i] = array_[i + 1];
  }
  --tail_;
  return element;
}

template <class T>
bool QueueArray<T>::isEmpty()
{
  return (tail_ == 1);
}

#endif