#include "List.h"


void List::insert(Node* node)
{
	if (this->head_ == nullptr) // checking for empty list
	{
		this->head_ = node;
		count_++;
		return;
	}
	Node* current = head_; // starting with the head of the list
	while (current->next_ != nullptr && current->next_->data_ <= node->data_) // searching for index to insert element
	{
		current = current->next_;
	}
	if (current == head_) // if we hadn't moved around the list, checking for position to insert (1st or 2nd elem)
	{
		if (current->data_ > node->data_) {
			node->next_ = head_;
			head_ = node;
			count_++;
		}
		else if (current->data_ < node->data_) {
			node->next_ = head_->next_;
			head_->next_ = node;
			count_++;
		}
		return;
	}
	if (current->next_ != nullptr) // if we had moved around the list, we are checking for repeative elements
	{
		if (current->next_->data_ != node->data_ && current->data_ != node->data_) {
			node->next_ = current->next_;
			current->next_ = node;
			count_++;
		}
		return;
	}
	else if (current->next_ == nullptr && current->data_ == node->data_) { // if the new element is found in our list, do nothing 
		return;
	}
	count_++;
	current->next_ = node;
}

List::List()
{
	this->head_ = nullptr;
	this->count_ = 0;
}

List::List(List&& copy) noexcept
{
	this->head_ = copy.head_;
	this->count_ = copy.count_;
	copy.head_ = nullptr;
	copy.count_ = 0;
}

List::List(const List& copy) {
	Node* temp = copy.head_;
	while (temp != nullptr) {
		this->insert(new Node(temp->data_));
		temp = temp->next_;
	}
}

List::~List() 
{
	Node* next = this->head_; // freeing the memory from the head of the list with the delete function
	while (next != nullptr) {
		next = head_->next_;
		delete head_;
		head_ = next;
	}
}

void List::operator+=(int data) // creating new temporary Node based on data and insert it
{
	Node* temp = new Node(data);
	this->insert(temp);
}

std::ostream& operator<<(std::ostream& stream, const List& list)
{
	List::Node* current = list.head_;
	while (current != nullptr) {
		stream << current->data_ << " ";
		current = current->next_;
	}
	return stream;
}

bool List::operator==(const List& copy) 
{
	if (this->count_ != copy.count_) return false; // checking for length
	Node* temp1 = this->head_;
	Node* temp2 = copy.head_;
	while (temp1->next_ != nullptr && temp2->next_ != nullptr) { // if even one of the elements is not the same, return false
		if (temp1->data_ != temp2->data_) return false;
		temp1 = temp1->next_;
		temp2 = temp2->next_;
	}
	return true; // return true if all the tests passed successfully
}

List operator&(const List& first, const List& second) // checking for repeative elements and insertthem
{
	List temp;
	List::Node* current = first.head_;
	while (current != nullptr) {
		List::Node* current2 = second.head_;
		while (current2 != nullptr) {
			if (current->data_ == current2->data_) {
				temp.insert(new List::Node(current->data_));
				break;
			}
			current2 = current2->next_;
		}
		current = current->next_;
	}
	return temp;
}

List operator|(const List& first, const List& second) // insert all the elements, but insert function will check for repeative ones.
{
	List temp;
	List::Node* current = first.head_;
	while (current != nullptr) {
		temp.insert(new List::Node(current->data_));
		current = current->next_;
	}
	current = second.head_;
	while (current != nullptr) {
		temp.insert(new List::Node(current->data_));
		current = current->next_;
	}
	return temp;
}

void List::merge(List& param) // inserting elements and clearing param list.
{ 
	Node* current = param.head_;
	while (current != nullptr) {
		this->insert(new List::Node(current->data_));
		current = param.head_->next_;
		delete param.head_;
		param.head_ = current;
	}
}


