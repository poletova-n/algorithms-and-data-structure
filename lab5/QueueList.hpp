#ifndef QUEUE_QUEUELIST_HPP
#define QUEUE_QUEUELIST_HPP

#include <list>

#include "queue.hpp"
#include "exception.hpp"

template <class T>
class QueueList : public Queue<T>
{
public:

  explicit QueueList(int size = 100);
  ~QueueList() {};
  void enQueue (const T& e) override;
  const T& deQueue () override;
  bool isEmpty() override;
  void print(std::ostream &out);

private:
  std::list<int> list;
  int size_;
};

template <class T>
QueueList<T>::QueueList(int size) :
  size_(size)
{
}

template <class T>
void QueueList<T>::enQueue (const T& e) {
  list.push_front(e);
}

template <class T>
const T& QueueList<T>::deQueue() {
  T& element = list.back();
  list.pop_back();
  return element;
}

template<class T>
bool QueueList<T>::isEmpty() {
  return list.size() == 0;
}

template<class T>
void QueueList<T>::print(std::ostream &out) {
  out << "Total numder of elements: " << list.size();
  out << std::endl;
  for (auto i = list.begin(); i != list.end(); i++) {
    out << *i << " ";
  }
  out << std::endl;
}

#endif //QUEUE_QUEUELIST_HPP
