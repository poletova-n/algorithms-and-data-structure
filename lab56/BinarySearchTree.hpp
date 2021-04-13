#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include <iostream>
#include "list_stack.hpp"
#include "queue_list.hpp"

template<class T>
class BinarySearchTree {
public:
  BinarySearchTree();

  void add_iter(const T &key);

  void add_rec(T key);

  bool search(const T &key);

  T search_next(const T &key);

  int get_count_knots() const;

  int get_height() const;

  void remove(const T &key);

  void print_element(std::ostream &out, T key);

  void erase_tree();

  void iter_width();

  void iter_left_right();

  bool is_same(BinarySearchTree<T> src);

private:
  struct Node {
    T key_;
    Node *left_;
    Node *right_;
    Node *parent_;

    explicit Node(T key, Node *left = nullptr, Node *right = nullptr, Node *parent = nullptr) :
            key_(key),
            left_(left),
            right_(right),
            parent_(parent) {}
  };

  Node *root_;

  void add_recursive(Node *node, T key);

  int get_count(Node *node) const;

  int get_height_tree(Node *node) const;

  void delete_tree(Node *node);

  void clean_tree(Node *node);

  Node *find_node(Node *node, T key);

  StackList<T> add_tree_to_stack(Node *root);

  StackList<T> add_tree_to_stack_2(Node *root, bool status);
};

template<class T>
void BinarySearchTree<T>::erase_tree() {
  delete_tree(root_);
}

template<class T>
BinarySearchTree<T>::BinarySearchTree() :
        root_(nullptr) {}

template<class T>
void BinarySearchTree<T>::add_iter(const T &key) {
  Node *tmp = new Node(key);
  Node *head = root_;
  if (head == nullptr) {
    root_ = tmp;
    return;
  }
  while (head != nullptr) {
    if (tmp->key_ < head->key_) {
      if (head->left_ == nullptr) {
        tmp->parent_ = head;
        head->left_ = tmp;
        return;
      }
      head = head->left_;
    } else if (tmp->key_ > head->key_) {
      if (head->right_ == nullptr) {
        tmp->parent_ = head;
        head->right_ = tmp;
        return;
      }
      head = head->right_;
    }
  }
  if (tmp->key_ < head->key_) {
    tmp->parent_ = head;
    head->left_ = tmp;
  } else {
    tmp->parent_ = head;
    head->right_ = tmp;
  }
}

template<class T>
void BinarySearchTree<T>::add_rec(T key) {
  add_recursive(root_, key);
}

template<class T>
bool BinarySearchTree<T>::search(const T &key) {
  Node *head = root_;
  while (head != nullptr) {
    if (head->key_ == key) {
      return true;
    }
    if (key < head->key_) {
      head = head->left_;
    } else if (key > head->key_) {
      head = head->right_;
    }
  }
  return false;
}

template<class T>
T BinarySearchTree<T>::search_next(const T &key) {
  Node *head = root_;
  while (head != nullptr) {
    if (head->key_ == key) {
      if (head->left_ != nullptr) {
        return head->left_->key_;
      } else if (head->right_ != nullptr) {
        return head->right_->key_;
      } else {
        return key;
      }
    }
    if (key < head->key_) {
      head = head->left_;
    } else if (key > head->key_) {
      head = head->right_;
    }
  }
  return NULL;
}

template<class T>
int BinarySearchTree<T>::get_count_knots() const {
  int count = get_count(root_);
  return count;
}

template<class T>
int BinarySearchTree<T>::get_height() const {
  int count = get_height_tree(root_);
  return count;
}

template<class T>
void BinarySearchTree<T>::remove(const T &key) {
  Node *element = root_;
  StackList<T> stack = add_tree_to_stack(root_);
  StackList<T> stack_reverse;
  while (!stack.is_empty()) {
    stack_reverse.push(stack.pop());
  }
  clean_tree(root_);
  while (!stack_reverse.is_empty()) {

    T elem = stack_reverse.pop();
    if (elem != key) {
      this->add_iter(elem);
    }
  }
}

template<class T>
void BinarySearchTree<T>::print_element(std::ostream &out, T key) {
  Node *node = find_node(root_, key);
  bool is_root = false;
  bool have_l = false;
  bool have_r = false;
  bool have_p = false;
  if (node == root_) {
    is_root = true;
  }
  if (node->left_ != nullptr) {
    have_l = true;
  }
  if (node->right_ != nullptr) {
    have_r = true;
  }
  if (node->parent_ != nullptr) {
    have_p = true;
  }
  out << "----------------------------------------- \n"
      << "INFORMATION ABOUT NODE WITH KEY: " << key << "\n"
      << "VALUE: " << node->key_ << "\n"
      << "IS THIS ROOT: " << is_root << "\n"
      << "HAVE LEFT ch: " << have_l << "\n"
      << "HAVE RIGHT ch: " << have_r << "\n"
      << "HAVE PARENT: " << have_p << "\n"
      << "----------------------------------------- \n";
}

