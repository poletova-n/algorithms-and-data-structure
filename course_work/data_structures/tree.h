#ifndef TREE_TREE_H
#define TREE_TREE_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <fstream>

#include "list.h"

template<typename T>
class Tree
{
public:
  Tree();
  ~Tree();
  void insert(T data, const List<T> translations);
  void search(T data) const;
  void output(std::ostream &output) const;
  void deleteNode(T data);
private:
  struct Node
  {
    Node(T data, List<T> translations, Node *parent = nullptr, Node *first = nullptr, Node *second = nullptr, Node *third = nullptr, Node *fourth = nullptr, size_t length = 0) :
      parent_(parent),
      length_(length)
    {
      keys_[0] = data;
      translations_[0] = translations;
      sons_[0] = first;
      sons_[1] = second;
      sons_[2] = third;
      sons_[3] = fourth;
    }
    T keys_[3];
    List<T> translations_[3];
    Node *sons_[4];
    size_t length_;
    Node *parent_;
  };
  Node *root_;

  Node *searchNode(T data) const;
  void split(Node *node);
  void updateKeys(Node *node);
  void sortSons(Node *node);
  T getMax(Node *node) const;

  Node *searchNext(T data) const;

  void deleteNode(Node *node);

  void deleteTree(Node *node);
};

template<typename T>
Tree<T>::Tree():
  root_(nullptr)
{
  std::ifstream file("dictionary.txt");
  if (file.is_open())
  {
    if (file.eof())
    {
      throw std::runtime_error("File is empty");
    }
    while (!file.eof())
    {
      std::string english;
      getline(file, english);
      std::string russian;
      List<T> translations;
      getline(file, russian);
      while (!russian.empty())
      {
        translations += russian;
        getline(file, russian);
      }
      if (!english.empty())
      {
        insert(english, translations);
      }
    }
  }
  else
  {
    throw std::runtime_error("File is not open");
  }
}

template<typename T>
Tree<T>::~Tree()
{
  if (root_ != nullptr)
  {
    deleteTree(root_);
  }
}

template<typename T>
void Tree<T>::insert(T data, const List<T> translations)
{
  if (root_ == nullptr)
  {
    root_ = new Node(data, translations);
  }
  else
  {
    Node *temp = searchNode(data);
    if (temp->keys_[0] == data)
    {
      temp->translations_[0] = translations;
    }
    else
    {
      if (temp->parent_ == nullptr)
      {
        Node *temp1 = new Node(temp->keys_[0], temp->translations_[0], root_);
        Node *temp2 = new Node(data, translations, root_);
        root_->sons_[0] = temp1;
        root_->sons_[1] = temp2;
        root_->length_ = 2;
        sortSons(root_);
        updateKeys(temp2);
      }
      else
      {
        Node *temp1 = new Node(data, translations, temp->parent_);
        temp->parent_->sons_[temp->parent_->length_] = temp1;
        temp->parent_->length_++;
        sortSons(temp1->parent_);
        updateKeys(temp1);
        split(temp1->parent_);
        updateKeys(temp1);
      }
    }
  }
}

template<typename T>
void Tree<T>::search(T data) const
{
  if (root_ == nullptr)
  {
    throw std::runtime_error("search: tree is empty");
  }
  Node *temp = searchNode(data);
  if (temp->keys_[0] == data)
  {
    std::cout << temp->keys_[0] << "\n";
    temp->translations_[0].print(std::cout);
  }
  else
  {
    std::cout << "Word not found\n\n";
  }
}

template<typename T>
void Tree<T>::output(std::ostream &output) const
{
  if (root_ == nullptr)
  {
    throw std::runtime_error("output: tree is empty");
  }
  Node *temp = root_;
  while (temp->sons_[0] != nullptr)
  {
    temp = temp->sons_[0];
  }
  output << temp->keys_[0] << "\n";
  temp->translations_[0].print(output);
  output << "\n";
  temp = searchNext(temp->keys_[0]);
  while (temp != nullptr)
  {
    output << temp->keys_[0] << "\n";
    temp->translations_[0].print(output);
    output << "\n";
    temp = searchNext(temp->keys_[0]);
  }
}

