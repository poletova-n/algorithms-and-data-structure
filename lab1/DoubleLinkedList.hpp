#pragma once
#ifndef DOUBLE_LINKED_LIST_H
#define DOUBLE_LINKED_LIST_H
#include <iostream>
class DoubleLinkedList
{
public:
	DoubleLinkedList();
	DoubleLinkedList(const DoubleLinkedList& object);
	void operator += (int data);
	void operator = (const DoubleLinkedList& object);
	int operator [] (int size);
	bool operator == (DoubleLinkedList& object);
	friend DoubleLinkedList operator & (DoubleLinkedList& object1, DoubleLinkedList& object2);
	friend DoubleLinkedList operator | (DoubleLinkedList& object1, DoubleLinkedList& object2);
	friend std::ostream& operator<<(std::ostream& output, DoubleLinkedList& object);
	void merge(DoubleLinkedList& object);
	~DoubleLinkedList();
private:
	class Node
	{
	public:
		Node(int data, Node* next = nullptr, Node* prev = nullptr)
		{
			prev_ = prev;
			next_ = next;
			data_ = data;
		}
		Node* prev_;
		Node* next_;
		int data_;
	};
	Node* head_;
	int count_;
};
#endif
