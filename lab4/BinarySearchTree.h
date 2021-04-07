#include <iostream>

template<class T>
class Tree
{
private:
  template<class T>
  struct Node
  {
    T key_;
    Node<T>* left_;
    Node<T>* right_;

    Node(T key, Node* left = nullptr, Node* right = nullptr) :
      key_(key), left_(left), right_(right)
    {
    }
  };
  Node<T>* root_;

  void swap(Tree<T>& left, Tree<T>& right) noexcept;

  void deleteSubtree(Node<T>* node);

  Node<T>* iterativeSearchNode(const T& key) const;

  void printNode(std::ostream& out, Node<T>* root) const;

  int getCountSubTree(const Node<T>* node) const;

  int getHeightSubTree(Node<T>* node) const;

  Node<T>* nextNode(const T& key);

  void copyNodes(const Node<T>* root);

public:
  Tree();

  Tree(const Tree<T>& src);

  Tree(Tree<T>&& src) noexcept;

  Tree <T>& operator= (const Tree<T>& src);

  Tree <T>& operator= (Tree<T>&& src);

  virtual ~Tree();

  bool iterativeSearch(const T& key) const;

  bool insert(const T& key);

  bool deleteKey(const T& key);

  void print(std::ostream& out) const;

  int getCount() const;

  int getHeight() const;

};
