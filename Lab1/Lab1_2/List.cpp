#include "List.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& src) { // 
	this->head_ = nullptr;
	this->tail_ = nullptr;
	this->count_ = 0;
	Node* temp = src.head_;
	while (temp != nullptr) {
		this->insert(new Node(temp->data_));
		temp = temp->next_;
	}
}

DoubleLinkedList::DoubleLinkedList(DoubleLinkedList&& copy) noexcept
{
	this->head_ = copy.head_;
	this->count_ = copy.count_;
	this->tail_ = copy.tail_;
	copy.head_ = nullptr;
	copy.count_ = 0;
	copy.tail_ = nullptr;
}

DoubleLinkedList::~DoubleLinkedList()
{
	Node* current = nullptr; 
	Node* next = head_;
	while (next != nullptr) { 
		current = next;
		next = next->next_;  
		delete current;      
	}
}

void DoubleLinkedList::operator+=(int data)
{
	Node* temp = new Node(data);
	this->insert(temp);
}

bool DoubleLinkedList::operator==(const DoubleLinkedList& src) 
{
	if (this->count_ != src.count_) return false; // checking for length
	Node* current = this->head_;
	Node* current2 = src.head_;
	while (current->next_ != nullptr && current2->next_ != nullptr) { // if even one of the elements is not the same, return false
		if (current->data_ != current2->data_) return false;
		current = current->next_;
		current2 = current2->next_;
	}
	return true; // return true if all the tests passed successfully
}

void DoubleLinkedList::merge(DoubleLinkedList& param)
{
	Node* current = param.head_;
	while (current != nullptr) {
		this->insert(new DoubleLinkedList::Node(current->data_));
		current = param.head_->next_;
		delete param.head_;
		param.head_ = current;
	}
}

void DoubleLinkedList::insert(Node* node) {
	if (this->head_ == nullptr) // checking for empty list
	{
		this->head_ = node;
		this->tail_ = node;
		count_++;
		return;
	}
	if (this->head_ == this->tail_) {
		if (node->data_ > this->head_->data_) {
			this->tail_ = node;
			this->tail_->prev_ = this->head_;
			this->head_->next_ = this->tail_;
			this->count_++;
			return;
		}
		else if (node->data_ == this->head_->data_) {
			return;
		}
		else {
			this->head_ = node;
			this->tail_->prev_ = this->head_;
			this->head_->next_ = this->tail_;
			this->count_++;
			return;
		}
	}
	Node* current = head_; // starting with the head of the list
	while (current->next_ != nullptr && current->next_->data_ <= node->data_) // searching for index to insert element
	{
		current = current->next_;
	}
	if (current == head_) // if we hadn't moved around the list, checking for position to insert (1st or 2nd elem)
	{
		if (current->data_ > node->data_) {
			head_->prev_ = node;
			node->next_ = head_;
			head_ = node;
			count_++;
		}
		else if (current->data_ < node->data_) {
			node->next_ = head_->next_;
			head_->next_->prev_ = node;
			head_->next_ = node;
			node->prev_ = head_->next_;
			count_++;
		}
		return;
	}
	if (current->next_ != nullptr) // if we had moved around the list, we are checking for repeative elements
	{
		if (current->next_->data_ != node->data_ && current->data_ != node->data_) {
			node->next_ = current->next_;
			current->next_->prev_ = node;
			current->next_ = node;
			node->prev_ = current;
			count_++;
		}
		return;
	}
	else if (current->next_ == nullptr && current->data_ == node->data_) { // if the new element is found in our list, do nothing 
		return;
	}
	count_++;
	current->next_ = node;
	node->prev_ = current;
	this->tail_ = node;
}

std::ostream& operator<<(std::ostream& stream, const DoubleLinkedList& list)
{
	DoubleLinkedList::Node* current = list.head_;
	while (current != nullptr) {
		stream << current->data_ << " ";
		current = current->next_;
	}
	return stream;
}

DoubleLinkedList operator&(const DoubleLinkedList& first, const DoubleLinkedList& second)
{
	DoubleLinkedList temp;
	DoubleLinkedList::Node* current = first.head_;
	while (current != nullptr) {
		DoubleLinkedList::Node* current2 = second.head_;
		while (current2 != nullptr) {
			if (current->data_ == current2->data_) {
				temp.insert(new DoubleLinkedList::Node(current->data_));
				break;
			}
			current2 = current2->next_;
		}
		current = current->next_;
	}
	return temp;
}

DoubleLinkedList operator|(const DoubleLinkedList& first, const DoubleLinkedList& second)
{
	DoubleLinkedList temp;
	DoubleLinkedList::Node* current = first.head_;
	while (current != nullptr) {
		temp.insert(new DoubleLinkedList::Node(current->data_));
		current = current->next_;
	}
	current = second.head_;
	while (current != nullptr) {
		temp.insert(new DoubleLinkedList::Node(current->data_));
		current = current->next_;
	}
	return temp;
}


