#ifndef STACK_HPP
#define STACK_HPP

template <class T>
class Stack {
public:
  virtual ~Stack() = default;
  virtual void push(const T& arg) = 0;
  virtual T pop() = 0;
  virtual bool is_empty() = 0;
};

#endif