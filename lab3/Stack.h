#ifndef STACK_H
#define STACK_H

#include <iostream>

template <typename T>
class Stack
{
public:
  class StackException
  {
  public:
    StackException(const std::string message);
    std::string getMessage() const;
  private:
    std::string message_;
  };

  virtual ~Stack() = default;

  virtual void push(const T& e) = 0;
  virtual T pop() = 0;
  virtual bool isEmpty() const = 0;
  virtual bool isFull() const = 0;
  virtual T getTop() const = 0;
};


template<typename T>
inline Stack<T>::StackException::StackException(const std::string message) :
  message_(message)
{
}

template<typename T>
inline std::string Stack<T>::StackException::getMessage() const
{
  return message_;
}

#endif /* STACK_H */
