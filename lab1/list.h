#ifndef LAB1_LIST_H
#define LAB1_LIST_H
#include <iostream>

class list
{
private:
    struct Node
    {
        int info_;
        Node* next_;
        Node(int info, Node* next = nullptr) : info_(info), next_(next) {} //конструктор структуры (шаблон)
    };
    Node* head_;
    Node* count_;

public:
    void insert(Node* list);
    list();
    list(list&& copy) noexcept;
    ~list();
    void operator += (int info);
    friend std::ostream& operator << (std::ostream& stream, const list& list);
    bool operator == (const list& copy);
    friend list operator &  (const list& first, const list& second);
    friend list operator |  (const list& first, const list& second);
    void merge(list& parametr);
};

#endif //LAB1_LIST_H
