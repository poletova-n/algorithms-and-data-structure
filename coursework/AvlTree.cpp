#include "AvlTree.h"
#include "Stack.h"
#include <stdexcept>

AvlTree::AvlTree() : root_(nullptr)
{}

AvlTree::AvlTree(AvlTree&& src) noexcept
{
  root_ = nullptr;
  swap(src);
}

AvlTree& AvlTree::operator=(AvlTree&& src) noexcept
{
  root_ = nullptr;
  swap(src);
  return *this;
}

AvlTree::~AvlTree()
{
  deleteSubtree(root_);
}

void AvlTree::deleteSubtree(AvlTree::Node* node)
{
  if (node != nullptr)
  {
    deleteSubtree(node->left_);
    deleteSubtree(node->right_);
    delete node;
  }
}

void AvlTree::swap(AvlTree& src)
{
  std::swap(root_, src.root_);
}

bool AvlTree::iterativeSearch(const std::string& key)  const
{
  return (iterativeSearchNode(key) != nullptr);
}

AvlTree::Node* AvlTree::iterativeSearchNode(const std::string& key) const
{
  if (root_ == nullptr || root_->key_ == key)
  {
    return root_;
  }
  AvlTree::Node* root = root_;
  while (root != nullptr && root->key_ != key)
  {
    if (root->key_ < key)
    {
      root = root->right_;
    }
    else
    {
      root = root->left_;
    }
  }
  return root;
}

int AvlTree::getHeight() const
{
  return getHeightSubTree(this->root_);
}

int AvlTree::getHeightSubTree(Node* node) const
{
  if (node == nullptr)
  {
    return 0;
  }
  else
  {
    return (1 + std::max(getHeightSubTree(node->left_), getHeightSubTree(node->right_)));
  }
}

AvlTree::Node* AvlTree::makeRightSmallRotate(Node* tree)
{
  AvlTree::Node* newTree = tree->left_;
  tree->left_ = newTree->right_;
  newTree->right_ = tree;
  fixNodeHeight(tree);
  fixNodeHeight(newTree);

  return newTree;
}

AvlTree::Node* AvlTree::makeLeftSmallRotate(Node* tree)
{
  AvlTree::Node* newTree = tree->right_;
  tree->right_ = newTree->left_;
  newTree->left_ = tree;
  fixNodeHeight(tree);
  fixNodeHeight(newTree);
  return newTree;
}

int AvlTree::getBalanceFactor(Node* node) const
{
  if (node)
  {
    if (node->left_ && node->right_)
    {
      return node->right_->height_ - node->left_->height_;
    }
    else if (node->left_)
    {
      return -node->left_->height_;
    }
    else if (node->right_)
    {
      return node->right_->height_;
    }
  }
  return 0;
}

