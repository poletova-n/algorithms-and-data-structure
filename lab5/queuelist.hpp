#ifndef QUEUELIST_HPP
#define QUEUELIST_HPP

#include <cstdlib>
#include <list>
#include <ostream>
#include "queue.hpp"
#include "exceptions.hpp"

template<class T>
class QueueList : public Queue<T> {
public:
  QueueList() = default;
  QueueList(const QueueList<T>& src);
  QueueList(QueueList<T>&& src) noexcept;
  ~QueueList() override = default;
  void push(const T& e) override;
  void pop() override;
  [[nodiscard]] bool isEmpty() const override;
  T& front() override;
  T& back() override;
  void print(std::ostream& ostream) const override;

private:
  std::list<T> list_;
};

template<class T>
QueueList<T>::QueueList(const QueueList<T>& src):
  list_(src.list_)
{}

template<class T>
QueueList<T>::QueueList(QueueList<T>&& src) noexcept:
  list_(std::move(src.list_))
{}

template<class T>
void QueueList<T>::push(const T& e)
{
  list_.push_back(e);
}

template<class T>
void QueueList<T>::pop()
{
  if (list_.size() == 0) {
    throw std::out_of_range("Out of range!");
  }
  list_.pop_front();
}

template<class T>
bool QueueList<T>::isEmpty() const
{
  return list_.empty();
}

template<class T>
T& QueueList<T>::front()
{
  return list_.front();
}

template<class T>
T& QueueList<T>::back()
{
  return list_.back();
}
template<class T>
void QueueList<T>::print(std::ostream& ostream) const
{
  ostream << "Queue{list_=[";
  for (auto i = list_.begin(); i != list_.end(); ++i) {
    ostream << *i << ';';
  }
  ostream << "], size_=" << list_.size() << "}\n";
}

#endif
