#ifndef STACK_LIST
#define STACK_LIST

#include "stack.h"
#include "exception.h"

#include<iostream>

template <class T>
class StackList: public Stack<T>
{
public:
	StackList();
	~StackList() override;
	void push(const T& element) override;
	T pop() override;
	bool isEmpty() override;

private:
    class Node
    {
    public:
        Node* pPrev_;
        T data_;
        Node(T data, Node* pPrev = nullptr)
        {
            data_ = data;
            pPrev_ = pPrev;
        }
       
    };

    int size_;
    Node* top_;
};

template<class T>
StackList<T>::StackList()
{
    size_ = 0;
    top_ = nullptr;
}

template<class T>
StackList<T>::~StackList()
{
    while (size_ != 0)
    {
        pop();
    }
}

template<class T>
void StackList<T>::push(const T& element)
{
    if (top_ == nullptr)
    {
        top_ = new Node(element);
        size_++;
    }
    else
    {
        Node* temp = new Node(element, top_);
        top_ = temp;
        size_++;
    }
}

template<class T>
T StackList<T>::pop()
{
    if (size_ <= 0)
    {
        throw StackUnderflow();
    }
    else 
    {
        T current = top_->data_;
        Node* temp = top_;
        top_ = top_->pPrev_;
        delete temp;
        size_--;
        return current;
    }
}

template<class T>
bool StackList<T>::isEmpty()
{
	return size_ == 0;
}

#endif 

