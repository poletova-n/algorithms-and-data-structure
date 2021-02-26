#ifndef DOUBLE_LINKED_LIST
#define DOUBLE_LINKED_LIST
#include <ostream>

class DoubleLinkedList {
private:
    struct Node {
        int item_;
        Node* next_;
        Node* prev_;
        Node(int item, Node* next = nullptr, Node* prev = nullptr) : item_(item), next_(next), prev_(prev) { }
    };
    Node* head_;
    Node* tail_;
    int size;
    void insert(Node* list);
public:
    DoubleLinkedList();
    DoubleLinkedList(const DoubleLinkedList& copy);
    DoubleLinkedList(DoubleLinkedList&& copy) noexcept;
    ~DoubleLinkedList();
    void operator+=(int item);
    friend std::ostream& operator<<(std::ostream& item, const DoubleLinkedList& list);
    bool operator==(const DoubleLinkedList& copy);
    friend DoubleLinkedList operator&(const DoubleLinkedList& first, const DoubleLinkedList& second);
    friend DoubleLinkedList operator|(const DoubleLinkedList& first, const DoubleLinkedList& second);
    void merge(DoubleLinkedList& list);
};

#endif

