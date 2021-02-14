#pragma once
#ifndef LIST_H
#define LIST_H
#include <iostream>

class List {
private:
	struct Node {
		int data_;
		Node* next_;
		Node(int data, Node* next = nullptr) : data_(data), next_(next) { }
	};
	Node* head_;
	int count_;
	void insert(Node* list);
public:
	List();
	List(const List& copy);
	List(List&& copy) noexcept;
	~List();
	int getCount() { return count_; }
	void operator+=(int data);
	friend std::ostream& operator<<(std::ostream& stream, const List& list);
	bool operator==(const List& copy);
	friend List operator&(const List& first, const List& second);
	friend List operator|(const List& first, const List& second);
	void merge(List& param);
};


#endif // !LIST_H
