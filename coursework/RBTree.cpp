#include "RBTree.hpp"
#include <stdexcept>
#include <iomanip>

RBTree:: RBTree() :
  root_()
{}

void RBTree::insert(std::string& word, SinglyLinkedOrderedList& synonyms)
{
  if (parse(word) == false)
  {
    throw std::invalid_argument("Word must be contain of English letter and -");
  }
  if (this->search(word))
  {
    throw std::invalid_argument("The word has already been added!");
  }
  insertPrivate(word, synonyms);
}

void RBTree::insertPrivate(std::string& word, SinglyLinkedOrderedList &tr)
{
  Node *current;
  Node *parent;

  current = root_;
  parent = nullptr;
  while (current != nullptr)
  {
    parent = current;
    current = word < current->word_ ? current->left_ : current->right_;
  }

  Node *x = new Node(word, tr);
  x->parent_ = parent;
  x->left_ = nullptr;
  x->right_ = nullptr;
  x->color_ = true;

  if (parent)
  {
    if (word < parent->word_)
    {
      parent->left_ = x;
    }
    else
    {
      parent->right_ = x;
    }
  }
  else
  {
    root_ = x;
  }
  insert1(x);
}

void RBTree::insert1(Node* node) {
  if (node->parent_ == nullptr)
  {
    node->color_ = false;
  }
  else
  {
    insert2(node);
  }
}

void RBTree::insert2(Node *node) {
  if (node->parent_->color_ == false)
  {
    return;
  }
  else
  {
    insert3(node);
  }
}

void RBTree::insert3(Node *node)
{
  Node *u = uncle(node), *g;

  if ((u != nullptr) && (u->color_ == true))
  {
    node->parent_->color_ = false;
    u->color_ = false;
    g = grandparent(node);
    g->color_ = true;
    insert1(g);
  }
  else
  {
    insert4(node);
  }
}

void RBTree::insert4(Node *x) {
  Node *g = grandparent(x);
  if ((x == x->parent_->right_) && (x->parent_ == g->left_))
  {
    leftRotate(x->parent_);

    x = x->left_;
  }
  else if ((x == x->parent_->left_) && (x->parent_ == g->right_))
  {
    rightRotate(x->parent_);
    x = x->right_;
  }
  insert5(x);
}

void RBTree::insert5(Node *x) {
  Node *g = grandparent(x);
  x->parent_->color_ = false;
  g->color_ = true;
  if ((x == x->parent_->left_) && (x->parent_ == g->left_))
  {
    rightRotate(g);
  }
  else
    {
    leftRotate(g);
  }
}
RBTree::Node *RBTree::grandparent(Node *node)
{
  if ((node != nullptr) && (node->parent_ != nullptr))
  {
    return node->parent_->parent_;
  }
  else
  {
    return nullptr;
  }
}

RBTree::Node *RBTree::uncle(Node *node)
{
  Node *g = grandparent(node);
  if (g == nullptr)
    return nullptr;
  if (node->parent_ == g->left_)
    return g->right_;
  else
    return g->left_;
}

