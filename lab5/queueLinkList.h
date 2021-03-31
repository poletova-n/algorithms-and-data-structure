#ifndef QUEUELINKLIST_H
#define QUEUELINKLIST_H

#include <iostream>

#include "myException.h"
#include "queue.h"

template<class T>
class QueueLinkList : public Queue<T>
{
private:
	struct Node
	{
		T data_;
		Node* next_;
		Node* pre_;
		Node(T data): data_(data), next_(nullptr), pre_(nullptr) {}
	};
	Node* head_;
	Node* tail_;

public:
	QueueLinkList(): head_(nullptr), tail_(nullptr) {}
	QueueLinkList(QueueLinkList<T>&&);
	~QueueLinkList();
	QueueLinkList<T>& operator=(const QueueLinkList<T>&) = delete;
	QueueLinkList<T>& operator=(QueueLinkList<T>&&) noexcept;
	void enQueue(const T&) override;
	T deQueue() override;
	bool isEmpty() override;
	
	QueueLinkList(const QueueLinkList<T>&);
};

template<class T>
QueueLinkList<T>::QueueLinkList(QueueLinkList<T>&& list):
	head_(list.head_),
	tail_(list.tail_)
{
	list.head_ = nullptr;
	list.tail_ = nullptr;
}

template<class T>
QueueLinkList<T>::~QueueLinkList()
{
	while (head_ != nullptr)
	{
		if (head_ == tail_)
		{
			delete head_;
			head_ = tail_ = nullptr;
		}
		else
		{
			head_ = head_->pre_;
			delete head_->next_;
			head_->next_ = nullptr;
		}
	}
}

template<class T>
QueueLinkList<T>& QueueLinkList<T>::operator=(QueueLinkList<T>&& list) noexcept
{
	if (this == &list)
	{
		return *this;
	}
	if (head_ != nullptr)
	{
		while (head_ != nullptr)
		{
			if (head_ == tail_)
			{
				delete head_;
				head_ = tail_ = nullptr;
			}
			else
			{
				head_ = head_->pre_;
				delete head_->next_;
				head_->next_ = nullptr;
			}
		}
		if (list->head_ == nullptr)
		{
			return *this;
		}
		
	}
	head_ = list.head_;
	tail_ = list.tail_;
	list.head_ = nullptr;
	list.tail_ = nullptr;
	return *this;
}

template<class T>
void QueueLinkList<T>::enQueue(const T& data)
{
	if (head_ == nullptr)
	{
		Node* temp = new Node(data);
		head_ = tail_ = temp;
	}
	else
	{
		Node* temp = new Node(data);
		tail_->pre_ = temp;
		temp->next_ = tail_;
		tail_ = temp;
	}
}

template<class T>
T QueueLinkList<T>::deQueue()
{
	if (head_ == nullptr)
	{
		throw QueueUnderflow();
	}
	else
	{
		if (head_ == tail_)
		{
			T data = head_->data_;
			delete head_;
			head_ = tail_ = nullptr;
			return data;
		}
		else
		{
			Node* temp = head_;
			head_ = head_->pre_;
			temp->pre_ = nullptr;
			head_->next_ = nullptr;
			T data = temp->data_;
			delete temp;
			return data;
		}
	}
}

template<class T>
bool QueueLinkList<T>::isEmpty()
{
	return head_ == nullptr;
}

template<class T>
QueueLinkList<T>::QueueLinkList(const QueueLinkList<T>& list)
{
	if (list.head_ == nullptr)
	{
		head_ = tail_ = nullptr;
	}
	else
	{
		for (Node* i = list.head_; i != nullptr; i = i->pre_)
		{
			this->enQueue(i->data_);
		}
	}
	
}

#endif
