#include <iostream>
#include <random>

#include "BinarySearchTree.h"

void fillTestTree(BinarySearchTree<int>& tree, int maxValue, int size, int step)
{
  const int maxIterationsPerGeneration = 1000;
  const double mean = maxValue / 2;
  std::default_random_engine generator(time(nullptr));
  std::normal_distribution<float> distribution(mean, step);
  for (int i = 0; i < size; i++) {
    int number;
    for (int k = 0; k < maxIterationsPerGeneration; k++) {
      number = static_cast<int> (distribution(generator));
      if (!tree.iterativeSearch(number)) {
        break;
      }
    }
    tree.insert(number);
  }
}

void emptyTests(BinarySearchTree<int>& emptyTree1, BinarySearchTree<int>& emptyTree2)
{
  std::cout << "Empty tree:\n";
  emptyTree1.print(std::cout);
  emptyTree1.deleteKey(1);
  std::cout << "Amount of nodes in empty tree: " << emptyTree1.getCount()
            << "\nHeight of empty tree: " << emptyTree1.getHeight()
            << "\n1 is presented in empty tree: " << (emptyTree1.iterativeSearch(1) ? "true" : "false")
            << "\nEmpty trees are equal: " << (emptyTree1 == emptyTree2 ? "true\n" : "false\n");
}

void gettersTest(BinarySearchTree<int>& tree)
{
  std::cout << "Tree's height is " << tree.getHeight()
            << "\nAmount of nodes in tree is " << tree.getCount() << '\n';
}

void searchTest(BinarySearchTree<int>& tree, int maxValue)
{
  const int testsAmount = 4;
  for (int i = 0; i < testsAmount; i++) {
    std::cout << maxValue / 2 - i << " is presented in tree:"
              << (tree.iterativeSearch(maxValue / 2 - i) ? "true\n" : "false\n");
  }
}

void walkTest(BinarySearchTree<int>& tree)
{
  std::cout << "Recursive inorder walk:\n";
  tree.inorderWalk();
  std::cout << "Iterative inorder walk:\n";
  tree.iterativeInorderWalk();
}

void deleteTest(BinarySearchTree<int>& tree, int maxValue)
{
  tree.deleteKey(tree.getRootKey());
  std::cout << "After deleting root:\n";
  tree.print(std::cout);

  const int testsAmount = 4;
  for (int i = 0; i < testsAmount; i++) {
    tree.deleteKey(maxValue / 2 - i);
    std::cout << "After deleting " << maxValue / 2 - i <<  ":\n";
    tree.print(std::cout);
  }
}

void moveTest(BinarySearchTree<int>& source, BinarySearchTree<int>& destination)
{
  destination = source.copy();
  std::cout << "After moving copy of first tree to second tree:\nFirst tree:\n";
  source.print(std::cout);
  std::cout << "Second tree:\n";
  destination.print(std::cout);
  std:: cout << "Trees are " << (source == destination ? "" : "not ") << "equal\n";
  source.insert(100);
  std::cout << "After inserting 100 into first tree:\nFirst tree:\n";
  source.print(std::cout);
  std::cout << "Second tree:\n";
  destination.print(std::cout);
}

int main()
{
  BinarySearchTree<int> tree1;
  BinarySearchTree<int> tree2;

  emptyTests(tree1, tree2);

  const int tree1MaxValue = 34;
  const int tree1Size = 10;
  const int tree1Step = 4;
  fillTestTree(tree1, tree1MaxValue, tree1Size,  tree1Step);
  std::cout << "After filling first tree with normally distributed numbers around "
            << tree1MaxValue / 2 << ":\n";
  tree1.print(std::cout);

  gettersTest(tree1);
  walkTest(tree1);
  searchTest(tree1, tree1MaxValue);
  deleteTest(tree1, tree1MaxValue);

  const int tree2MaxValue = 60;
  const int tree2Size = 20;
  const int tree2Step = 6;
  fillTestTree(tree2, tree2MaxValue, tree2Size,  tree2Step);
  std::cout << "After filling second tree with normally distributed numbers around "
            << tree2MaxValue / 2 << ":\n";
  tree2.print(std::cout);

  std::cout << "After distribution with different parameters trees are"
            << (tree1 == tree2 ? "" : " not") << " equal\n";

  moveTest(tree1, tree2);
  return 0;
}
