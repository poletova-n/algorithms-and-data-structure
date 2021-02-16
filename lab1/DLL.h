#pragma once
#include <iostream>


class DoublyLinkedList
{
	friend std::ostream& operator<< (std::ostream& os, DoublyLinkedList& dllst);
	friend DoublyLinkedList operator&(DoublyLinkedList& firstList, DoublyLinkedList& secondList);
	friend DoublyLinkedList operator|(DoublyLinkedList& firstList, DoublyLinkedList& secondList);
	friend bool operator != (DoublyLinkedList& firstList, DoublyLinkedList& secondList);
public:
	DoublyLinkedList();
	~DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& other);
	DoublyLinkedList(DoublyLinkedList& src);
	bool operator ==(const DoublyLinkedList& other);
	void operator+=(int data);
	void PrintList();
	void push_front(int data);
	void push_back(int data);


	void copyAll(DoublyLinkedList& dll);
	DoublyLinkedList& operator=(DoublyLinkedList dll);
	void pop_front();
	void clear();
	void Merge(DoublyLinkedList& src);
	void Sort();
	int GetSize()
	{
		return size;
	}

private:
	class  Node
	{
	public:
		int data;
		Node* next;
		Node* prev;
		Node(int data = int(), Node* next = nullptr, Node* prev = nullptr)
		{
			this->data = data;
			this->next = next;
			this->prev = prev;
		}
	};
	DoublyLinkedList::Node* searchNode(int item);
	bool searchItem(int data);
	Node* head;
	Node* tail;
	int size;
};
