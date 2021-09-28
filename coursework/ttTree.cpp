#include "ttTree.h"
#include <iomanip>
#include <sstream>

ttTree::ttTree()
{
  root = nullptr;
}

void ttTree::printTree(std::ostream& out)
{
  out << "2-3 Tree Index:\n-------------------------\n";
  printTreeHelper(root, out);
}

void ttTree::buildTree(std::ifstream& input)
{
  int line = 1, numWords = 0, distWords = 0, treeHeight;
  std::string tempLine, tempWord;
  while (!input.eof())
  {
    getline(input, tempLine);
    for (int i = 0; i < tempLine.length(); i++)
    {
      while (tempLine[i] != ' ' && tempLine[i] != '\n' && i < tempLine.length())
      {
        tempWord.insert(tempWord.end(), tempLine[i]);
        i++;
      }

      while (tempWord.length() > 0 && !isalnum(tempWord[tempWord.length() - 1]))
        tempWord.resize(tempWord.size() - 1);

      if (tempWord.length() > 0)
      {
        words.push_back(tempWord);
        root = insert(tempWord, line, root, distWords);
        numWords++;
        tempWord.clear();
      }
    }
    line++;
  }

  treeHeight = findHeight(root);

  std::cout << "=====================================================" << '\n';
  std::cout << "- Built Tree results (2-3 Tree)" << '\n';
  std::cout << "=====================================================" << '\n';

  std::cout << std::setw(40) << std::left;
  std::cout << "Total number of words: " << numWords << '\n';

  std::cout << std::setw(40) << std::left
            << "Total number of distinct words: " << distWords << '\n';

  std::cout << std::setw(40) << std::left
            << "Height of 2-3 Tree is: " << treeHeight << '\n';
}

ttTree::node* ttTree::createNode(const std::string& x, node* left, node* middle)
{
  node* t = new node();
  t->leftKey = x;
  t->left = left;
  t->middle = middle;
  t->right = nullptr;
  return t;
}

bool ttTree::isLeafNode(node* x)
{
  if (x->left == nullptr && x->middle == nullptr && x->right == nullptr)
  {
    return true;
  }
  else
  {
    return false;
  }
}

ttTree::node* ttTree::add(node* x, node* n)
{
  if (x->rightKey.empty())
  {
    if (x->leftKey < n->leftKey)
    {
      x->rightKey = n->leftKey;
      x->rightLines = n->leftLines;
      x->middle = n->left;
      x->right = n->middle;
    }
    else
    {
      x->rightKey = x->leftKey;
      x->rightLines = x->leftLines;
      x->leftKey = n->leftKey;
      x->leftLines = n->leftLines;
      x->right = x->middle;
      x->middle = n->middle;
      x->left = n->left;
    }
    return x;
  }

  else if (x->leftKey >= n->leftKey)
  {
    node* newNode = createNode(x->leftKey, n, x);
    newNode->leftLines = x->leftLines;
    x->left = x->middle;
    x->middle = x->right;
    x->right = nullptr;
    x->leftKey = x->rightKey;
    x->rightKey.clear();
    x->leftLines = x->rightLines;
    x->rightLines.clear();

    return newNode;
  }

  else if (x->rightKey >= n->leftKey)
  {
    node* newNode = createNode(x->rightKey, n->middle, x->right);
    newNode->leftLines = x->rightLines;
    x->middle = n->left;
    n->middle = newNode;
    n->left = x;
    x->rightKey.clear();
    x->right = nullptr;
    x->rightLines.clear();

    return n;
  }

  else
  {
    node* newNode = createNode(x->rightKey, x, n);
    newNode->leftLines = x->rightLines;
    x->right = nullptr;
    x->rightKey.clear();
    x->rightLines.clear();

    return newNode;
  }
}

ttTree::node* ttTree::insert(std::string& key, int line, node* x, int& distWord)
{
  if (key.front() == '(' || key.front() == '"' || key.front() == ':' || key.front() == ';')
  {
    key.erase(key.begin());
  }
  if (x == nullptr)
  {
    node* newNode = createNode(key, nullptr, nullptr);
    newNode->leftLines.push_back(line);
    distWord++;
    return newNode;
  }
  if (key == x->leftKey || key == x->rightKey)
  {
    if (key == x->leftKey)
      x->leftLines.push_back(line);
    else
      x->rightLines.push_back(line);
    return x;
  }
  if (isLeafNode(x))
  {
    node* newNode = createNode(key, nullptr, nullptr);
    newNode->leftLines.push_back(line);
    node* finalNode = add(x, newNode);
    distWord++;
    return finalNode;
  }

  if (key < x->leftKey)
  {
    node* newNode = insert(key, line, x->left, distWord);
    if (newNode == x->left)
      return x;
    else
      return add(x, newNode);
  }

  else if (x->rightKey.empty() || key < x->rightKey)
  {
    node* newNode = insert(key, line, x->middle, distWord);
    if (newNode == x->middle)
      return x;
    else
      return add(x, newNode);
  }

  else
  {
    node* newNode = insert(key, line, x->right, distWord);
    if (newNode == x->right)
      return x;
    else
      return add(x, newNode);
  }
}

void ttTree::printLines(node* x, bool isLeft, std::ostream& out)
{
  if (isLeft)
  {
    if (!x->leftLines.empty())
    {
      out << " " << x->leftLines[0];
      for (int i = 1; i < x->leftLines.size(); i++)
        out << ", " << x->leftLines[i];
    }
  }
  else
  {
    if (!x->rightLines.empty())
    {
      out << " " << x->rightLines[0];
      for (int i = 1; i < x->rightLines.size(); i++)
        out << ", " << x->rightLines[i];
    }
  }
}

void ttTree::print(node* x, std::ostream& out)
{
  if (x->rightKey.empty())
  {
    out << std::setw(30) << std::left;
    out << x->leftKey;
    printLines(x, true, out);
    out << '\n';
  }
  else
  {
    out << std::setw(30) << std::left;
    out << x->leftKey;
    printLines(x, true, out);
    out << '\n';
    out << std::setw(30) << std::left;
    out << x->rightKey;
    printLines(x, false, out);
    out << '\n';
  }
}

void ttTree::printTreeHelper(node* x, std::ostream& out)
{
  if (x != nullptr)
  {
    if (isLeafNode(x))
    {
      print(x, out);
    }
    else
    {
      printTreeHelper(x->left, out);
      out << std::setw(30) << std::left;
      out << x->leftKey;
      printLines(x, true, out);
      out << '\n';
      if (x->middle)
      {
        printTreeHelper(x->middle, out);
        if (!x->rightKey.empty())
        {
          out << std::setw(30) << std::left;
          out << x->rightKey;
          printLines(x, false, out);
          out << '\n';
        }
      }
      printTreeHelper(x->right, out);
    }
  }
}

int ttTree::findHeight(node* x)
{
  if (x == nullptr)
    return 0;
  else
  {
    int leftHeight = findHeight(x->left), rightHeight = findHeight(x->right);
    int middleHeight = findHeight(x->middle);
    if (leftHeight > rightHeight && leftHeight > middleHeight)
      return (leftHeight + 1);
    else if (rightHeight > leftHeight && rightHeight > middleHeight)
      return (rightHeight + 1);
    else
      return (middleHeight + 1);
  }
}