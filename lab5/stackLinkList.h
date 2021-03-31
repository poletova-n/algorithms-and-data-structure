#ifndef STACKLINKEDLIST_H
#define STACKLINKRDLIST_

#include "myException.h"

template <class T>
class StackLinkedList
{
public:
	StackLinkedList() : top_(nullptr) {}
	StackLinkedList(const StackLinkedList<T>&);
	StackLinkedList(StackLinkedList<T>&& sll) : top_(sll.top_)
	{
		sll.top_ = nullptr;
	}
	~StackLinkedList();
	StackLinkedList<T>& operator=(const StackLinkedList<T>&) = delete;
	StackLinkedList<T>& operator=(StackLinkedList<T>&&);
	void push(const T&);
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



template<class T>
StackLinkedList<T>::StackLinkedList(const StackLinkedList<T>& sll)
{
	if (sll.top_ == nullptr)
	{
		top_ = nullptr;
	}
	else
	{
		Node* temp = sll.top_;
		while (temp.pre_ != nullptr)
		{
			temp = temp->pre_;
		}
		for (; temp->next != nullptr; temp = temp->next_)
		{
			Node* node = new Node(temp->data_);
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
	}
}

template<class T>
StackLinkedList<T>::~StackLinkedList()
{
	while (top_ != nullptr)
	{
		if (top_->pre_ == nullptr)
		{
			delete top_;
			top_ = nullptr;
		}
		else
		{
			top_ = top_->pre_;
			delete top_->next_;
			top_->next_ = nullptr;
		}
	}
}

template<class T>
StackLinkedList<T>& StackLinkedList<T>::operator=(StackLinkedList<T>&& list)
{
	if (this == &list)
	{
		return *this;
	}
	if (top_ != nullptr)
	{
		while (top_ != nullptr)
		{
			if (top_->pre_ == nullptr)
			{
				delete top_;
				top_ = nullptr;
			}
			else
			{
				top_ = top_->pre_;
				delete top_->next;
				top_->next_ = nullptr;
			}
		}
		if (list->top_ == nullptr)
		{
			return *this;
		}
	}
	top_ = list.top_;
	list.top_ = nullptr;
}

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
	if (top_ == nullptr)
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
