#include <iostream>
#include "DoubleLinkedList.h"

void DoubleLinkedList::deleteNode(Node* x)
{
	if (x == nullptr) {
		throw ("DoubleLinkedList::deleteNode - неверно задан адрес удаляемого узла");
	}
	if (x->prev_ != nullptr) {
		(x->prev_)->next_ = x->next_;
	}
	else {
		head_ = x->next_;
	}
	if (x->next_ != nullptr) {
		(x->next_)->prev_ = x->prev_;
	}
	else {
		tail_ = x->prev_;
	}
	delete x;
	count_--;
}
DoubleLinkedList::Node* DoubleLinkedList::searchNode(int item)
{
	Node* x = head_;
	while (x != nullptr && x->item_ != item) {
		x = x->next_;
	}
	return x;
}
void DoubleLinkedList::outAll()
{
	Node* current = head_;
	while (current != nullptr) {
		std::cout << current->item_ << ' ';
		current = current->next_;
	}
	std::cout << std::endl;
}
bool DoubleLinkedList::searchItem(int item)
{
	return (searchNode(item) != nullptr);
}

DoubleLinkedList DoubleLinkedList::copy()
{
	DoubleLinkedList result = *this;
	return result;
}

DoubleLinkedList::DoubleLinkedList (const DoubleLinkedList& list)
{
	count_ = list.count_;
	head_ = list.head_;
	tail_ = list.tail_;
}

DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList& s)
{
	if (this != &s)
	{
		DoubleLinkedList(s).swap(*this);
	}

	return *this;
}
void DoubleLinkedList::swap(DoubleLinkedList& s) throw()
{
	std::swap(this->count_, s.count_);
	std::swap(this->head_, s.head_);
	std::swap(this->tail_, s.tail_);
}

DoubleLinkedList::DoubleLinkedList (DoubleLinkedList&& list) noexcept
{
	this->count_ = list.count_;
	list.count_ = 0;

	this->head_ = list.head_;
	list.head_ = NULL;

	this->tail_ = list.tail_;
	list.tail_ = NULL;
}

DoubleLinkedList& DoubleLinkedList::operator=(DoubleLinkedList&& other) noexcept
{
	if (this != &other)
	{
		delete[] this->head_;
		this->head_ = other.head_;
		other.head_ = nullptr;

		delete[] this->tail_;
		this->tail_ = other.tail_;
		other.tail_ = nullptr;

		delete &other.count_;
		this->count_ = other.count_;
		other.count_ = NULL;
	}
	return *this;
}

void DoubleLinkedList::insertTail(Node* x)
{
	x->prev_ = tail_;
	if (tail_ != nullptr) {
		tail_->next_ = x;
	}
	else {
		head_ = x;
	}
	tail_ = x;
	count_++;
}
void DoubleLinkedList::insertHead(Node* x)
{
	x->next_ = head_;
	if (head_ != nullptr) {
		head_->prev_ = x;
	}
	else {
		tail_ = x;
	}
	head_ = x;
	count_++;
}
void DoubleLinkedList::insertTail(int item)
{
	insertTail(new Node(item));
}
void DoubleLinkedList::insertHead(int item)
{
	insertHead(new Node(item));
}

DoubleLinkedList::Node* DoubleLinkedList::replaceNode(Node* x, int item)
{
	x->item_ = item;
	return x;
}

bool DoubleLinkedList::deleteTail()
{
	if (tail_ == nullptr) {
		return 0;
	}
	deleteNode(tail_);
	return 1;
}
bool DoubleLinkedList::deleteHead()
{
	if (head_ == nullptr) {
		return 0;
	}
	deleteNode(head_);
	return 1;
}

bool DoubleLinkedList::deleteItem(const int item)
{
	deleteNode(searchNode(item));

	return 0;
}

bool DoubleLinkedList::replaceItem(int itemOld, int itemNew)
{
	while (head_ != NULL)
	{
		Node* node = searchNode(itemOld);
		if (node == nullptr)
		{
			return false;
		}
		replaceNode(node, itemNew);

	}
	return true;
}

std::ostream& operator<<(std::ostream& os, const DoubleLinkedList& list)
{
	DoubleLinkedList::Node* p;
	for (p = list.head_; p != NULL; p = p->next_)
		os << p->item_ << ' ';
	os << std::endl;

	return os;
}

bool DoubleLinkedList::operator==(const DoubleLinkedList& list) const
{
	if (count_ != list.count_) //if sizes aren't equal, return false
	{
		return false;
	}
	if (head_ == nullptr && list.head_ == nullptr)
	{
		return true;
	}

	Node* p = head_;
	Node* q = list.head_;

	while (p != NULL /*nullptr*/)
	{
		if (p->item_ != q->item_)
		{
			return false;
		}
		p = p->next_;
		q = q->next_;
	}
	return true;
}

void DoubleLinkedList::unite(DoubleLinkedList& other)
{
	if (other.head_ != NULL)
	{
		if (tail_ != NULL)
		{
			Node* temp = tail_;
			tail_->next_ = other.head_;
			other.head_->prev_ = temp;
		}
		else
		{
			head_ = other.head_;
		}
		tail_ = other.tail_;
		count_ += other.count_;
		other.head_ = NULL;
		other.tail_ = NULL;
		other.count_ = 0;
	}
}