void AvlTree::fixNodeHeight(Node* node)
{
  if (node->left_ && node->right_)
  {
    int leftHeight = node->left_->height_;
    int rightHeight = node->right_->height_;
    node->height_ = (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
  }
  else if (node->left_)
  {
    node->height_ = node->left_->height_;
  }
  else if (node->right_)
  {
    node->height_ = node->right_->height_;
  }
}

AvlTree::Node* AvlTree::balanceTree()
{
  fixNodeHeight(root_);
  if (getBalanceFactor(root_) == 2) //big left rotate
  {
    if (getBalanceFactor(root_->right_) < 0)
      root_->right_ = makeRightSmallRotate(root_->right_);
    return makeLeftSmallRotate(root_);
  }

  if (getBalanceFactor(root_) == -2) // big right rotate
  {
    if (getBalanceFactor(root_->left_) > 0)
      root_->left_ = makeLeftSmallRotate(root_->left_);
    return makeRightSmallRotate(root_);
  }
  return root_;
}

void AvlTree::print(std::ostream& out) const
{
  out << "( ";
  printNode(out, root_);
  out << ")";
  out << std::endl;
}

void AvlTree::printNode(std::ostream& out, Node* root) const
{
  out << '(';
  if (root != nullptr)
  {
    out << root->key_;
    printNode(out, root->left_);
    printNode(out, root->right_);
  }
  out << ')';
  }


void AvlTree::inorderWalk(std::ostream& out) const
{
  out << "( ";
  inorderWalk(out, root_);
  out << ')';
  out << std::endl;
}

void AvlTree::inorderWalk(std::ostream& out, Node* node) const
{
  if (node != nullptr)
  {
    inorderWalk(out, node->left_);
    out << "(" << node->key_ << ", " << node->frequency_ << ") ";
    inorderWalk(out, node->right_);
  }
}

int AvlTree::getFrequency(const std::string& key) const
{
  AvlTree::Node* node(iterativeSearchNode(key));
  return node->frequency_;
}


AvlTree::Node* AvlTree::treeMinimum(AvlTree::Node* root)
{
  while (root && root->left_)
  {
    root = root->left_;
  }
  return root;
}

bool AvlTree::deleteKey(const std::string& key)
{
  AvlTree::Node* node = iterativeSearchNode(key);
  if (!node)
  {
    return 0;
  }
  AvlTree::Node* dest = treeMinimum(node->right_);
  if (node->right_ == nullptr || node->left_ == nullptr)
  {
    dest = node;
    AvlTree::Node* replacement = dest->right_;//replacement == nullptr если нет наследников
    if (dest->left_)
    {
      replacement = dest->left_;
    }
    if (replacement)
    {
      replacement->p_ = dest->p_;
    }
    if (!dest->p_)//удаляем корень
    {
      root_ = replacement;
    }
    else if (dest == dest->p_->left_)
    {
      dest->p_->left_ = replacement;
    }
    else
    {
      dest->p_->right_ = replacement;
    }
  }
  else
  {
    node->key_ = dest->key_;
    if (dest->right_)
    {
      dest->right_->p_ = dest->p_;
    }
    dest->p_->left_ = dest->right_;
  }
  delete dest;
  this->balanceTree();
  return 1;
}

bool AvlTree::insert(const std::string& key)
{
  AvlTree::Node* parent = nullptr;
  AvlTree::Node* current = root_;
  while (current)
  {
    parent = current;
    if (key < current->key_)
    {
      current = current->left_;
    }
    else if (key > current->key_)
    {
      current = current->right_;
    }
    else
    {
      current->frequency_++;
      return 1;
    }
  }
  if (!parent)
  {
    root_ = new AvlTree::Node(key);
  }
  else if (key < parent->key_)
  {
    parent->left_ = new AvlTree::Node(key, nullptr, nullptr, parent);
  }
  else
  {
    parent->right_ = new AvlTree::Node(key, nullptr, nullptr, parent);
  }
  this->balanceTree();
  return 1;
}

void AvlTree::printMostCommonWords(std::ostream& out)
{
  if (root_ == nullptr)
  {
    throw std::underflow_error("Print words error: binary search tree is empty.\
n");
  }
  const int N = 3;
  StackArray<Node*> tree;
  AvlTree::Node* current = root_;
  tree.push(current);
  AvlTree::Node* maxArr[N];
  for (int i = 0; i < N; i++)
  {
    maxArr[i] = new AvlTree::Node("");
    maxArr[i]->frequency_ = 0;
  }
  while (!tree.isEmpty())
  {
    for (int i = 0; i < N - 1; i++)
    {
      for (int j = i + 1; j < N; j++)
      {
        if (maxArr[i]->frequency_ >= maxArr[j]->frequency_)
        {
          std::swap(maxArr[i], maxArr[j]);
        }
      }
    }
    if (maxArr[0]->frequency_ <= current->frequency_)
    {
      maxArr[0] = current;
    }
    if (current->right_ != nullptr)
    {
      tree.push(current->right_);
    }
    if (current->left_ != nullptr)
    {
      current = current->left_;
    }
    else
    {
      current = tree.pop();
    }
  }
  for (int i = N - 1; i >= 0; i--)
  {
    if (maxArr[i]->frequency_ != 0)
    {
      current = maxArr[i];
      out << current->key_ << " " << current->frequency_ << "\n";
    }
  }
  out << "\n";
}

int AvlTree::getCount()
{
  return getCountSubTree(root_);
}

int AvlTree::getCountSubTree(Node* node) const
{
  if (node == nullptr)
    return 0;
  return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
}
