#ifndef DOUBLE_DOUBLELINKEDLIST_H
#define DOUBLE_DOUBLELINKEDLIST_H
#include <iostream>

class DoubleList{
private:
    struct Node {
      int data_;
      Node* next_;
      Node* prev_;

      Node(int data, Node* next = nullptr, Node* prev = nullptr) : data_(data), next_(next), prev_(prev) { }
    };
    Node* head_;

    Node* tail_;

    int counter_;

    bool RepeatedElements(Node* value);
    void sorting();

public:
    void insert(Node *dlist); // add to head

    DoubleList();

    DoubleList(DoubleList&& copy) noexcept;

    ~DoubleList();

    void operator += (int data);

    friend std::ostream & operator << (std::ostream& trans, const DoubleList& list);

    bool operator==(const DoubleList& list);

    friend DoubleList operator&(const DoubleList& firstlist, const DoubleList& secondlist);

    friend DoubleList operator|(const DoubleList& firstlist, const DoubleList& secondlist);

    void merge(DoubleList& List);
};

#endif
