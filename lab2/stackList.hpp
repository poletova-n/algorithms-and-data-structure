#ifndef STACKLIST_HPP
#define STACKLIST_HPP

#include <list>
#include "stack.hpp"

template <class T>
class StackList : public Stack<T> {
public:
  StackList() = default;

  StackList(const StackList<T>& src);

  ~StackList() = default;

  void push(const T &e) override;

  T pop() override;

  [[nodiscard]] bool isEmpty() const override;

private:
  std::list<T> list_;
};

template <class T>
StackList<T>::StackList(const StackList<T> &src)
{
  list_ = src.list_;
}

template <class T> void StackList<T>::push(const T &e)
{
  list_.push_back(e);
}

template <class T>
T StackList<T>::pop()
{
  if (list_.size() == 0) {
    throw StackUnderflow();
  }
  T temp1 = list_.back();
  list_.pop_back();
  return temp1;
}

template <class T>
bool StackList<T>::isEmpty() const
{
  return list_.empty();
}

#endif
