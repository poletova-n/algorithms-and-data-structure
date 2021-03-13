#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

#include "Stack.h"

template <typename T>
class StackArray : public Stack<T>
{
public:
  class WrongStackSize : public Stack<T>::StackException
  {
  public:
    WrongStackSize(const std::string message);
  private:
  };
  class StackOverflow : public Stack<T>::StackException
  {
  public:
    StackOverflow(const std::string message);
  private:
  };
  class StackUnderflow : public Stack<T>::StackException
  {
  public:
    StackUnderflow(const std::string message);
  private:
  };

  StackArray(size_t size = 100);
  StackArray(const StackArray<T>& obj) = delete;
  StackArray(StackArray<T>&& obj) noexcept;
  StackArray& operator=(const StackArray<T>& obj) = delete;
  StackArray& operator=(StackArray<T>&& obj) noexcept;

  virtual ~StackArray();

  StackArray getCopy() const;
  void push(const T& elem);
  T pop();
  bool isEmpty() const;
  bool isFull() const;
  T getTop() const;

private:
  T* array_;
  size_t top_;
  size_t size_;
  
  void swap(StackArray<T>& obj);
};


template<typename T>
inline StackArray<T>::WrongStackSize::WrongStackSize(const std::string message) :
  StackException(message)
{
}

template<typename T>
inline StackArray<T>::StackOverflow::StackOverflow(const std::string message) :
  StackException(message)
{
}

template<typename T>
inline StackArray<T>::StackUnderflow::StackUnderflow(const std::string message) :
  StackException(message)
{
}


template<typename T>
inline StackArray<T>::StackArray(size_t size) :
  size_(size),
  top_(0)
{
  try
  {
    array_ = new T[size + 1];
  }
  catch(...)
  {
    throw WrongStackSize("Wrong stack size\n");
  }
}

template<typename T>
inline StackArray<T>::StackArray(StackArray<T>&& obj) noexcept
{
  array_ = obj.array_;
  size_ = obj.size_;
  top_ = obj.top_;
  obj.array_ = nullptr;
  obj.size_ = 0;
  obj.top_ = 0;
}

template<typename T>
inline StackArray<T>& StackArray<T>::operator=(StackArray<T>&& obj) noexcept
{
  array_ = obj.array_;
  size_ = obj.size_;
  top_ = obj.top_;
  obj.array_ = nullptr;
  obj.size_ = 0;
  obj.top_ = 0;
  return *this;
}

template<typename T>
inline StackArray<T>::~StackArray()
{
  delete[] array_;
}

template<typename T>
inline StackArray<T> StackArray<T>::getCopy() const
{
  StackArray retStack(size_);
  for (int i = 1; i <= top_; i++)
  {
    retStack.push(array_[i]);
  }
  return retStack;
}

template<typename T>
inline void StackArray<T>::push(const T& elem)
{
  if (top_ == size_)
  {
    throw StackOverflow("Stack overflow\n");
  }
  else
  {
    top_++;
    array_[top_] = elem;
  }
}

template<typename T>
inline T StackArray<T>::pop()
{
  if (top_ == 0)
  {
    throw StackUnderflow("Stack underflow\n");
  }
  else
  {
    T retValue = array_[top_];
    top_--;
    return retValue;
  }
  
}

template<typename T>
inline bool StackArray<T>::isEmpty() const
{
  return (top_ == 0);
}

template<typename T>
inline bool StackArray<T>::isFull() const
{
  return (top_ == size_);
}

template<typename T>
inline T StackArray<T>::getTop() const
{
  return array_[top_];
}

template<typename T>
inline void StackArray<T>::swap(StackArray<T>& obj)
{
  std::swap(array_, obj.array_);
  std::swap(top_, obj.top_);
  std::swap(size_, obj.size_);
}

#endif /* STACK_ARRAY_H */
