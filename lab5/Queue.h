#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <exception>

class QueueOverflow : public std::exception
{
public:
  QueueOverflow() = default;

  const char* what() const noexcept override{ return message_; }

private:
  const char* message_ = "Queue overflow";
};

class QueueUnderflow : public std::exception
{
public:
  QueueUnderflow() = default;

  const char* what() const noexcept override{ return message_; }

private:
  const char* message_ = "Queue underflow";
};

template <class T>
class Queue
{
public:
  virtual ~Queue() {}

  virtual void enQueue(const T& e) = 0;

  virtual T deQueue() = 0;

  virtual bool isEmpty() const = 0;
};

class WrongQueueSize : public std::exception
{
public:
  WrongQueueSize() = default;

  const char* what() const noexcept override{ return message_; }

private:
  const char* message_ = "Wrong queue size";
};

template <typename T>
class QueueArray final : public Queue<T>
{
public:
  QueueArray(size_t size);
  QueueArray(const QueueArray<T>& src) = delete;
  QueueArray(QueueArray<T>&& src);

  QueueArray<T>& operator= (const QueueArray<T>& src) = delete;
  QueueArray<T>& operator= (QueueArray<T>&& src);

  virtual ~QueueArray() override { delete[] array_; }

  void enQueue(const T& e) override;
  T deQueue() override;
  bool isEmpty() const override { return head_ == tail_; }

private:
  T* array_;
  size_t head_ = 1;
  size_t tail_ = 1;
  size_t size_;
  void swap(QueueArray<T> &right);
};

template <typename T>
QueueArray<T>::QueueArray(size_t size):
  size_(size), head_ (1), tail_ (1)
{
  if (size < 1) {
    throw WrongQueueSize();
  }
  try {
    array_ = new T[size + 1];
  } catch (...) {
    throw WrongQueueSize();
  }
}

template <typename T>
void QueueArray<T>::swap(QueueArray<T>& right)
{
  std::swap(array_, right.array_);
  std::swap(head_,  right.head_);
  std::swap(tail_,  right.tail_);
  std::swap(size_,  right.size_);
}

template <typename T>
QueueArray<T>::QueueArray(QueueArray<T>&& src)
{
  array_ = std::move(src.array_);
  head_ = src.head_;
  tail_ = src.tail_;
  size_ = src.size_;
  src.array_ = nullptr;
  src.size_ = 0;
  src.head_ = 0;
  src.tail_ = 0;
}

template <typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& src)
{
  swap(src);
  src.array_ = nullptr;
  src.size_ = 0;
  src.head_ = 0;
  src.tail_ = 0;
  return *this;
}

template <typename T>
void QueueArray<T>::enQueue(const T& e)
{
  if (head_ == tail_ + 1) {
    throw QueueOverflow();
  }
  array_[tail_++] = e;
  tail_ %= size_;
}

template <typename T>
T QueueArray<T>::deQueue()
{
  if (head_ == tail_) {
    throw QueueUnderflow();
  }
  size_t temp = head_++;
  head_ %= size_;
  return array_[temp];
}

#endif