void RBTree::remove(std::string& word)
{
  Node* tmp = root_;
  if (tmp == nullptr)
  {
    throw std::runtime_error("Tree is empty!");
  }
  tmp = searchNode(word);
  if (tmp == nullptr)
  {
    throw std::runtime_error("No such word found");
  }
  Node *y;
  Node *x = nullptr;
  if (tmp->parent_ == nullptr)
  {
    if (tmp->left_ == nullptr || tmp->right_ == nullptr)
    {
      y = tmp;
    }
    else
    {
      y = successor(tmp);
      if ((y->parent_->right_ != nullptr && y == y->parent_->left_)
          || (y->parent_->left_ != nullptr && y == y->parent_->right_))
      {
        Node *s = sibling(y);
        if (s != nullptr && (s->color_ == false && ((s->left_ != nullptr && s->left_->color_ == true)
            || (s->right_ != nullptr && s->right_->color_ == true))))
        {
          deleteNode(y);
        }
      }
      else
      {
        fixUpTreeForRemove(y);
      }
    }
    if (y->left_ != nullptr)
    {
      x = y->left_;
    }
    else
    {
      x = y->right_;
    }
    if (x != nullptr)
    {
      x->parent_ = y->parent_;
    }
    if (y->parent_ == nullptr)
    {
      root_ = x;
    }
    else
    {
      if (y == y->parent_->left_)
      {
        y->parent_->left_ = x;
      }
      else
      {
        y->parent_->right_ = x;
      }
    }

    if (y != tmp)
    {
      tmp->word_ = y->word_;
      tmp->synonyms_ = y->synonyms_;
    }
  }
  else if (tmp->left_ == nullptr && tmp->right_ == nullptr && tmp->color_ == true)
  {
    y = tmp;
    if (y == y->parent_->left_)
    {
      y->parent_->left_ = x;
    } else
    {
      y->parent_->right_ = x;
    }
  }
  else
  {
    Node *s = sibling(tmp);
    if (tmp->left_ == nullptr && tmp->right_ == nullptr && tmp->color_ == false && s->left_ == nullptr && s->right_ == nullptr)
    {
      y = tmp;
      fixUpTreeForRemove(tmp);
      if (y == y->parent_->left_)
      {
        y->parent_->left_ = x;
      }
      else
      {
        y->parent_->right_ = x;
      }
    }
    else
    {
      if (tmp->left_ == nullptr || tmp->right_ == nullptr)
      {
        y = tmp;
      }
      else
      {
        y = successor(tmp);
      }

      if (y->left_ != nullptr)
      {
        x = y->left_;
      }
      else
      {
        x = y->right_;
      }

      if (x != nullptr)
      {
        x->parent_ = y->parent_;
      }

      if (y->parent_ == nullptr)
      {
        root_ = x;
      }
      else
      {
        Node *s = sibling(y);
        if (s->color_ == false && ((s->left_ != nullptr && s->left_->color_ == true && s->right_ == nullptr)
            || (s->right_ != nullptr && s->right_->color_ == true && s->left_ == nullptr)))
        {
          deleteNode(y);
          if (y == y->parent_->left_)
          {
            y->parent_->left_ = x;
          }
          else
          {
            y->parent_->right_ = x;
          }
        }
        else
        {
          fixUpTreeForRemove(y);
          if (y == y->parent_->left_)
          {
            y->parent_->left_ = x;
          }
          else
          {
            y->parent_->right_ = x;
          }
        }
      }
      if (y != tmp)
      {
        tmp->word_ = y->word_;
        tmp->synonyms_ = y->synonyms_;
      }
    }
  }
}

RBTree::Node *RBTree::successor(Node *node)
{
  if (node->right_ != nullptr)
  {
    while (node->left_ != nullptr) {
      node = node->left_;
    }
    return node;
  }
  Node *temp = node->parent_;
  while (temp != nullptr && node == temp->right_) {
    node = temp;
    temp = temp->parent_;
  }
  return temp;
};

RBTree::Node* RBTree::sibling(Node* node)
{
  if (node == node->parent_->right_)
  {
    return node->parent_->left_;
  }
  else
  {
    return node->parent_->right_;
  }
}

bool RBTree::search(std::string& word)
{
  Node *temp(root_);
  while (temp != nullptr)
  {
    if (temp->word_ > word)
    {
      temp = temp->left_;
    }
    else if (temp->word_ < word)
    {
      temp = temp->right_;
    }
    else
    {
      return true;
    }
  }
  return false;
}

void RBTree::deleteNode(Node* node)
{
  Node *s = sibling(node);
  s->color_ = node->parent_->color_;
  node->parent_->color_ = false;
  if (node == node->parent_->left_)
  {
    s->right_->color_ = false;
    leftRotate(node->parent_);
  }
  else
  {
    s->left_->color_ = false;
    rightRotate(node->parent_);
  }
}

