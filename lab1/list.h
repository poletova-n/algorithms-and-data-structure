#pragma once
#ifndef LIST
#define LIST

class List
{
public:

    List();

    ~List();

    List(const List& other);

    void operator +=(int data);

    int operator[](int index);

    bool operator ==(List& list);

    void operator =(List& other);

    List merge(List& list);

    friend std::ostream& operator<<(std::ostream& stream, List& list);

    friend List operator &(List& list, List& list1);

    friend List operator |(List& list, List& list1);

private:

    class Node
    {
    public:
        Node* pNext_;
        int data_;
        Node(int data, Node* pNext = nullptr)
        {
            this->data_ = data;
            this->pNext_ = pNext;
        }
        friend std::ostream& operator<<(std::ostream& stream, List& list);
    };
    int size_;
    Node* head_;

};
#endif
