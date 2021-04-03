#ifndef QUEUE_HPP
#define QUEUE_HPP

template<class T>
class Queue {
public:
  virtual ~Queue() = default;

  virtual void push(const T&) = 0;

  virtual void pop() = 0;

  [[nodiscard]] virtual bool isEmpty() const = 0;

  virtual T& front() = 0;

  virtual T& back() = 0;

  virtual void print(std::ostream&) const = 0;
};

#endif
