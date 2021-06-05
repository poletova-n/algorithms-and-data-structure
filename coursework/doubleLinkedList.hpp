#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST

#include <iostream>

class DoubleLinkedList
{
private:
    struct Node
    {
        int item_;
        Node *next_;
        Node *prev_;

        Node(int item, Node *next = nullptr, Node *prev = nullptr) : item_(item), next_(next), prev_(prev) { }
    };

    int count_;
    Node *head_;
    Node *tail_;

    Node *head() const { return head_; }

    Node *tail() const { return tail_; }

    void insertTail(Node *x);

    void insertHead(Node *x);

    void deleteNode(Node *x);

    Node *searchNode(int item);

    Node *replaceNode(Node *x, int item);

public:
    DoubleLinkedList();

    DoubleLinkedList(const DoubleLinkedList& other);

    DoubleLinkedList& operator=(const DoubleLinkedList& other);

    void swap(DoubleLinkedList& list) noexcept;

    DoubleLinkedList(DoubleLinkedList&& other) noexcept;

    DoubleLinkedList& operator=(DoubleLinkedList&& other) noexcept;

    int getItem(int index);

    int count() const { return count_; }

    int headItem() const;
    int &headItem();

    int tailItem() const;
    int &tailItem();

    void insertHead(int item);

    void insertTail(int item);

    bool deleteHead();

    bool deleteTail();

    bool deleteItem(const int item, bool all = false);

    bool searchItem(int item);

    bool replaceItem(int itemOld, int itemNew, bool all = false);

    void print();

    virtual ~DoubleLinkedList();

    friend std::ostream& operator<<(std::ostream& outStream, const DoubleLinkedList& list);

    bool operator==(const DoubleLinkedList& other);

    void addList(DoubleLinkedList& list);

    int getNode(int index);

    DoubleLinkedList copy();

    bool isEmpty();
};

#endif
