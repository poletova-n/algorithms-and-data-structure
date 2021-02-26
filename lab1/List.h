#ifndef LIST_H
#define LIST_H
#include <ostream>

class List {
private:
    struct Node {
        int item_;
        Node* next_;
        Node(int item, Node* next = nullptr) : item_(item), next_(next) { }
    };
    Node* head_;
    int size;
    void insert(Node* list);
public:
    List();
    List(const List& copy);
    List(List&& copy) noexcept;
    ~List();
    void operator+=(int item);
    friend std::ostream& operator<<(std::ostream& item, const List& list);
    bool operator==(const List& copy);
    friend List operator&(const List& first, const List& second);
    friend List operator|(const List& first, const List& second);
    void merge(List& list);
};

#endif
