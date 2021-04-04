#ifndef LAB2_STACKLIST_HPP
#define LAB2_STACKLIST_HPP

#include "stack.hpp"
#include "exceptionS.hpp"

template <class T>
class StackList : public Stack<T>
{
public:
    StackList();
    virtual ~StackList();
    void push(const T& e);
    const T& pop();
    bool isEmpty() { return top == 0; }
private:
    struct  Node
    {
        T val;
        Node *prev;
        Node(T val_, Node *prev_) :
                val(val_), prev(prev_){}
    };
    Node* top;
    int size;
};

template <class T>
StackList<T>::StackList(){
  try{
    size = 0;
  }
  catch (...) {
    throw WrongStackSize();
  }
  top = nullptr;
}

template<class T>
StackList<T>::~StackList(){
  while(size != 0)
  {
    pop();
  }
}
template <class T>
void StackList<T>::push(const T& e)
{
  Node *temp = new Node(e, top);
  top = temp;
  size++;
}
template <class T>
const T& StackList<T>::pop()
{
  if (top == nullptr)
    throw StackUnderflow();
  size--;
  Node* temp = top;
  top = top->prev;
  return temp->val;
}

#endif
