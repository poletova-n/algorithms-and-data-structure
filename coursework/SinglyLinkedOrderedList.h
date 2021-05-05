#ifndef SINGLYLINKEDORDERLIST
#define SINGLYLINKEDORDERLIST

#include <iostream>

class SinglyLinkedOrderedList
{
public:
  SinglyLinkedOrderedList();
  SinglyLinkedOrderedList(const SinglyLinkedOrderedList &src);
  SinglyLinkedOrderedList(SinglyLinkedOrderedList &&list) noexcept;
  SinglyLinkedOrderedList& operator = (const SinglyLinkedOrderedList &src);
  void insert(std::string& word);
  bool search(std::string& word);
  bool deleteWord(std::string& word);
  friend std::ostream &operator<<(std::ostream &out, SinglyLinkedOrderedList &list)
  {
    if (list.head_ == nullptr)
    {
      return out;
    }
    else
    {
      Node *newNode = list.head_;
      while (newNode != nullptr)
      {
        if(newNode->next_ != nullptr)
        {
          out << newNode->word_ << ',';
        }
        else
        {
          out << newNode->word_ ;
        }
        newNode = newNode->next_;
      }
    }
    return out;
  };
  ~SinglyLinkedOrderedList();
private:
  struct Node
  {
  public:
    Node *next_;
    std::string word_;

    Node(std::string word, Node *next) :
      word_(word),
      next_(next)
    {}
  };
  Node *head_;
  Node *tail_;
  int count_;
  Node *searchNode(std::string& word);
  void deleteNode(Node *x);
  bool parse(std::string& word);
};
#endif