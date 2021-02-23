#ifndef STACKLINKEDLIST_H
#define STACKLINKRDLIST_

#include"my_exception.h"
#include"stack.h"

template <class T>
class StackLinkedList :public Stack<T>
{
public:
	StackLinkedList(): top_(nullptr) {}
	StackLinkedList(const StackLinkedList<T>& sll) : top_(sll.top_) {}
	StackLinkedList(StackLinkedList<T>&& sll) : top_(sll.top_)
	{
		sll.top_ = nullptr;
	}
	~StackLinkedList()
	{
		delete top_;
	}
	StackLinkedList<T>& operator=(const StackLinkedList<T>&) = delete;
	StackLinkedList<T>& operator=(StackLinkedList<T>&&) = delete;
	void push(const T&) override;
	T pop();
	bool isEmpty();
private:

	struct Node
	{
		T data_;
		Node* next_;
		Node* pre_;
		Node(T data) : data_(data), next_(nullptr), pre_(nullptr) {}
	};
	Node* top_;
};

template <class T>
void StackLinkedList<T>::push(const T& number)
{
	Node* node = new Node(number);
	if (top_ == nullptr)
	{
		top_ = node;
	}
	else
	{
		top_->next_ = node;
		node->pre_ = top_;
		top_ = node;
	}
}
template <class T>
T StackLinkedList<T>::pop()
{
	if (top_==nullptr)
	{
		throw StackUnderflow();
	}
	else
	{
		if (top_->pre_ == nullptr)
		{
			T temp = top_->data_;
			top_ = nullptr;
			return temp;
		}
		else
		{
			T temp = top_->data_;
			top_ = top_->pre_;
			top_->next_->pre_ = nullptr;
			top_->next_ = nullptr;
			return temp;
		}
	}
}
template <class T>
bool StackLinkedList<T>::isEmpty()
{
	return top_ == nullptr;
}

#endif