void RBTree::fixUpTreeForRemove(RBTree::Node *node)
{
  while ((node != root_) && (node->color_ == false))
  {
    if (node == node->parent_->left_)
    {
      Node *tmp = node->parent_->right_;
      if (tmp->color_ == true)
      {
        tmp->color_ = false;
        node->parent_->color_ = true;
        leftRotate(node->parent_);
        tmp = node->parent_->right_;
      }
      if ((tmp->left_ == nullptr && tmp->right_ == nullptr))
      {
        tmp->color_ = true;
        node = node->parent_;
      }
      else if (tmp->left_->color_ == false && tmp->right_->color_ == false)
      {
        tmp->color_ = true;
        node = node->parent_;
      }
      else
      {
        if (tmp->right_->color_ == false)
        {
          tmp->left_->color_ = false;
          tmp->color_ = true;
          rightRotate(tmp);
          tmp = node->parent_->right_;
        }
        tmp->color_ = node->parent_->color_;
        node->parent_->color_ = false;
        tmp->right_->color_ = false;
        leftRotate(node->parent_);
        node = root_;
      }
    }
    else
    {
      Node *tmp = node->parent_->left_;
      if (tmp->color_ == true)
      {
        node->parent_->color_ = true;
        rightRotate(node->parent_);
        tmp = node->parent_->left_;
      }
      if ((tmp->left_ == nullptr) && (tmp->right_ == nullptr))
      {
        tmp->color_ = true;
        node = node->parent_;
      }
      else if ((tmp->right_->color_ == false) && (tmp->left_->color_ == false))
      {
        tmp->color_ = true;
        node = node->parent_;
      }
      else
      {
        if (tmp->left_->color_ == false)
        {
          tmp->right_->color_ = false;
          tmp->color_ = true;
          leftRotate(tmp);
          tmp = node->parent_->left_;
        }
        tmp->color_ = node->parent_->color_;
        node->parent_->color_ = false;
        tmp->left_->color_ = false;
        rightRotate(node->parent_);
        node = root_;
      }
    }
  }
  node->color_ = false;
}

void RBTree::leftRotate(Node *node)
{
  Node *tmp = node->right_;
  node->right_ = tmp->left_;
  if (tmp->left_ != nullptr)
  {
    tmp->left_->parent_ = node;
  }
  if (tmp != nullptr)
  {
    tmp->parent_ = node->parent_;
  }
  if (node->parent_)
  {
    if (node == node->parent_->left_)
    {
      node->parent_->left_ = tmp;
    }
    else
    {
      node->parent_->right_ = tmp;
    }
  }
  else
  {
    root_ = tmp;
  }
  tmp->left_ = node;
  if (node != nullptr)
  {
    node->parent_ = tmp;
  }
}

void RBTree::rightRotate(Node* node)
{
  Node* temp = node->left_;
  temp->parent_ = node->parent_;
  if (node->parent_ == nullptr)
  {
    root_ = temp;
  }
  else
  {
    if (node->parent_->left_ == node)
    {
      node->parent_->left_ = temp;
    } else
    {
      node->parent_->right_ = temp;
    }
  }
  node->parent_ = temp;
  if (temp->right_ != nullptr)
  {
    temp->right_->parent_ = node;
  }
  node->left_ = temp->right_;
  temp->right_ = node;
}

void RBTree::print(std::ostream& output)
{
  if(root_!= nullptr)
  {
    output << '\n' << "word:                    synonyms:" << '\n';
  }
  printNode(output, root_);
}

void RBTree::printNode(std::ostream& output, Node* node)
{
  if (node != nullptr)
  {
    printNode(output, node->left_);
    output <<std::setw(25) << std::left << node->word_ << node->synonyms_<< '\n';
    printNode(output, node->right_);
  }
}

RBTree::Node *RBTree::searchNode(std::string& word)
{
  Node* tmp = root_;
  while ((tmp != nullptr) && (tmp->word_ != word))
  {
    if (word > tmp->word_)
    {
      tmp = tmp->right_;
    }
    else
    {
      tmp = tmp->left_;
    }
  }
  return tmp;
}

bool RBTree::parse(std::string &word)
{
  for (int i = 0; i < word.size(); i++)
  {
    if ((word[i] < 'A' || word[i] > 'z') && (word[i] != '-'))
    {
      return false;
    }
  }
  return true;
}

void RBTree::printHierarchy(std::ostream &output)
{
  printNodeForHierarchy(output, root_);
}

void RBTree::printNodeForHierarchy(std::ostream &output, RBTree::Node *node)
{
  output << '(';
  if (node != nullptr)
  {
    output << node->word_ << ':' << node->synonyms_;
    printNodeForHierarchy(output, node->left_);
    printNodeForHierarchy(output, node->right_);
  }
  output << ')';
}
