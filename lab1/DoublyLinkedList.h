#ifndef DOUBLY_LINKEDLIST_H
#define DOUBLY_LINKEDLIST_H


#include <ostream>

class DoublyLinkedList {
public:
  // Конструктор "по умолчанию" - создание пустого списка
  DoublyLinkedList();

  // Конструктор "копирования" – создание копии имеющегося списка
  DoublyLinkedList(const DoublyLinkedList& src);

  //Конструктор перемещения
  DoublyLinkedList(DoublyLinkedList&& src) noexcept;

  void swap(DoublyLinkedList& rhs) noexcept;

  // количество элементов списка
  [[nodiscard]] int size() const;

  // Доступ к информации головного узла списка
  //  int headItem() const;
  //  int& headItem();

  // Доступ к информации хвостового узла списка
  //  int tailItem() const;
  //int& tailItem();

  // Вставить элемент в голову списка
  void push_front(int item);

  // Вставить элемент в хвост списка
  void push_back(int item);

  // Удалить элемент с головы списка
  void pop_front();

  // Удалить элемент из хвоста списка
  void pop_back();

  // Удаление узла с заданным значением
  void remove(int item);

  //Очистка листа
  void clear();

  // Поиск записи с заданным значением
  bool has(int item);

  //Слияние двух листов
  void merge(DoublyLinkedList& other);

  //Перегруженный оператор копирующего присваивания
  DoublyLinkedList& operator=(const DoublyLinkedList& other);

  //Перегруженный оператор перемещающего присваивания
  DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;

  bool operator==(const DoublyLinkedList& rhs) const;

  bool operator!=(const DoublyLinkedList& rhs) const;

  friend DoublyLinkedList operator&(const DoublyLinkedList& lhs, const DoublyLinkedList& rhs);

  friend DoublyLinkedList operator|(const DoublyLinkedList& lhs, const DoublyLinkedList& rhs);

  DoublyLinkedList& operator+=(int item);

  // Вывод элементов списка в текстовом виде в стандартный выходной поток
  friend std::ostream& operator<<(std::ostream& os, const DoublyLinkedList& singlyLinkedList);

  // Деструктор списка
  virtual ~DoublyLinkedList();

private:
  struct Node {
    int item_;  // значение элемента списка
    Node* next_;// указатель на следующий элемент списка
    Node* prev_;// указатель на предыдущий элемент списка
    Node(int item, Node* next, Node* prev);
  };

  int size_;  // счетчик числа элементов
  Node* head_;// первый элемент списка
  Node* tail_;// последний элемент списка

  // Доступ к головному узлу списка
  [[nodiscard]] Node* head() const;

  // Доступ к хвостовому узлу списка
  [[nodiscard]] Node* tail() const;

  // Вставить сформированный узел в хвост списка
  void insertTail(Node* x);

  // Вставить сформированный узел в начало списка
  void insertHead(Node* elem);// (int item);

  // Удаление заданного узла
  void deleteNode(Node* x);

  // Поиск узла (адрес) с заданным значением
  Node* searchNode(int item);

  // Замена информации узла на новое
  void replace(int itemOld, int itemNew);

  //Сортировка листа
  void sort();
};


#endif