template<typename T>
void Tree<T>::deleteNode(T data)
{
  if (root_ == nullptr)
  {
    throw std::runtime_error("deleteNode: tree is empty");
  }
  Node *temp = searchNode(data);
  if (temp->keys_[0] == data)
  {
    deleteNode(temp);
    std::cout << "Word successfully deleted!\n\n";
  }
  else
  {
    std::cout << "Word not found\n\n";
  }
}

template<typename T>
typename Tree<T>::Node *Tree<T>::searchNode(T data) const
{
  if (root_ == nullptr)
  {
    throw std::runtime_error("searchNode: tree is empty");
  }
  Node *temp = root_;
  while (temp->length_ != 0)
  {
    if (temp->length_ == 2)
    {
      if (temp->keys_[0] < data)
      {
        temp = temp->sons_[1];
      }
      else
      {
        temp = temp->sons_[0];
      }
    }
    else if (temp->length_ == 3)
    {
      if (temp->keys_[1] < data)
      {
        temp = temp->sons_[2];
      }
      else if (temp->keys_[0] < data)
      {
        temp = temp->sons_[1];
      }
      else
      {
        temp = temp->sons_[0];
      }
    }
  }
  return temp;
}

template<typename T>
void Tree<T>::split(Node *node)
{
  if (node->length_ > 3)
  {
    if (node->parent_ != nullptr)
    {
      Node *temp1 = new Node(node->sons_[0]->keys_[0], node->sons_[0]->translations_[0], node->parent_, node->sons_[0], node->sons_[1], nullptr, nullptr, 2);
      Node *temp2 = new Node(node->sons_[2]->keys_[0], node->sons_[2]->translations_[0], node->parent_, node->sons_[2], node->sons_[3], nullptr, nullptr, 2);
      node->sons_[0]->parent_ = temp1;
      node->sons_[1]->parent_ = temp1;
      node->sons_[2]->parent_ = temp2;
      node->sons_[3]->parent_ = temp2;

      if (node->parent_->sons_[0] == node)
      {
        node->parent_->sons_[0] = temp1;
      }
      else if (node->parent_->sons_[1] == node)
      {
        node->parent_->sons_[1] = temp1;
      }
      else if (node->parent_->sons_[2] == node)
      {
        node->parent_->sons_[2] = temp1;
      }

      Node *tempParent = node->parent_;
      delete node;

      tempParent->sons_[tempParent->length_] = temp2;
      tempParent->length_++;
      sortSons(tempParent);
      split(tempParent);
    }
    else
    {
      Node *temp1 = new Node(root_->sons_[0]->keys_[0], root_->sons_[0]->translations_[0], root_, root_->sons_[0], root_->sons_[1], nullptr, nullptr, 2);
      Node *temp2 = new Node(root_->sons_[2]->keys_[0], root_->sons_[2]->translations_[0], root_, root_->sons_[2], root_->sons_[3], nullptr, nullptr, 2);
      root_->sons_[0]->parent_ = temp1;
      root_->sons_[1]->parent_ = temp1;
      root_->sons_[2]->parent_ = temp2;
      root_->sons_[3]->parent_ = temp2;
      root_->sons_[0] = temp1;
      root_->sons_[1] = temp2;
      root_->sons_[2] = nullptr;
      root_->sons_[3] = nullptr;
      root_->length_ = 2;
      sortSons(root_);
    }
  }
}

template<typename T>
void Tree<T>::updateKeys(Node *node)
{
  Node *temp = node->parent_;
  while (temp != nullptr)
  {
    //temp->keys_[0] = 0;
    //temp->keys_[1] = 0;
    //temp->keys_[2] = 0;
    for (size_t i = 0; i < temp->length_ - 1; i++)
    {
      temp->keys_[i] = getMax(temp->sons_[i]);
    }
    temp = temp->parent_;
  }
}

template<typename T>
void Tree<T>::sortSons(Node *node)
{
  for (size_t i = 0; i < node->length_ - 1; i++)
  {
    for (size_t j = i; j < node->length_; j++)
    {
      if (node->sons_[i]->keys_[0] > node->sons_[j]->keys_[0])
      {
        std::swap(node->sons_[i], node->sons_[j]);
      }
    }
  }
}

template<typename T>
T Tree<T>::getMax(Node *node) const
{
  while (((node->length_ == 2) && (node->sons_[1] != nullptr)) || ((node->length_ == 3) && (node->sons_[2] != nullptr)))
  {
    if (node->length_ == 2)
    {
      node = node->sons_[1];
    }
    else if (node->length_ == 3)
    {
      node = node->sons_[2];
    }
  }
  return node->keys_[0];
}

