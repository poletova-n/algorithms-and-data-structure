#include <iostream>
#include "list.h"

List::List() {
	size_ = 0;
	head_ = nullptr;
}
List::List(int value) {
	size_ = 1;
	head_ = new Node(value);
}
List::List(Node* src) {
	size_ = 1;
	head_ = src;
}

List::List(List* src) {
	head_ = nullptr;
	size_ = 0;
	Node* temp = src->head_;
	while (temp != nullptr)
	{
		insert(temp->value_);
		temp = temp->next_;
	}
}

List::List(List&& src) noexcept {
	if (this != &src)
	{
		List temp(&src);
		head_ = temp.head_;
		size_ = temp.size_;
		src.~List();
		temp.head_ = nullptr;
		temp.size_ = NULL;
	}
}
List::~List() {
	Node* next = head_;
	while (next != nullptr) {
		next = head_->next_;
		delete head_;
		head_ = next;
	}
}
bool List::operator==(List& src) {
	if (size_ != src.size_) {
		return 0;
	}
	else {
		Node* left = head_;
		Node* right = src.head_;
		for (int i = 0; i < size_; i++) {
			if (right->value_ != left->value_) {
				return 0;
			}
		}
	}
	return 1;
}
void List::operator+=(int item) {
	Node* temp = new Node(item);
	this->insert_n(temp);
}
std::ostream& operator<< (std::ostream& out, List& src)
{
	src.outAll();
	return out;

}

void List::outAll() {
	Node* current = head_;
	while (current != nullptr) {
		std::cout << current->value_ << ' ';
		current = current->next_;
	}
	std::cout << std::endl;
}

void List::insert_n(Node* src) {
	insert(src->value_);
}

void List::insert(int value) {
	if (head_ == nullptr) {
		head_ = new Node(value);
	}
	else {
		Node* current = this->head_;
		while (current->next_ != nullptr) {
			current = current->next_;
		}
		current->next_ = new Node(value);
	}
	size_ += 1;
}

List operator| (List& src1, List& src2)
{
	List list3;
	int count1 = src1.size_;
	List::Node* head1 = src1.head_;
	for (int i = 0; i < count1; i++)
	{
		list3.insert(head1->value_);
		head1 = head1->next_;
	}
	int count2 = src2.size_;
	List::Node* head2 = src2.head_;
	for (int i = 0; i < count2; i++)
	{
		if (!list3.searchItem(head2->value_))
		{
			list3.insert(head2->value_);
		}
		head2 = head2->next_;
	}
	return list3;
}

List operator& (List& src1, List& src2)
{
	List list3 = new List();
	int count1 = src1.size_;
	List::Node* head1 = src1.head_;
	for (int i = 0; i < count1; i++)
	{
		if (src2.searchItem(head1->value_))
		{
			list3.insert(head1->value_);
		}
		head1 = head1->next_;
	}
	return list3;
}
List::Node* List::searchNode(int item) {
	Node* x = head_;
	while (x != nullptr && x->value_ != item) {
		x = x->next_;
	}
	return x;
}

bool List::searchItem(int item) {
	return (searchNode(item) != nullptr);
}

void List::merge(List& src) {
	Node* x = src.head_;
	while (x != nullptr) {
		insert(x->value_);
		x = x->next_;
	}
	return;
}