#include "DoubleLinkedList.h"
#include <iostream>

DoubleLinkedList::DoubleLinkedList()
{
	this->head_ = nullptr;
	this->count_ = 0;
}

DoubleLinkedList::DoubleLinkedList(int item) {
	this->count_ = 1;
	this->head_->item_ = item;
	this->head_->next_ = nullptr;
	this->head_->prev_ = nullptr;
	tail_ = head_;
}
    
DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList& src)
{
	head_ = nullptr;
	tail_ = nullptr;
	count_ = 0;
	Node* temp = src.head_;
	while (temp != nullptr)
	{
		insertTail(temp->item_);
		temp = temp->next_;
	}
}
    
void DoubleLinkedList::insertTail(Node* x) 
{
	x->prev_ = tail_;
	if (head_ == nullptr) {
		insertHead(x);
		count_ -= 1;
	}
	tail_->next_ = x;
	x->next_ = nullptr;
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
   
void DoubleLinkedList::deleteNode(Node* x)
{
	if (x == nullptr) {
		throw ("DoubleLinkedList::deleteNode  -     ");
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

      
DoubleLinkedList::Node* DoubleLinkedList::replaceNode(DoubleLinkedList::Node* x, int item)
{
	return x;
}

    
int DoubleLinkedList::headItem() const
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem -  !");
}

int& DoubleLinkedList::headItem()
{
	if (head_ != nullptr) {
		return head_->item_;
	}
	throw ("headItem -  !");
}

      
int DoubleLinkedList::tailItem() const
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem -  !");
}
int& DoubleLinkedList::tailItem()
{
	if (tail_ != nullptr) {
		return tail_->item_;
	}
	throw ("tailItem -  !");
}

    
void DoubleLinkedList::insertHead(int item)
{            
	insertHead(new Node(item));
}


     
void DoubleLinkedList::insertTail(int item)
{           
	insertTail(new Node(item));
}

     
bool DoubleLinkedList::deleteHead()
{
	if (head_ == nullptr) {
		return 0;    
	}
	deleteNode(head_);
	return 1;        
}

     
bool DoubleLinkedList::deleteTail()
{

	return 0; 
}

       
bool DoubleLinkedList::deleteItem(const int item)
{

	return 0;
}

      
bool DoubleLinkedList::searchItem(int item)
{   
	return (searchNode(item) != nullptr);
}


     
bool DoubleLinkedList::replaceItem(int itemOld, int itemNew)
{

	return 0;
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