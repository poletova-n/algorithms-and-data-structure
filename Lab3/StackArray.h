#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include "StackList.h"

template <typename T>
class StackArray : public Stack<T>
{
public:
  StackArray(size_t size );
  StackArray(const StackArray<T>&) = delete;
  StackArray(StackArray<T>&&);
  virtual ~StackArray();

  StackArray& operator=(const StackArray<T>&) = delete;
  StackArray& operator=(StackArray<T>&&);

  void push(const T&) override;
  virtual T& pop();
  bool isEmpty() const override;
  void print() override;
  virtual const T& top();

private:
  T* array_;
  size_t top_;
  size_t size_;
};
template<typename T>
void StackArray<T>::print()
{
  for (int i = size_; i >=1; i--)
  {
    std::cout  <<" "<<array_[i];
    array_[top_--];
  }
}
template<typename T>
T& StackArray<T>::pop()
{
  if (top_ == 0) {
    throw typename Stack<int>::StackUnderflow();
  }
  return array_[top_--];
}
template<typename T>
void StackArray<T>::push(const T& e)
{
  if (top_ == size_) {
    throw typename Stack<int>:: StackOverflow();
  }
  array_[++top_] = e;
}
template<typename T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& src)
{
  if (src == *this)
    return *this;

  array_(src.array_);
  top_(src.top_);
  size_(src.size_);

  src.size_ = 0;
  src.top_ = 0;
  src.array_ = nullptr;
}
template<typename T>
bool StackArray<T>::isEmpty() const
{
  if (top_ == 0)
    return true;
  else
    return false;
}
template<typename T>
const T& StackArray<T>::top() {
  return array_[top_];
}
template<typename T>
StackArray<T>::StackArray(StackArray<T>&& src) :
        array_(src.array_),
        size_(src.size_),
        top_(src.top_)
{
  src.size_ = 0;
  src.top_ = 0;
  src.array_ = nullptr;
}
template<typename T >
StackArray<T>::StackArray(size_t size) :
        size_(size),
        top_(0)
{
  try {
    array_ = new T[size + 1];
  }
  catch (...) {
    throw typename Stack<int>::WrongStackSize();
  }
  if (size == 0) {
    throw typename Stack<int>::WrongStackSize();
  }

}
template <typename T>
StackArray<T>::~StackArray()
{
  delete[] array_;
}

#endif
