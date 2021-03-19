#ifndef CPP_PROJECTS_DOUBLELIST_H
#define CPP_PROJECTS_DOUBLELIST_H
#include <iostream>


class DoubleList
{
private:
    struct Node
    {


        Node(int data, Node* next = nullptr, Node* prev = nullptr):
                data_(data), next_(next), prev_(prev)
        {

        }

        Node(const Node &copyVal):
                data_(copyVal.data_), next_(copyVal.next_), prev_(copyVal.prev_)
        {

        }

        int data_;
        Node* next_;
        Node* prev_;
    };

    int count_;
    Node* head_;
    Node* tail_;

    void sort();

    bool checkNonRepetitiveElements(Node* value);

public:

    DoubleList();

    DoubleList(DoubleList &&copyVal) noexcept;

    ~DoubleList();

    void operator+= (int value);

    friend std::ostream &operator<< (std::ostream &output, const DoubleList &list);

    bool operator== (DoubleList &otherList);

    DoubleList(const DoubleList &copyValue);

    friend DoubleList operator& (const DoubleList& firstVal, const DoubleList& secondVal);

    friend DoubleList operator| (const DoubleList& firstVal, const DoubleList& secondVal);

    void merge(DoubleList& newList);

    int getCount() const;

    void insert(Node *value);

};

#endif //CPP_PROJECTS_DOUBLELIST_H
