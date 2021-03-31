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
  virtual T getTop() = 0;
  virtual void deleteTop() = 0;
  virtual size_t getSize() = 0;
};

#endif