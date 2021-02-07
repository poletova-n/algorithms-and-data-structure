#pragma once
#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST
#include <iostream>


class DoubleLinkedList
{
private:
    struct Node         
    {
        int data_;        
        Node* next_;     
        Node* prev_;    
        Node(int item, Node* next = nullptr, Node* prev = nullptr) : data_(item), next_(next), prev_(prev) { }
    };
    int count_;
    Node* head_; 
    Node* tail_;
    void insert(Node* list);

public:
    DoubleLinkedList() : count_(0), head_(nullptr), tail_(nullptr) {  }
    DoubleLinkedList(const DoubleLinkedList& copy);
    DoubleLinkedList(DoubleLinkedList&& copy) noexcept;
    ~DoubleLinkedList();

    int getCount() const { return count_; }

    void operator+=(int data);
    friend std::ostream& operator<<(std::ostream& stream, const DoubleLinkedList& list);
    bool operator==(const DoubleLinkedList& src);
    friend DoubleLinkedList operator&(const DoubleLinkedList& first, const DoubleLinkedList& second);
    friend DoubleLinkedList operator|(const DoubleLinkedList& first, const DoubleLinkedList& second);
    void merge(DoubleLinkedList& param);
};
#endif

