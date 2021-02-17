#include <iostream>
#include "SLL.h"

SinglyLinkedList::SinglyLinkedList()
{
	size = 0;
	head = nullptr;
}

SinglyLinkedList::SinglyLinkedList(SinglyLinkedList& src)
{
	size = src.size;
	src.size = 0;
	head = src.head;
	src.head = nullptr;
}

SinglyLinkedList::SinglyLinkedList(const SinglyLinkedList& src)
{
	size = src.size;
	head = src.head;
}

SinglyLinkedList::~SinglyLinkedList()
{
	clear();
}

bool SinglyLinkedList::operator==(const SinglyLinkedList& other)
{
	if (size != other.size)
	{
		return false;
	}
	if (&other == this)
	{
		return true;
	}
	else {
		Node* lst1 = other.head;
		Node* lst2 = this->head;
		while (lst1 != nullptr)
		{
			if (lst1->data != lst2->data)
			{
				return false;
			}
			lst1 = lst1->next;
			lst2 = lst2->next;
		}
		return true;
	}
}

void SinglyLinkedList::Merge(SinglyLinkedList& src)
{
	while (src.head != nullptr)
	{
		if (this->searchNode(src.head->data) == nullptr)
		{
			*this += src.head->data;
		}

		Node* temp = src.head->next;
		src.head = nullptr;
		src.head = temp;
	}
}

SinglyLinkedList::Node* SinglyLinkedList::searchNode(int data)
{
	SinglyLinkedList::Node* x = head;
	while (x != nullptr && x->data != data) {
		x = x->next;
	}
	return x;
}

void SinglyLinkedList::pop_back()
{
	removeAt(size - 1);
}

void SinglyLinkedList::removeAt(int idx)
{
	if (idx == 0)
	{
		pop_front();
	}
	else
	{
		Node* prev = this->head;
		for (int i = 0; i < idx; i++)
		{
			prev = prev->next;
		}
		Node* toDelete = prev->next;
		prev->next = toDelete->next;
		delete toDelete;
		size--;
	}
}

bool operator!=(SinglyLinkedList& firstList, SinglyLinkedList& secondList)
{
	return !(firstList == secondList);
}


void SinglyLinkedList::operator+=(int data)
{
	push_back(data);
}


int SinglyLinkedList::operator[](const int idx)
{
	int counter = 0;
	Node* cur = this->head;
	while (cur != nullptr)
	{
		if (counter == idx)
		{
			return cur->data;
		}
		cur = cur->next;
		counter++;
	}
}

void SinglyLinkedList::push_back(int data)
{
	if (head == nullptr)
	{
		head = new Node(data);
	}
	else
	{
		Node* cur = this->head;

		while (cur->next != nullptr)
		{
			cur = cur->next;
		}
		cur->next = new Node(data);
	}
	size++;
	Sort();
}

void SinglyLinkedList::push_front(int data)
{
	head = new Node(data, head);
	size++;
	Sort();
}

SinglyLinkedList operator&(SinglyLinkedList& firstList, SinglyLinkedList& secondList)
{
	SinglyLinkedList newList;
	for (int i = 0; i < firstList.size; i++)
	{
		for (int j = 0; j < secondList.size; j++)
		{
			if (firstList[i] == secondList[j])
			{
				newList += firstList[i];
			}
		}
	}
	return newList;
}

SinglyLinkedList operator|(SinglyLinkedList& firstList, SinglyLinkedList& secondList)
{
	SinglyLinkedList newList;
	newList = firstList;
	for (int i = 0; i < secondList.size; i++)
	{
		int counter = 0;
		for (int j = 0; j < newList.size; j++)
		{
			if (secondList[i] == newList[j])
			{
				counter++;
			}
		}
		if (counter == 0)
		{
			newList += secondList[i];
		}
	}
	return newList;
}


void SinglyLinkedList::PrintList()
{
	Node* cur = head;
	while (cur != nullptr)
	{
		std::cout << cur->data << "  ";
		cur = cur->next;
	}
	std::cout << "\n";
}

void SinglyLinkedList::Sort()
{
	for (int i = 0; i < this->size; i++)
	{
		Node* temp = this->head;
		Node* next = temp->next;
		while (next != nullptr)
		{
			if (temp->data > next->data)
			{
				std::swap(temp->data, next->data);
			}
			temp = temp->next;
			next = next->next;
		}
	}

}

void SinglyLinkedList::pop_front()
{
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
}

void SinglyLinkedList::clear()
{
	while (size)
	{	
	pop_front();
	}
}

