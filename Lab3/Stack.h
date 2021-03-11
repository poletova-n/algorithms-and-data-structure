#ifndef STACK_H
#define STACK_H

#include "exceptions.h"

template <class T>
class Stack 
{
public:
  virtual ~Stack() { };
  virtual const T& top() = 0;
  virtual void push(const T& element) = 0;
  virtual T pop() = 0;
  virtual bool isEmpty() = 0;
};

#endif // !STACK_H