template<class T>
int BinarySearchTree<T>::get_height_tree(Node *node) const {
  int height_l = 0;
  int height_r = 0;
  if (node->left_ != nullptr) {
    height_l = get_height_tree(node->left_);
  }
  if (node->right_ != nullptr) {
    height_r = get_height_tree(node->right_);
  }
  if (height_r > height_l) {
    return height_r + 1;
  } else {
    return height_l + 1;
  }
}

template<class T>
int BinarySearchTree<T>::get_count(Node *node) const {
  static int count = 0;
  if (node != nullptr) {
    count++;
    get_count(node->left_);
    get_count(node->right_);
  }
  return count;
}

template<class T>
void BinarySearchTree<T>::add_recursive(Node *node, T key) {
  if (node == nullptr) {
    node = new Node(key);
  } else {
    if (key < node->key_) {
      add_recursive(node->left_, key);
    }
    if (key > node->key_) {
      add_recursive(node->right_, key);
    }
  }
}

template<class T>
void BinarySearchTree<T>::clean_tree(Node *node) {
  if (node != nullptr) {
    clean_tree(node->left_);
    clean_tree(node->right_);
    if (node == root_) {
      node->key_ = NULL;
      node->left_ = nullptr;
      node->right_ = nullptr;
      node->parent_ = nullptr;
      root_ = nullptr;
      return;
    }
    Node *parent = node->parent_;
    if (parent->left_ == node) {
      parent->left_ = nullptr;
      delete node;
    } else if (parent->right_ == node) {
      parent->right_ = nullptr;
      delete node;
    }
  }
}

template<class T>
void BinarySearchTree<T>::delete_tree(Node *node) {
  if (node != nullptr) {
    delete_tree(node->left_);
    delete_tree(node->right_);
    if (node != root_) {
      Node *parent = node->parent_;
      if (parent->left_ == node) {
        parent->left_ = nullptr;
        delete node;
      } else {
        parent->right_ = nullptr;
        delete node;
      }

    } else
      delete node;
  }
}

template<class T>
typename BinarySearchTree<T>::Node *BinarySearchTree<T>::find_node(Node *node, T key) {
  Node *left;
  Node *right;
  if (node != nullptr) {
    if (node->key_ == key) {
      return node;
    } else {
      left = find_node(node->left_, key);
      if (left != nullptr) {
        if (left->key_ == key) {
          return left;
        }
      }
      right = find_node(node->right_, key);
      if (right != nullptr) {
        if (right->key_ == key) {
          return right;
        }
      }
    }
  } else {
    return node;
  }
}

template<class T>
StackList<T> BinarySearchTree<T>::add_tree_to_stack(Node *root) {
  static StackList<T> stack;
  static int iter = 0;
  if (root != nullptr) {
    iter++;
    stack.push(root->key_);
    add_tree_to_stack(root->left_);
    add_tree_to_stack(root->right_);
  }
  iter--;
  return stack;
}

template<class T>
void BinarySearchTree<T>::iter_width() {
  Node *temp = root_;
  QueueList<Node *> tre;
  tre.enQueue(temp);
  while (temp != nullptr && !tre.isEmpty()) {
    Node *temp = tre.deQueue();
    print_element(std::cout, temp->key_);
    if (temp->left_ != nullptr) {
      tre.enQueue(temp->left_);
    }
    if (temp->right_ != nullptr) {
      tre.enQueue(temp->right_);
    }
  }
}

template<class T>
void BinarySearchTree<T>::iter_left_right() {
  Node *iter = root_;
  StackList<Node *> stack;
  while ((iter != nullptr) || (!stack.is_empty())) {
    if (iter != nullptr) {
      stack.push(iter);
      iter = iter->left_;
    } else {
      iter = stack.pop();
      print_element(std::cout, iter->key_);
      iter = iter->right_;
    }
  }
}

template<class T>
bool BinarySearchTree<T>::is_same(BinarySearchTree<T> src) {
  StackList<T> one = add_tree_to_stack_2(src.root_, true);
  StackList<T> two = add_tree_to_stack_2(root_, true);
  if (one.get_size() != two.get_size()) {
    return false;
  }
  bool status = false;
  while (!one.is_empty()) {
    T num_1 = one.pop();
    while (!two.is_empty()) {
      T num_2 = two.pop();
      if (num_1 == num_2) {
        status = true;
        break;
      } else {
        status = false;
      }
    }
    if (status == false) {
      return status;
    }
  }

  return status;
}

template<class T>
StackList<T> BinarySearchTree<T>::add_tree_to_stack_2(BinarySearchTree::Node *root, bool status) {
  static StackList<T> stack;
  if (root != nullptr) {
    stack.push(root->key_);
    add_tree_to_stack_2(root->left_, false);
    add_tree_to_stack_2(root->right_, false);
  }
  StackList<T> temp(stack);
  if (status) {
    stack.~StackList();
  }
  return temp;
}

#endif