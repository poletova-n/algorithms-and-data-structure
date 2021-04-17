#ifndef stack_h
#define stack_h

template <class T>
class Stack
{
public:
    
  virtual ~Stack() = default;
  virtual void push(const T& e) = 0;
  virtual T pop() = 0;
  [[nodiscard]] virtual bool isEmpty() const = 0;
};

#endif
