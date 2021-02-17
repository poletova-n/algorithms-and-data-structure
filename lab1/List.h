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

public:
    void insert(Node* list);

    List();

    List(List&& copy) noexcept;

    ~List();

    void operator += (int data);

    friend std::ostream & operator << (std::ostream& stream, const List& list);

    bool operator == (const List& copy);

    friend List operator & (const List& first, const List& second);

    friend List operator | (const List& first, const List& second);

    void merge(List& parameter);
};
#endif
