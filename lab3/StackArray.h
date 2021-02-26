#ifndef STACKSARRAY_H
#define STACKSARRAY_H

#include <iostream>

#include "StackOverflow.h"
#include "StackUnderflow.h"
#include "WrongStackSize.h"
#include "Stacks.h"

template<class T>
class StackArray : public Stack<T>
{
public:
  StackArray(size_t size = 100);
  StackArray(const StackArray<T>& src) = delete;
  StackArray(StackArray<T>&& src);
  StackArray<T>& operator=(const StackArray<T>& src) = delete;
  StackArray<T>& operator=(StackArray<T>&& src);
  virtual ~StackArray();
  virtual void push(const T& data);
  virtual const T& pop();
  virtual bool isEmpty();
  const T& peek() const;

private:
  T* array_;
  size_t top_;
  size_t size_;
  void Swap(StackArray<T>& src);
};



template<typename T>
StackArray<T>::StackArray(size_t size) :
  size_(size),
  top_(0)
{
  try {
    array_ = new T[size + 1];
  }
  catch (...) {
    throw WrongStackSize();
  }
}


template<typename T>
StackArray<T>::StackArray(StackArray<T>&& src) :
  array_(src.array_),
  top_(src.top_),
  size_(src.size_)
{
  src.size_ = 0;
  src.top_ = 0;
  src.array_ = nullptr;
  
  std::cout << "Move constructor!\n";
}


template<typename T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& src)
{
  if (src == *this)
    return *this;

  array_(src.array_);
  top_ = src.top_;
  size_ = src.size_;

  src.size_ = 0;
  src.top_ = 0;
  src.array_ = nullptr;

  std::cout << "Move assignment!\n";
}


template <typename T>
StackArray<T>::~StackArray()
{
  delete[] array_;
}


template<typename T>
void StackArray<T>::push(const T& data)
{
  if (top_ >= size_) {
    throw StackOverflow();
  }
  array_[++top_] = data;
}


template<typename T>
const T& StackArray<T>::pop()
{
  if (top_ == 0) {
    throw StackUnderflow();
  }
  return array_[top_--];
}


template<typename T>
bool StackArray<T>::isEmpty()
{
  if (top_ == 0)
    return true;
  else
    return false;
}


template<typename T>
const T& StackArray<T>::peek() const
{
  return array_[top_];
}
#endif