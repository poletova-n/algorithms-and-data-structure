#ifndef QUEUELIST_H
#define QUEUELIST_H

#include "exceptions.h"
#include "queue.h"

template <class T>
class QueueList : public Queue<T>
{
public:
		QueueList();
		QueueList(const QueueList<T>& copy);
		QueueList(QueueList<T>&& moved) noexcept;

		virtual ~QueueList();

		void enQueue(const T& elem);
		T deQueue();
		bool isEmpty();
private:
		struct Node
		{
				T elem_;
				Node* next_;
				Node(T element) :
						elem_(element),
						next_(nullptr)
				{}
		};
		Node* head_;
		size_t size_;
};

template <class T>
QueueList<T>::QueueList():
		head_(nullptr),
		size_(0)
{}

template <class T>
QueueList<T>::QueueList(const QueueList<T>& copy) :
  size_(copy.size_),
  head_(nullptr)
{
  Node* temp = copy.head_;
  while (temp->next_ != nullptr)
  {
    enQueue(temp->elem_);
    temp = temp->next_;
  }
  enQueue(temp->elem_);
}

template <class T>
QueueList<T>::QueueList(QueueList<T>&& moved) noexcept:
		head_(moved.head_),
		size_(moved.size_)
{
		moved.size_ = 0;
		moved.head_ = nullptr;
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
				T element = head_->elem_;
				delete head_;
				head_ = nullptr;
				return element;
		}
		T element = head_->elem_;
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

#endif // !QUEUELIST_H
