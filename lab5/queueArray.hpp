#ifndef QUEUE_QUEUEARRAY_HPP
#define QUEUE_QUEUEARRAY_HPP

#include "queue.hpp"
#include "exception.hpp"

template <class T>
class QueueArray : public Queue<T>
{
public:

  explicit QueueArray(int size = 100);
  ~QueueArray() override;
  void enQueue (const T& e) override;
  const T& deQueue () override;
  bool isEmpty() override;
  void print(std::ostream &out);

private:
  T* array_;
  int head_;
  int tail_;
  int size_;
};

template <class T>
QueueArray<T>::QueueArray(int size) :
  size_(size),
  head_(0),
  tail_(0)
{
  try {
    array_ = new T[size];
  }
  catch (...) {
    throw WrongQueueSize();
  }
}

template <class T>
void QueueArray<T>::enQueue (const T& e) {
  if (head_ - tail_ == 1 || tail_ - head_ == size_ - 1)
  {
    throw QueueOverflow();
  }
  try {
    for (int i = tail_ + 1; i > head_;) {
      array_[i] = array_[--i];
    }
  }
  catch (...) {
    throw WrongQueueSize();
  }
  array_[head_] = e;
  tail_++;
}

template <class T>
const T& QueueArray<T>::deQueue() {
  if (head_ == tail_)
    throw QueueUnderflow();
  int temptTail = tail_;
  tail_--;
  return array_[temptTail];
}

template<class T>
bool QueueArray<T>::isEmpty() {
  return head_ == tail_;
}

template<class T>
QueueArray<T>::~QueueArray() {
  delete[] array_;
}

template<class T>
void QueueArray<T>::print(std::ostream &out) {
  out << "Total numder of elements: " << tail_ - head_;
  out << std::endl;
  for (int i = head_; i < tail_; i++) {
    out << array_[i] << " ";
  }
  out << std::endl;
}

#endif //QUEUE_QUEUEARRAY_HPP
