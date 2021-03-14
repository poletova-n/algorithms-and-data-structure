#ifndef STACK_ARRAY
#define STACK_ARRAY

#include "Stack.h"

template <typename T>
class StackArray : public Stack<T>
{
public:
  StackArray(int = 100);
  StackArray(const StackArray<T>&) = delete;
  StackArray(StackArray<T>&&);
  ~StackArray();

  StackArray& operator=(const StackArray<T>&) = delete;
  StackArray& operator=(StackArray<T>&&);

  void push(const T&) override;
  T pop() override;
  bool isEmpty() const override;
  StackArray<T> copy() const;
  void print() override;
  
private:
  T* array_;
  size_t top_;
  size_t size_;
 
};

template <typename T>
StackArray<T>::StackArray(int size)
{
  if (size <= 0) {
    throw typename Stack<T>::WrongStackSize();
  }
  array_ = new T[++size];
  size_ = size;
  top_ = 0;
}

template <typename T>
StackArray<T>::StackArray(StackArray<T>&& source)
{
  array_ = source.array_;
  top_ = source.top_;
  size_ = source.size_;
  source.array_ = nullptr;
  source.top_ = 0;
  source.size_ = 0;
}

template <typename T>
StackArray<T>::~StackArray()
{
  delete[] array_;
}

template <typename T>
StackArray<T>& StackArray<T>::operator=(StackArray<T>&& source)
{
  array_ = source.array_;
  top_ = source.top_;
  size_ = source.size_;
  source.array_ = nullptr;
  source.top_ = 0;
  source.size_ = 0;
  return *this;
}

template <typename T>
void StackArray<T>::push(const T& element)
{
  if (top_ + 1 == size_) {
    throw typename Stack<T>::StackOverflow();
  }
  array_[++top_] = element;
}

template <typename T>
T StackArray<T>::pop()
{
  if (top_ == 0) {
    throw typename Stack<T>::StackUnderflow();
  }
  return array_[top_--];
}

template <typename T>
bool StackArray<T>::isEmpty() const
{
  return top_ == 0;
}

template <typename T>
StackArray<T> StackArray<T>::copy() const
{
  StackArray<T> result(size_ - 1);
  for (int i = 1; i < size_; i++) {
    result.array_[i] = array_[i];
  }
  result.top_ = top_;
  return result;
}

template <typename T>
void StackArray<T>::print()
{
  while (!isEmpty()) {
    std::cout << pop() << ' ';
  }
}

#endif
