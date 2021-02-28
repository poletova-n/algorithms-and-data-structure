#ifndef STACK_STACKLIST_H
#define STACK_STACKLIST_H

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
    const T& pop() override;
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
    Node* temp = top_;
    while (temp->pPrev_ != nullptr)
    {
        temp = temp->pPrev_;
        delete top_;
        top_ = temp;
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
const T& StackList<T>::pop()
{
    if (size_ <= 0)
    {
        throw StackUnderflow();
    }
    else
    {
        T current = top_->data_;
        top_ = top_->pPrev_;
        size_--;
        return current;
    }
}

template<class T>
bool StackList<T>::isEmpty()
{
    return size_ == 0;
}

#endif //STACK_STACKLIST_H
