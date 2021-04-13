#ifndef QUEUELIST_HPP
#define QUEUELIST_HPP

#include "exception.hpp"
#include "queue.hpp"

template <class T>
class QueueList : public Queue<T>
{
public:
	QueueList();
	QueueList(const QueueList<T>& scr);

	virtual ~QueueList();

	void enQueue(const T& element);
	T deQueue();
	bool isEmpty();
private:
	struct Node
	{
		T element_;
		Node* next_;
		Node(T element) :
			element_(element),
			next_(nullptr)
		{}
	};
	Node* head_;
	size_t size_;
};

template <class T>
QueueList<T>::QueueList() :
	head_(nullptr),
	size_(0)
{}

template <class T>
QueueList<T>::QueueList(const QueueList<T>& scr) :
	size_(scr.size_)
{
	Node* current = scr.head_;
	while (current->next_ != nullptr)
	{
		enQueue(current->element_);
		current = current->next_;
	}
	enQueue(current->element_);
}

template <class T>
void QueueList<T>::enQueue(const T& element)
{
	if (head_ == nullptr)
	{
		head_ = new Node(element);
		++size_;
		return;
	}
	Node* current = this->head_;
	while (current->next_ != nullptr)
	{
		current = current->next_;
	}
	current->next_ = new Node(element);
	++size_;
}

template <class T>
T QueueList<T>::deQueue()
{
	if (head_ == nullptr)
	{
		throw QueueUnderFlow();
	}
	if (size_ == 1)
	{
		T element = head_->element_;
		delete head_;
		head_ = nullptr;
		return element;
	}
	T element = head_->element_;
	Node* temp = head_->next_;
	delete head_;
	head_ = temp;
	--size_;
	return element;
}

template <class T>
QueueList<T>::~QueueList()
{
	Node* next = head_;
	while (next != nullptr)
	{
		next = head_->next_;
		delete head_;
		head_ = next;
	}
}

template <class T>
bool QueueList<T>::isEmpty()
{
	return (head_ == nullptr);
}

#endif
