#ifndef QUEUEARRAY_HPP
#define QUEUEARRAY_HPP

#include <cstdlib>
#include <ostream>
#include "queue.hpp"
#include "exceptions.hpp"

template<class T>
class QueueArray : public Queue<T> {
public:
  explicit QueueArray(size_t capacity = 100);
  QueueArray(const QueueArray<T>& src);
  QueueArray(QueueArray<T>&& src) noexcept;
  ~QueueArray() override;
  void push(const T& e) override;
  void pop() override;
  [[nodiscard]] bool isEmpty() const override;
  T& front() override;
  T& back() override;
  void print(std::ostream& ostream) const override;

private:
  T* array_;
  size_t size_;
  size_t capacity_;
};

template<class T>
QueueArray<T>::QueueArray(size_t capacity):
  capacity_(capacity)
{
  array_ = static_cast<T*> (malloc(capacity_ * sizeof(T)));
  if (!array_) {
    free(array_);
    throw WrongQueueSize();
  }
  size_ = 0;
}

template<class T>
QueueArray<T>::QueueArray(const QueueArray<T>& src):
  capacity_(src.capacity_)
{
  array_ = static_cast<T*>(malloc(capacity_ * sizeof(T)));
  if (!array_) {
    free(array_);
    throw WrongQueueSize();
  }
  size_ = src.size_;
}

template<class T>
QueueArray<T>::QueueArray(QueueArray<T>&& src) noexcept:
  array_(std::move(src.array_)),
  size_(src.size_),
  capacity_(src.capacity_)
{
  src.size_ = 0;
  src.capacity_ = 0;
}

template<class T>
void QueueArray<T>::push(const T& e)
{
  if (size_ == capacity_) {
    throw QueueOverflow();
  }
  array_[size_] = e;
  ++size_;
}

template<class T>
void QueueArray<T>::pop()
{
  if (size_ == 0) {
    throw QueueUnderflow();
  }
  T* temp = static_cast<T*>(malloc(capacity_ * sizeof(T)));
  for (int i = 0; i < size_-1; ++i) {
    temp[i] = array_[i+1];
  }
  free(array_);
  array_ = std::move(temp);
  --size_;
}

template<class T>
QueueArray<T>::~QueueArray()
{
  free(array_);
}

template<class T>
bool QueueArray<T>::isEmpty() const
{
  return size_ == 0;
}

template<class T>
void QueueArray<T>::print(std::ostream& ostream) const
{
  ostream << "Queue{array_=[";
  if (isEmpty()) {
    ostream << "], size_=0}\n";
    return;
  }
  for (size_t i = 0; i < size_; ++i) {
    ostream << array_[i] << ';';
  }
  ostream << "], size_=" << size_ << "}\n";
}

template<class T>
T& QueueArray<T>::front()
{
  if (size_ == 0) {
    throw QueueUnderflow();
  }
  return array_[0];
}

template<class T>
T& QueueArray<T>::back()
{
  if (size_ == 0) {
    throw QueueUnderflow();
  }
  return array_[size_ - 1];
}

#endif
