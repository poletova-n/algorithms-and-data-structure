#ifndef QUEUE_ARRAY
#define QUEUE_ARRAY

#include "QueueUnderflow.hpp"
#include "QueueOverflow.hpp"
#include "WrongQueueSize.hpp"
#include "Queue.hpp"

template<typename T>
class QueueArray final :
  public Queue<T> // модификатор final запрещает наследование от класса
{
public:
  QueueArray(size_t size);
  QueueArray(const QueueArray<T> &src) = delete;
  QueueArray(QueueArray<T> &&src);
  QueueArray<T> &operator=(QueueArray<T> &&src);
  void print();

  bool isEmpty() const override
  { return head_ == tail_; }

  virtual ~QueueArray() override
  { delete[] array_; }

  void enQueue(const T &e) override;
  T deQueue() override;

private:
  T *array_;         // массив элементов очереди
  size_t head_ = 1;  // Очередь пуста, если  head[Q] = tail[Q].
  size_t tail_ = 1;  // Первоначально: head[Q] = tail[Q] = 1;
  size_t size_;      // размер очереди
};

template<typename T>
QueueArray<T>::QueueArray(size_t size):
  size_(size), head_(1), tail_(1)
{
  try
  {
    array_ = new T[size + 1];
  }
  catch (...)
  {
    throw WrongQueueSize();
  }
}


template<typename T>
QueueArray<T>::QueueArray(QueueArray<T> &&src)
{
  head_ = src.head_;
  tail_ = src.tail_;
  array_ = src.array_;
  size_ = src.size_;
  src.array_ = nullptr;
  src.size_ = 0;
}

template<typename T>
QueueArray<T> &QueueArray<T>::operator=(QueueArray<T> &&src)
{
  head_ = src.head_;
  tail_ = src.tail_;
  array_ = src.array_;
  size_ = src.size_;
  src.array_ = nullptr;
  src.size_ = 0;
  return *this;
}

template<typename T>
void QueueArray<T>::enQueue(const T &e)
{
  if (size_ + 1 == tail_)
  {
    throw QueueOverflow();
  }
  array_[tail_] = e;
  tail_++;
}

template<typename T>
T QueueArray<T>::deQueue()
{
  if (head_ == tail_)
  {
    throw QueueUnderflow();
  }
  T deleteTemp = array_[1];
  for (size_t i = 0; i < tail_ - 1; i++)
  {
    array_[i] = array_[i + 1];
  }
  tail_ --;
  return deleteTemp;
}

template<typename T>
void QueueArray<T>::print()
{
  if (isEmpty())
  {
    std::cout << "Queue is empty\n";
  }
  else
  {
    std::cout << "Queue:\n";
    for (size_t i = head_; i < tail_; i++)
    {
      std::cout << array_[i] << " ";
    }
    std::cout << "\n";
  }
}

#endif
