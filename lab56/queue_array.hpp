#ifndef LAB56_QUEUE_ARRAY_HPP
#define LAB56_QUEUE_ARRAY_HPP
#include "queue.hpp"
#include "exceptions_queue.hpp"

template<class T>
class QueueArray : public Queue<T> {
public:
  explicit QueueArray(int size = 100);

  QueueArray(const QueueArray<T> &src);

  virtual ~QueueArray() { delete[] array_; }

  void enQueue(const T &e);

  const T deQueue();

  bool isEmpty() { return head_ == tail_; }

private:
  T *array_;
  int head_ = 0;
  int tail_ = 0;
  int size_;
};

template<class T>
QueueArray<T>::QueueArray(int size) {
  try {
    array_ = new T[size];
  }
  catch (...) {
    throw WrongQueueSize();
  }
  size_ = size;
  head_ = 0;
  tail_ = 0;
}

template<class T>
QueueArray<T>::QueueArray(const QueueArray<T> &src) {
  try {
    array_ = new T[src.size_];
    for (int i = 0; i < src.size_; i++)
    {
      array_[i] = src.array_[i];
    }
    size_ = src.size_;
    head_ = src.head_;
    tail_ = src.tail_;
  }
  catch (...) {
    throw WrongQueueSize();
  }
}

template<class T>
void QueueArray<T>::enQueue(const T &e) {
  if ((head_ == tail_ + 1)||(tail_ == size_)) {
    throw QueueOverflow();
  }
  array_[tail_] = e;
  tail_++;
}

template<class T>
const T QueueArray<T>::deQueue() {
  if (head_ == tail_){
    throw QueueUnderflow();
  }
  const T temp = array_[head_];

  for (int i = 0; i < tail_-1; i++)
  {
    array_[i] = array_[i + 1];
  }
  tail_--;
  return temp;
}

#endif //LAB56_QUEUE_ARRAY_HPP
