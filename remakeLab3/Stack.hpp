#ifndef STACK_HPP
#define STACK_HPP

#include "exception.hpp"

template <class T>
class Stack
{
public:
  virtual ~Stack() = default;;
  virtual const T& top() = 0;
  virtual void push(const T& element) = 0;
  virtual T pop() = 0;
  virtual bool isEmpty() = 0;
};

#endif