#pragma once
#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

class DLList
{
public:

    DLList();

    ~DLList();

    DLList(const DLList& other);

    void operator +=(int data);

    int operator[](int index);

    bool operator ==(DLList& list);

    void operator=(DLList& other);

    friend DLList operator &(DLList& list, DLList& list1);

    friend DLList operator |(DLList& list, DLList& list1);

    friend std::ostream& operator<<(std::ostream& stream, DLList& list);

    DLList merge(DLList& list);

    friend DLList operator ||(DLList& list, DLList& list1);

private:

    class Node
    {
    public:
        Node* pNext_;
        Node* pPrev_;
        int data_;
        Node(int data, Node* pNext = nullptr, Node* pPrev = nullptr)
        {
            this->data_ = data;
            this->pNext_ = pNext;
            this->pPrev_ = pPrev;
        }
        friend std::ostream& operator<<(std::ostream& stream, DLList& list);
    };
    int size_;
    Node* head_;
    Node* tail_;
};
#endif