#pragma once
#include <iostream>

class SinglyLinkedList
{
public:
	SinglyLinkedList();
	~SinglyLinkedList();
	SinglyLinkedList(SinglyLinkedList& src);
	SinglyLinkedList(const SinglyLinkedList& src);
	void operator+=(int data);
	int operator[](const int idx);
	void push_back(int data);
	void push_front(int data);
	void PrintList();
	void Sort();
	void pop_front();
	bool operator ==(const SinglyLinkedList& other);
	int GetSize()
	{
		return size;
	}
	void Merge(SinglyLinkedList& src);

	void pop_back();
	void  removeAt(int idx);;

	friend std::ostream& operator<< (std::ostream& os, const SinglyLinkedList& sllst);
	friend SinglyLinkedList operator&(SinglyLinkedList& firstList, SinglyLinkedList& secondList);
	friend SinglyLinkedList operator|(SinglyLinkedList& firstList, SinglyLinkedList& secondList);
	friend 	bool operator!=(SinglyLinkedList& firstList, SinglyLinkedList& secondList);
private:

	struct Node
	{
	public:
		int data;
		Node* next;
		Node(int data = int(), Node* next = nullptr)
		{
			this->data = data;
			this->next = next;
		}
	};
	Node* head;
	int size;
	SinglyLinkedList::Node* searchNode(int item);
};
