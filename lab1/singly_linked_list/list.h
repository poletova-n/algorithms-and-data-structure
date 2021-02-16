#pragma once
#include <iostream>
class List
{
private:
	class Node {
	public:
		Node* next_;
		int value_;
		Node(int value = NULL, Node* next = nullptr) {
			this->value_ = value;
			this->next_ = next;
		}
	};
public:
	int size_;
	Node* head_;
	List(int value);
	List();
	List(Node* src);
	List(List* src);
	List(List&& src) noexcept;
	~List();
	int get_size() { return size_; }
	void insert(int value);
	void insert_n(Node* src);
	void outAll();
	friend std::ostream& operator<<(std::ostream& out, List& src);
	void operator+=(int item);
	bool operator==(List& src);
	bool searchItem(int item);
	Node* searchNode(int item);
	friend List operator| (List& src1, List& src2);
	friend List operator& (List& src1, List& src2);
	void merge(List& src);
};