#ifndef STACK_H
#define STACK_H

template<class T>
class Stack
{
public:
  virtual ~Stack() = default;
  virtual void push(const T &element) = 0;
  virtual T pop() = 0;
  virtual bool isEmpty() = 0;
};

#endif