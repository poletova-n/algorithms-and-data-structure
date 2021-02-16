#include <iostream>
#include "DLL.h"

DoublyLinkedList::DoublyLinkedList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
	Node* cur = nullptr;
	Node* next = head;
	while (next != nullptr) {
		cur = next;
		next = next->next;
		delete cur;
	}

}

DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& other)
{
	head = nullptr;
	tail = nullptr;
	size = 0;

	Node* temp = other.head;

	while (temp != nullptr)
	{
		push_back(temp->data);
		temp = temp->next;
	}

}

DoublyLinkedList::DoublyLinkedList(DoublyLinkedList& src)
{
	head = src.head;
	tail = src.tail;
	size = src.size;
	src.head = nullptr;
	src.tail = nullptr;
	src.size = 0;
}



bool DoublyLinkedList::operator==(const DoublyLinkedList& other)
{
	if (size != other.size)
	{
		return false;
	}
	if (&other == this)
	{
		return true;
	}
	Node* lst1 = head;
	Node* lst2 = other.head;

	while (lst1 != 0)
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

void DoublyLinkedList::operator+=(int data)
{
	push_back(data);
}


void DoublyLinkedList::PrintList()
{
	Node* cur = head;
	while (cur != nullptr)
	{
		std::cout << cur->data << ' ';
		cur = cur->next;
	}
	std::cout << std::endl;
}


void DoublyLinkedList::copyAll(DoublyLinkedList& dll)
{
	DoublyLinkedList::Node* iterator = dll.head;
	while (iterator)
	{
		int obj = iterator->data;
		push_back(obj);
		iterator = iterator->next;
	}
}

DoublyLinkedList& DoublyLinkedList::operator=(DoublyLinkedList dll)
{
	if (this != &dll)
	{
		clear();
		copyAll(dll);
	}
	return *this;
}


void DoublyLinkedList::pop_front()
{
	Node* temp = head;
	head = head->next;
	delete temp;
	size--;
}

void DoublyLinkedList::clear()
{
	while (size)
	{
		pop_front();
	}
}


void DoublyLinkedList::push_front(int data)
{
	Node* newNode = new Node(data);
	newNode->data = data;
	newNode->next = head;
	newNode->prev = nullptr;
	if (head != nullptr)
	{
		head->prev = newNode;
	}
	else
	{
		tail = newNode;
	}
	head = newNode;
	size++;
	Sort();
}

void DoublyLinkedList::push_back(int data)
{
	Node* newNode = new Node(data);
	Node* last = head;
	newNode->next = nullptr;
	if (head == nullptr)
	{
		newNode->prev = nullptr;
		head = newNode;
	}
	else
	{
		while (last->next != nullptr)
		{
			last = last->next;
		}
		last->next = newNode;
		newNode->prev = last;
	}
	size++;
	Sort();
}

void DoublyLinkedList::Merge(DoublyLinkedList& src)
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

std::ostream& operator<<(std::ostream& os, DoublyLinkedList& dllst)
{
	dllst.PrintList();
	return os;
}

DoublyLinkedList operator&(DoublyLinkedList& firstList, DoublyLinkedList& secondList)
{
	DoublyLinkedList summary;
	DoublyLinkedList::Node* tempList = firstList.head;
	while (tempList != nullptr)
	{
		if (secondList.searchNode(tempList->data) != nullptr)
		{
			summary += tempList->data;
		}
		tempList = tempList->next;
	}
	return summary;
}

DoublyLinkedList operator | (DoublyLinkedList& firstList, DoublyLinkedList& secondList)
{
	DoublyLinkedList newList;
	int count1 = firstList.size;
	DoublyLinkedList::Node* head1 = firstList.head;
	for (int i = 0; i < count1; i++)
	{
		newList.push_back(head1->data);
		head1 = head1->next;
	}
	int count2 = secondList.size;
	DoublyLinkedList::Node* head2 = secondList.head;
	for (int i = 0; i < count2; i++)
	{
		if (!newList.searchItem(head2->data))
		{
			newList.push_back(head2->data);
		}
		head2 = head2->next;
	}
	return newList;
}

void DoublyLinkedList::Sort()
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

bool operator!=(DoublyLinkedList& firstList, DoublyLinkedList& secondList)
{
	return !(firstList == secondList);
}

DoublyLinkedList::Node* DoublyLinkedList::searchNode(int data)
{
	DoublyLinkedList::Node* cur = head;
	while (cur != nullptr && cur->data != data)
	{
		cur = cur->next;
	}
	return cur;
}

bool DoublyLinkedList::searchItem(int data)
{
	return (searchNode(data) != nullptr);
}
