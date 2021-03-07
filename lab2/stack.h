#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
public:
  virtual ~Stack() {};
  virtual void push(const T& element) = 0;
  virtual const T& pop() = 0;
  virtual bool isEmpty() = 0; 
  virtual const T& peek() = 0;
};

#endif 
