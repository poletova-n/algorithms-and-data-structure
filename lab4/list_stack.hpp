#ifndef LIST_STACK_HPP
#define LIST_STACK_HPP

#include "exceptions.hpp"
#include "stack.hpp"

template<class T>
class StackList : public Stack<T>
{
public:
  StackList();
  ~StackList() override;
  void push(const T& arg) override;
  T pop() override;
  T get_top();
  bool is_empty() override;
private:
  struct Node
  {
    T value_;
    Node* prev_;

    Node(T newValue, Node* prev) :
    value_(newValue), prev_(prev)
    {}
  };
  Node* top_;
  int size_;
};

template<class T>
StackList<T>::StackList() : 
  size_(0),
  top_(nullptr){}

template<class T>
bool StackList<T>::is_empty() {
  if (size_ == 0) {
    return true;
  }
  else {
    return false;
  }
}
 template<class T>
 T StackList<T>::pop() {
   if(size_<=0) {
     throw StackUnderflow();
   }
   size_ --;
   T tmp_val = top_->value_;
   top_ = top_->prev_;
   return tmp_val;
}

 template<class T>
 void StackList<T>::push(const T& arg) {
   Node* tmp = new Node(arg, top_);
   top_ = tmp;
   size_++;
 }

 template<class T>
 T StackList<T>::get_top() {
   return top_->value_;
 }

 template<class T>
 StackList<T>::~StackList(){
   while (!is_empty()){
     pop();
   }
 }
#endif