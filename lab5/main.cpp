#include <iostream>

#include "QueueArray.hpp"
#include "BinarySearchTree.h"

int main()
{
  std::cout << "Working with a queue" << std::endl;
  QueueArray<int> queue(7);
  std::cout << "Fill the queue" << std::endl;
  try
  {
    queue.enQueue(7);
    queue.enQueue(6);
    queue.enQueue(5);
    queue.enQueue(4);
    queue.enQueue(3);
    queue.enQueue(2);
    queue.enQueue(1);
  }
  catch (QueueOverflow e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << "Remove the item from the queue and output it" << std::endl;
  try
  {
    std::cout << queue.deQueue() << std::endl;
    std::cout << queue.deQueue() << std::endl;
    std::cout << queue.deQueue() << std::endl;
    std::cout << queue.deQueue() << std::endl;
    std::cout << queue.deQueue() << std::endl;
    std::cout << queue.deQueue() << std::endl;
  }
  catch (QueueUnderflow e)
  {
    std::cout << e.what() << std::endl;
  }
  std::cout << "Iterative Algorithms for Traversing Binary Trees" << std::endl;
  BinarySearchTree<int> tree;
  tree.insert(8);
  tree.insert(3);
  tree.insert(10);
  tree.insert(14);
  tree.insert(1);
  tree.insert(6);
  tree.insert(4);
  tree.insert(7);
  std::cout <<"breadthFirst:" << std::endl;
  tree.breadthFirst();
  std::cout <<"iterativeInorderWalk:" << std::endl;
  tree.iterativeInorderWalk();
  std::cout <<"Let's create a tree with the same keys, but in a different order" << std::endl;
  BinarySearchTree<int> second_tree;
  second_tree.insert(10);
  second_tree.insert(8);
  second_tree.insert(3);
  second_tree.insert(14);
  second_tree.insert(1);
  second_tree.insert(6);
  second_tree.insert(4);
  second_tree.insert(7);
  std::cout <<"Are these trees similar?" << std::endl;
  std::cout << (tree.isSimilarTree(second_tree) ? "These trees are similar" : "These trees are not similar")
            << std::endl;
  std::cout<<"Let's create a tree that will differ from ours by one key"<<std::endl;
  BinarySearchTree<int> third_tree;
  third_tree.insert(11);
  third_tree.insert(8);
  third_tree.insert(3);
  third_tree.insert(14);
  third_tree.insert(1);
  third_tree.insert(6);
  third_tree.insert(4);
  third_tree.insert(7);
  std::cout <<"Are these trees similar?" << std::endl;
  std::cout << (tree.isSimilarTree(third_tree) ? "These trees are similar" : "These trees are not similar")
            << std::endl;
  std::cout <<"Compare the empty tree with the filled" << std::endl;
  BinarySearchTree<int> fourth_tree;
  std::cout <<"Are these trees similar?" << std::endl;
  std::cout << (tree.isSimilarTree(fourth_tree) ? "These trees are similar" : "These trees are not similar")
            << std::endl;
  std::cout <<"Testing traversals on an empty tree" << std::endl;
  std::cout <<"breadthFirst:" << std::endl;
  fourth_tree.breadthFirst();
  std::cout <<"iterativeInorderWalk:" << std::endl;
  fourth_tree.iterativeInorderWalk();
  return 0;
}
