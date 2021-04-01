#ifndef LAB6_STACK_HPP
#define LAB6_STACK_HPP

template<typename T>
class Stack
{
public:
  virtual ~Stack() = default;
  virtual void push(const T& element) = 0;
  virtual T& pop() = 0;
};

#endif
