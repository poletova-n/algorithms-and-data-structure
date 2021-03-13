#ifndef STACKS_STACK_H
#define STACKS_STACK_H

template <class T>
class Stack
{
public:

  virtual ~Stack()
  {

  }
  virtual void push(const T& e) = 0;
  virtual const T& pop() = 0;
  virtual bool isEmpty() = 0;
};

#endif //STACKS_STACK_H
