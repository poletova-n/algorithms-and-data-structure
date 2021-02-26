#ifndef STACKS_H
#define STACKS_H

template<class T>
class Stack
{
public:
  virtual ~Stack() = default;
  virtual void push(const T& data) = 0;
  virtual const T& pop() = 0;
  virtual bool isEmpty() = 0;
};
#endif
