#ifndef CPP_PROJECTS_STACK_HPP
#define CPP_PROJECTS_STACK_HPP

template<class T>
class Stack
{
public:
  virtual ~Stack() = default;

  [[maybe_unused]] virtual void push(const T&) = 0;

  [[maybe_unused]] virtual const T& pop() = 0;

  [[maybe_unused]] virtual bool isEmpty() = 0;

  [[maybe_unused]] virtual T& top() const = 0;
};

#endif
