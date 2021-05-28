#include <string>
#ifndef __DOUBLE_LINKED_LIST
#define __DOUBLE_LINKED_LIST

class DoubleLinkedList
{
private:
    // Тип  Node используется для описания элемента списка, связанного со
    // следующим с помощью поля next_ и предшествующим с помощью поле prev_
    struct Node         // может использоваться  только в классе DoubleLinkedList
    {
        int item_;        // значение элемента списка
        Node* next_;      // указатель на следующий элемент списка
        Node* prev_;      // указатель на предшествующий элемент списка

        // Конструктор для создания нового элемента списка.
        Node(int item, Node* next = nullptr, Node* prev = nullptr) : item_(item), next_(next), prev_(prev) { }
    };

    int count_;         // счетчик числа элементов
    Node* head_;        // первый элемент списка
    Node* tail_;        // последний элемент списка

    // Доступ к головному узлу списка
    Node* head() const { return head_; }
    // Доступ к хвостовому узлу списка
    Node* tail() const { return tail_; }
    // Всавить сформированный узел в хвост списка
    void insertTail(Node* x);
    // Вставить сформированный узел в начало списка
    void insertHead(Node* x); // (int item);
    // Удаление заданного узла
    void deleteNode(Node* x);
    // Поиск узла (адрес) с заданным значением
    Node* searchNode(int item);
    // Замена информации узла на новое
    Node* replaceNode(Node* x, int item);

public:
    
    void outAll();
    bool searchItem(int item);
    DoubleLinkedList copy();

    // Конструктор "по умолчанию" - создание пустого списка
    DoubleLinkedList() : count_(0), head_(nullptr), tail_(nullptr) {  }
    // Конструктор "копирования" – создание копии имеющегося списка
    DoubleLinkedList(const DoubleLinkedList& list);
    
    DoubleLinkedList& operator=(DoubleLinkedList& s);
    void swap(DoubleLinkedList& s) throw();

    DoubleLinkedList(DoubleLinkedList&& list) noexcept;

    DoubleLinkedList& operator=(DoubleLinkedList&& other) noexcept;
    // Вставить элемент в голову списка
    void insertHead(int item);
    // Вставить элемент в хвост списка
    void insertTail(int item);
    // Удалить элемент с головы списка
    bool deleteHead();
    // Удалить элемент из хвоста списка
    bool deleteTail();
    // Удаление узла с заданным значением
    bool deleteItem(const int item);
    // Замена информации узла на новое
    bool replaceItem(int itemOld, int itemNew);

    friend std::ostream& operator<<(std::ostream& os, const DoubleLinkedList& list);
    bool operator== (const DoubleLinkedList& list) const;
    void unite(DoubleLinkedList& other);

};
#endif