template<typename T>
typename Tree<T>::Node *Tree<T>::searchNext(T data) const
{
  if (root_ == nullptr)
  {
    throw std::runtime_error("searchNext: tree is empty");
  }
  Node *temp = searchNode(data);
  while (temp->parent_ != nullptr)
  {
    Node *tempPrev = temp;
    temp = temp->parent_;
    if ((temp->sons_[0] == tempPrev) && (temp->sons_[1] != nullptr))
    {
      temp = temp->sons_[1];
      while (temp->length_ != 0)
      {
        temp = temp->sons_[0];
      }
      return temp;
    }
    else if ((temp->sons_[1] == tempPrev) && (temp->sons_[2] != nullptr))
    {
      temp = temp->sons_[2];
      while (temp->length_ != 0)
      {
        temp = temp->sons_[0];
      }
      return temp;
    }
  }
  return nullptr;
}

template<typename T>
void Tree<T>::deleteNode(Node *node)
{
  if (node->parent_ == nullptr)
  {
    delete node;
    root_ = nullptr;
  }
  else if (node->parent_->length_ == 3)
  {
    if (node->parent_->sons_[0] == node)
    {
      node->parent_->sons_[0] = node->parent_->sons_[1];
      node->parent_->sons_[1] = node->parent_->sons_[2];
      node->parent_->sons_[2] = nullptr;
      node->parent_->length_--;
      updateKeys(node);
      delete node;
    }
    else if (node->parent_->sons_[1] == node)
    {
      node->parent_->sons_[1] = node->parent_->sons_[2];
      node->parent_->sons_[2] = nullptr;
      node->parent_->length_--;
      updateKeys(node);
      delete node;
    }
    else if (node->parent_->sons_[2] == node)
    {
      node->parent_->sons_[2] = nullptr;
      node->parent_->length_--;
      updateKeys(node);
      delete node;
    }
  }
  else if (node->parent_->length_ == 2)
  {
    if (node->parent_ == root_)
    {
      if (node->parent_->sons_[0] == node)
      {
        Node *tempRoot = root_;
        root_ = node->parent_->sons_[1];
        node->parent_->sons_[1]->parent_ = nullptr;
        delete tempRoot;
        delete node;
      }
      else if (node->parent_->sons_[1] == node)
      {
        Node *tempRoot = root_;
        root_ = node->parent_->sons_[0];
        node->parent_->sons_[0]->parent_ = nullptr;
        delete tempRoot;
        delete node;
      }
    }
    else
    {
      Node *b = nullptr;
      Node *np = nullptr;
      Node *p = node->parent_;
      if (node->parent_->sons_[0] == node)
      {
        b = node->parent_->sons_[1];
        node->parent_->sons_[0] = nullptr;
        node->parent_->sons_[1] = nullptr;
        node->parent_->length_ = 0;
      }
      else if (node->parent_->sons_[1] == node)
      {
        b = node->parent_->sons_[0];
        node->parent_->sons_[0] = nullptr;
        node->parent_->sons_[1] = nullptr;
        node->parent_->length_ = 0;
      }

      if (node->parent_->parent_->sons_[0] == node->parent_)
      {
        np = node->parent_->parent_->sons_[1];
      }
      else if ((node->parent_->parent_->sons_[1] == node->parent_) && (node->parent_->parent_->sons_[2] != nullptr))
      {
        np = node->parent_->parent_->sons_[2];
      }
      else if (node->parent_->parent_->sons_[2] == node->parent_)
      {
        np = node->parent_->parent_->sons_[1];
      }
      else
      {
        np = node->parent_->parent_->sons_[0];
      }

      delete node;

      np->sons_[np->length_] = b;
      b->parent_ = np;
      np->length_++;

      sortSons(b->parent_);
      updateKeys(b);
      split(np);
      deleteNode(p);
    }
  }
}

template<typename T>
void Tree<T>::deleteTree(Node *node)
{
  if (node->sons_[0] != nullptr)
  {
    deleteTree(node->sons_[0]);
  }
  if (node->sons_[1] != nullptr)
  {
    deleteTree(node->sons_[1]);
  }
  if (node->sons_[2] != nullptr)
  {
    deleteTree(node->sons_[2]);
  }
  delete node;
}

#endif //TREE_TREE_H
