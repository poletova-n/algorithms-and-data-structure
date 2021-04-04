#ifndef QUEUE_H
#define QUEUE_H

#include <exception>

//========================================================================
// ������ QueueOverflow � QueueUnderflow ������������ ��� ��������
// �������������� ��������, ������� ����� ���������� ��� ������ � ��������
//========================================================================
class QueueOverflow : public std::exception
{
public:
  QueueOverflow():std::exception("Queue Overflow") {}
};
class QueueUnderflow : public std::exception
{
public:
  QueueUnderflow():
    std::exception("Queue Underflow")
  {}
};

//==============================================================
// �������������� �������� WrongQueueSize ����� �������y��,
// ���� � ������������ ������� ����������� ����� ������.
//==============================================================
class WrongQueueSize : public std::exception
{
public:
  WrongQueueSize():
    std::exception("Wrong Queue Size")
  {}
};

// =============================================================
//  ������ ������ Queue ������������ ������� ������������ �������
//==============================================================
template <class T>
class Queue
{
public:
  virtual ~Queue() {}

  // ����������� �������� �� ������
  virtual void push(const T& e) = 0; // ���������� �������� � ���� 
  virtual T pop() = 0;// �������� � ����������� �������� ��������. ���� ��������� ���, ����� ���������� QueueUnderflow 
  virtual bool isEmpty() const = 0; // �������� �� ������� 
};

//==============================================================
// ������ ������ QueueArray - ���������� ������������ �������.
// �������� ������� ���������� � ������.
//==============================================================
template <typename T>
class QueueArray final : public Queue<T> // ����������� final ��������� ������������ �� ������
{
public:
  QueueArray(size_t size); // size ������ ������ "�� ���������"
  QueueArray(const QueueArray<T>& src) = delete;
  QueueArray(QueueArray<T>&& src);

  QueueArray<T>& operator= (QueueArray<T>&& src); // �������� ������������� ������������

  virtual ~QueueArray() override;

  void push(const T& e) override;
  T pop() override;
  bool isEmpty() const override;

private:
  T* array_;         // ������ ��������� �������
  size_t head_;  // ������� �����, ����  head[Q] = tail[Q]. 
  size_t tail_;  // �������������: head[Q] = tail[Q] = 1;
  size_t size_;      // ������ ������� 
  void swap(QueueArray<T>& right);
};

template <typename T>
QueueArray<T>::QueueArray(size_t size):
  size_(size),
  head_(1),
  tail_(1)
{
  try
  {
    array_ = new T[size + 1];// �������� �������� ������ ��� �������� �������...
  }
  catch (...) // ���� ���-�� ��������� (��������, ������ ������� �������
  {
    throw WrongQueueSize(); // ��� ...) - ��������� ����.�������� bad_alloc
  }
}

template <typename T>
void QueueArray<T>::swap(QueueArray<T>& right)
{
  std::swap(*this.array_, right.array_);
  std::swap(*this.head_, right.head_);
  std::swap(*this.tail_, right.tail_);
  std::swap(*this.size_, right.size_);
}

template <typename T>
QueueArray<T>::QueueArray(QueueArray<T>&& src)
{
  head_ = src.head_;
  tail_ = src.tail_;
  size_ = src.size_;
  array_ = src.array_;

  src.head_ = 1;
  src.tail_ = 1;
  src.size_ = 0;
  src.array_ = nullptr;
}

template <typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& src)
{
  if (*this != src)
  {
    head_ = src.head_;
    tail_ = src.tail_;
    size_ = src.size_;
    array_ = src.array_;
    
    src.head_ = 1;
    src.tail_ = 1;
    src.size_ = 0;
    src.array_ = nullptr;
  }
  return *this;
}

template<typename T>
QueueArray<T>::~QueueArray()
{
  delete[] array_;
}

template <typename T>
void QueueArray<T>::push(const T& e)
{
  if ((head_ == tail_ + 1) || (tail_ == size_ && head_ == 0))
    throw QueueOverflow(); // ��� ����� ��� ������ ��������
  array_[tail_] = e;
  
  if (tail_ == size_)
    tail_ = 0;
  else
    tail_++;
}

template <typename T>
T QueueArray<T>::pop()
{
  if (head_ == tail_)
    throw QueueUnderflow(); // ������� �����
  if (head_ == size_)
  {
    head_ = 0;
    return array_[size_];
  }
  else
  {
    head_++;
    return array_[head_ - 1];
  }
}

template<typename T>
bool QueueArray<T>::isEmpty() const
{
  return head_ == tail_;
}

#endif /* QUEUE_H */