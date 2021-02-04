#ifndef SINGLY_LINKED_LIST
#define SINGLY_LINKED_LIST

#include <ostream>

class SinglyLinkedList {
public:
  // Конструктор "по умолчанию" - создание пустого списка
  SinglyLinkedList();

  // Конструктор "копирования" – создание копии имеющегося списка
  SinglyLinkedList(const SinglyLinkedList& src);
  //Перегруженный оператор перемещающего присваивания

  //Конструктор перемещения
  SinglyLinkedList(SinglyLinkedList&& src) noexcept;

  void swap(SinglyLinkedList& rhs) noexcept;

  // количество элементов списка
  [[nodiscard]] int size() const;

  // Доступ к информации головного узла списка
  //  int headItem() const;
  //  int& headItem();

  // Доступ к информации хвостового узла списка
  //  int tailItem() const;
  //  int& tailItem();

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
  void merge(SinglyLinkedList& other);

  //Перегруженный оператор копирующего присваивания
  SinglyLinkedList& operator=(const SinglyLinkedList& other);


  SinglyLinkedList& operator=(SinglyLinkedList&& other) noexcept;

  bool operator==(const SinglyLinkedList& rhs) const;

  bool operator!=(const SinglyLinkedList& rhs) const;

  friend SinglyLinkedList operator&(const SinglyLinkedList& lhs, const SinglyLinkedList& rhs);

  friend SinglyLinkedList operator|(const SinglyLinkedList& lhs, const SinglyLinkedList& rhs);

  SinglyLinkedList& operator+=(int item);

  // Вывод элементов списка в текстовом виде в стандартный выходной поток
  friend std::ostream& operator<<(std::ostream& os, const SinglyLinkedList& singlyLinkedList);

  // Деструктор списка
  virtual ~SinglyLinkedList();

private:
  struct Node {
    int item_;  // значение элемента списка
    Node* next_;// указатель на следующий элемент списка
    Node(int item, Node* next);
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
