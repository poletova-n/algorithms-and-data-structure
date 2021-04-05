#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include "queue.h"
#include "exception.h"

template <class T>
class QueueArray : public Queue<T>
{
public:
  QueueArray(int size = 100); 
  QueueArray(const QueueArray<T>& src);
  ~QueueArray() override
  {
    delete[] array_;
  }
  void enQueue(const T& element);
  const T& deQueue();
  void printQueue();
  bool isEmpty()
  {
    return ((head_ == 0) && (tail_ == 0));
  }
  int nElements()
  {
    return (tail_ - head_ + 1);
  };

  T front(QueueArray* queue)
  {
    if (queue->isEmpty())
      return INT_MIN;
    return queue->array_[queue->head_];
  }


private:
  T* array_;
  int head_ = 0;
  int tail_ = 0;
  int size_;
};

template <class T>
QueueArray<T>::QueueArray(int size)
{
  try 
  {
    array_ = new T[size_ = size];
  }
  catch (...) 
  {
    throw WrongQueueSize(); 
  }
  head_ = 0;
  tail_ = 0;
}

template <class T>
QueueArray<T>::QueueArray(const QueueArray<T>& src) 
{
  try 
  {
    array_ = new T[size_ = src.size_];
  }
  catch (...) 
  {
    throw WrongQueueSize();
  }
  for (int i = 0; i < src.tail_; i++) 
  {
    this->array_[i] = src.array_[i];
  }
  head_ = src.head_;
  tail_ = src.tail_;
}

template <class T>
void QueueArray<T>::enQueue(const T& element)
{
  if (size_ == tail_ + 1)
  {
    throw QueueOverflow(); 
  }
  else if (isEmpty())
  {
    array_[tail_] = element;
    head_ = 1;
    tail_ = 1;
  }
  else
  {
    array_[tail_] = element;
    tail_++;
  }
}

template <class T>
const T& QueueArray<T>::deQueue()
{
  if (!isEmpty())
  {
    if (head_ == tail_)
    {
      T temp = array_[head_ - 1];
      array_[head_ - 1] = 0;
      head_ = 0;
      tail_ = 0;
      return temp;
    }
    else
    {
      T temp = array_[head_ - 1];
      array_[head_ - 1] = 0;
      head_++;
      return temp;
    }
  }
  throw QueueUnderflow();
}

template<class T>
void QueueArray<T>::printQueue()
{
  if (isEmpty())
  {
    std::cout << "Queue is empty.";
  }
  else
  {
    int i = head_ - 1;
    for (int j = 0; j < nElements(); j++)
    {
      std::cout << " " << array_[i] << " ";
      i++;
    }
  }
    std::cout << std::endl;
}

#endif
