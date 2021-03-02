#ifndef STACK_LIST_H
#define STACK_LIST_H

#include "stack.h"
#include "exception.h"

template <class T>
struct Node
{
public:
  Node(T data) : data(data), next(nullptr) {};
  T data;
  Node<T>* next;
};

template <class T>
class StackList : public Stack<T>
{
public:
    StackList();
    StackList(const StackList<T>& src);
    virtual ~StackList() {};
    void push(const T& element);
    const T& pop();
    bool isEmpty()
    {
        return top == nullptr;
    }
    const T& peek();
private:    

    Node<T>* top; // вершина стека, элемент занесенный в стек последним
    int size; 
};

template <class T>
StackList<T>::StackList()
{
  size = 0;
  top = nullptr;
}

template <class T>
StackList<T>::StackList(const StackList<T>& src)
{
    this->size = src.size;
    this->top = src.top;
}

template <class T>
void StackList<T>::push(const T& element)
{
  if (size==0)
  {
    top = new Node<T>(element);
  }
  else
   {    
    Node<T> *cur = new Node<T>(element);
    cur->next = top;
    top = cur;
   }
    size++;
}

template <class T>
const T& StackList<T>::pop()
{
  if (!isEmpty()) 
  {
    T temp = top->data;
    top = top->next;
    size--;
    return temp;
  }
  throw StackUnderflow(); 
}

template<class T>
const T& StackList<T>::peek()
{
  if (top == nullptr)
  {
    throw StackUnderflow();
  }
  return top->data;
}

#endif
