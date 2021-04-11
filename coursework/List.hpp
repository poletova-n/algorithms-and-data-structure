#ifndef LIST_HPP
#define LIST_HPP
#include <iostream>
#include <string>

class List{
public:
    List(): head_(nullptr), tail_(nullptr) {}
    ~List();
    size_t getSize();
    void insert(std::string);
    void insertHead(std::string);
    void insertTail(std::string);
    std::string print() const;
private:
    struct Node
    {
        std::string item_;
        Node* next_;
        Node(std::string item = nullptr, Node* next = nullptr)
        {
            this->item_= item;
            this->next_= next;
        }
    };
    Node* head_;
    Node* tail_;
    void insertHead(Node*);
    void insertTail(Node*);
};
#endif
