#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include "stack.hpp"
#include "exceptions.hpp"

template <class T>
class StackArray : public Stack<T>
{
public:
  StackArray(size_t size);
  StackArray(const StackArray<T>& src);
  StackArray(StackArray<T>&& src);
  StackArray& operator=(const StackArray<T>& src);
  StackArray& operator=(StackArray<T>&& src);
  virtual ~StackArray();
  void push(const T& e) override;
  const T& pop() override;
  bool isEmpty() override;
  const T& top();
private:
  T* array_;
  size_t top_;
  size_t size_;
};

template <class T>
StackArray<T>::StackArray(size_t size) :
  size_(size),
  top_(0)
{
  try
  {
    array_ = new T[size + 1];
  }
  catch (...) 
  {
    throw WrongStackSize();
  }
}

// ����������� �����������
template <class T>
StackArray<T>::StackArray(const StackArray<T>& src) :
  size_(src.size_),
  top_(src.top_)
{
  try
  {
    array_ = new T[src.size_ + 1];
  }
  catch (...)
  {
    throw WrongStackSize();
  }
  for (size_t i = 1; i <= src.size_; i++)
  {
    array_[i] = src.array_[i];
  }
}

template<class T>
StackArray<T>::StackArray(StackArray<T>&& src) :
  size_(src.size_),
  top_(src.top_),
  array_(src.array_)
{
  src.size_ = 0;
  src.top_ = 0;
  src.array_ = nullptr;
}

template <class T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& src)
{
  size_ = src.size_;
  top_ = src.top_;
  array_ = src.array_;

  src.array_ = nullptr;
  src.size_ = 0;
  src.top_ = 0;
  return *this;
}

template <class T>
StackArray<T>& StackArray<T>::operator= (const StackArray<T>& src)
{
  if (*this == src)
  {
	return *this;
  }
  size_ = src.size_;
  top_ = src.top_;
  try 
  {
	array_ = new T[src.size_ + 1];
  }
  catch (...) 
  {
	throw WrongStackSize();
  }
  for (size_t i = 1; i < src.size_; i++)
  {
	array_[i] = src.array_[i];
  }
  return *this;
}

template<class T>
StackArray<T>::~StackArray()
{
  delete[] array_;
}

template <class T>
void StackArray<T>::push(const T& e)
{
  if (top_ == size_)
  {
    throw StackOverFlow();
  }
  array_[++top_] = e;
}

template <class T>
const T& StackArray<T>::pop()
{
  if (top_ == 0)
  {
    throw StackUnderFlow();
  }
  return array_[top_--];
}

template <class T>
bool StackArray<T>::isEmpty()
{
  return top_ == 0;
}

template <class T>
const T& StackArray<T>::top()
{
  if (top_ == 0)
  {
    throw StackUnderFlow();
  }
  return array_[top_];
}

#endif
