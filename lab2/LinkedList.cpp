#include "LinkedList.h"
#include <iostream>

std::ostream& operator<<(std::ostream& os, const SinglyLinkedOrderedList& list)
{
	SinglyLinkedOrderedList::Node* p;
	for (p = list.head_; p != NULL; p = p->next_)
    os << p->item_ << ' ';
	os << std::endl;

	return os;
}

void SinglyLinkedOrderedList::insertNode(Node* x)
{

	if (head_ == nullptr)
	{
		head_ = x;
	}
	else
	{
		Node* temp = head_;
		Node* prev = nullptr;

		while (temp != nullptr)
		{
			if (temp->item_ > x->item_)
			{
				break;
			}
			else
			{
				prev = temp;
				temp = temp->next_;
			}
		}

		if (temp == head_)
		{
			x->next_ = head_;
			head_ = x;
		}

		else
		{
			x->next_ = temp;
			prev->next_ = x;
		}
	}
}
void SinglyLinkedOrderedList::insertItem(int item)
{


	insertNode(new Node(item));
}

SinglyLinkedOrderedList::Node* SinglyLinkedOrderedList::searchNode(int item)
{
	Node* x = head_;
	while (x != nullptr && x->item_ != item) {
		x = x->next_;
	}
	return x;
}
bool SinglyLinkedOrderedList::searchItem(int item)
{
	return (searchNode(item) != nullptr);
}

void SinglyLinkedOrderedList::deleteNode(int name)
{
	while (searchItem(name) == true)
	{
		if (head_ == nullptr)
		{
			std::cout << "List is already empty!" << std::endl;
		}
		else
		{
			Node* current = head_;
			Node* trail = nullptr;

			while (current != nullptr)
			{
				if (current->item_ == name)
				{
					break;
				}
				else
				{
					trail = current;
					current = current->next_;
				}
			}

			if (current == nullptr)
			{
				std::cout << "Node with specified value does not exist!" << std::endl;
			}
			else
			{

				if (head_ == current)
				{
					head_ = head_->next_;
				}

				else
				{
					trail->next_ = current->next_;
				}

				delete current;

			}
		}
	}
}

void SinglyLinkedOrderedList::insertList(const SinglyLinkedOrderedList& that)
{
	for (const Node* tp = that.head_; tp; tp = tp->next_)
	{
		if (search(head_, tp->item_))
		{
			continue;
		}
		insertItem(tp->item_);
	}
}
SinglyLinkedOrderedList operator+(const SinglyLinkedOrderedList& list1, const SinglyLinkedOrderedList list2)
{
	SinglyLinkedOrderedList temp;
	temp.insertList(list1);
	temp.insertList(list2);

	return temp;
}

void SinglyLinkedOrderedList::subtractList(const SinglyLinkedOrderedList& that)
{
	for (const Node* tp = that.head_; tp; tp = tp->next_)
	{
		deleteNode(tp->item_);
	}
}
SinglyLinkedOrderedList operator- (const SinglyLinkedOrderedList& list1, const SinglyLinkedOrderedList list2)
{
	SinglyLinkedOrderedList temp;
	temp.insertList(list1);
	temp.subtractList(list2);

	return temp;
}


int SinglyLinkedOrderedList::getCount(Node* head)
{
	Node* current = head;


	int count = 0;

	while (current != NULL) {

		count++;

		current = current->next_;
	}

	return count;
}

SinglyLinkedOrderedList SinglyLinkedOrderedList::intersectionList(const SinglyLinkedOrderedList& that)
{
	SinglyLinkedOrderedList intersection;

	for (const Node* tp = that.head_; tp; tp = tp->next_)
	{
		if (search(head_, tp->item_))
		{
			intersection.insertItem(tp->item_);
		}
	}

	return intersection;
}
SinglyLinkedOrderedList operator* (const SinglyLinkedOrderedList& list1, const SinglyLinkedOrderedList list2)
{
	SinglyLinkedOrderedList temp;
	temp.insertList(list1);

	return temp.intersectionList(list2);
}

bool SinglyLinkedOrderedList::search(Node* head, int x)
{
	Node* current = head;  
	while (current != NULL)
	{
		if (current->item_ == x)
			return true;
		current = current->next_;
	}
	return false;
}
