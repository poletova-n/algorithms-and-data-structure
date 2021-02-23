//
// Created by Алена Рыжова on 21.02.2021.
//

#ifndef TEST_MAIN_H_
#define TEST_MAIN_H_
#include "BinarySearchTree.h"
void testBinaryTree1()
{
  BinarySearchTree<int> tree;
  if (tree.insert(2))
    std::cout << "Node with the key = " << 2 << " field added\n";
  if (tree.insert(5))
    std::cout << "Node with the key = " << 5 << " field added\n";
  if (tree.insert(4))
    std::cout << "Node with the key = " << 4 << " field added\n";
  if (tree.insert(-1))
    std::cout << "Node with the key = " << -1 << " field added\n";
  if (tree.insert(2))
    std::cout << "Node with the key = " << 2 << " field added\n";
  if (tree.insert(6))
    std::cout << "Node with the key = " << 6 << " field added\n";
  if (tree.insert(0))
    std::cout << "Node with the key = " << 0 << " field added\n";
  if (tree.insert(-3))
    std::cout << "Node with the key = " << -3 << " field added\n";
  if (tree.insert(-2))
    std::cout << "Node with the key = " << -2 << " field added\n";
  if (tree.insert(-6))
    std::cout << "Node with the key = " << -6 << " field added\n";
  if (tree.insert(-4))
    std::cout << "Node with the key = " << -4 << " field added\n";
  tree.print(std::cout);
  std::cout << "Count = " << tree.getCount() << "\n";
  std::cout << "Height = " << tree.getHeight() << "\n";
  if (tree.deleteKey(4))
    std::cout << "Node with the key = " << 4 << "  field deleted\n";
  if (tree.deleteKey(-6))
    std::cout << "Node with the key = " << 6 << "  field deleted\n";
  if (tree.deleteKey(-1))
    std::cout << "Node with the key = " << -1 << "  field deleted\n";
  if (tree.deleteKey(10))
    std::cout << "Node with the key = " << 10 << "  field deleted\n";
  if (tree.deleteKey(2))
    std::cout << "Node with the key = " << 10 << "  field deleted\n";
  tree.print(std::cout);
  std::cout << "Infix tree traversal (recursive): ";
  tree.inorderWalk();
  std::cout << "\nInfix tree traversal (iterative): ";
  tree.iterativeInorderWalk();
  std::cout
    << (tree.iterativeSearch(-2) ? "\nNode with field key = 2 found\n" : "\nNode with field key = 2 not found\n");
  std::cout << (tree.iterativeSearch(4) ? "Node with field key = 2 found\n" : "Node with field key = 2 not found\n");
}
void testBinaryTree2()
{
  std::cout << "tree1\n";
  BinarySearchTree<std::string> tree1;
  if (tree1.insert("12345"))
    std::cout << "Node with the key = 12345 field added\n";
  if (tree1.insert("678910"))
    std::cout << "Node with the key = 678910 field added\n";
  if (tree1.insert("1324"))
    std::cout << "Node with the key = 1324 field added\n";
  if (tree1.insert("1345"))
    std::cout << "Node with the key = 1345 field added\n";
  if (tree1.insert("2455"))
    std::cout << "Node with the key = 2455 field added\n";
  if (tree1.insert("Abcd"))
    std::cout << "Node with the key = Abcd field added\n";
  std::cout<<"tree1 = ";
  tree1.print(std::cout);
  try
  {
    BinarySearchTree<std::string> tree2(tree1.rValue());
    std::cout << "\nDemonstration of the move constructor\n";
    std::cout << "tree1: ";
    tree1.print(std::cout);
    std::cout << "tree2: ";
    tree2.print(std::cout);
  }
  catch (const std::invalid_argument &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  std::cout<<"tree3\n";
  BinarySearchTree<char> tree3;
  if (tree3.insert('a'))
    std::cout << "Node with the key = a field added\n";
  if (tree3.insert('b'))
    std::cout << "Node with the key = b field added\n";
  if (tree3.insert('q'))
    std::cout << "Node with the key = q field added\n";
  if (tree3.insert('1'))
    std::cout << "Node with the key = 1 field added\n";
  if (tree3.insert('!'))
    std::cout << "Node with the key = ! field added\n";
  if (tree3.insert('?'))
    std::cout << "Node with the key = ? field added\n";
  std::cout<<"tree3 = ";
  tree3.print(std::cout);
  std::cout << "Demonstration of the operation of the assignment operator by moving\n";
  BinarySearchTree<char> tree4;
  tree4 = tree3.rValue();
  std::cout << "tree3 = ";
  tree3.print(std::cout);
  std::cout << "tree4 = ";
  tree4.print(std::cout);

}
void testBinaryTree3()
{
  BinarySearchTree<double> tree1;
  std::cout << "tree1\n";
  if (tree1.insert(2.5))
    std::cout << "Node with the key = 2.5 field added\n";
  if (tree1.insert(-1.234))
    std::cout << "Node with the key = -1.234 field added\n";
  if (tree1.insert(4))
    std::cout << "Node with the key = 4 field added\n";
  if (tree1.insert(2.34))
    std::cout << "Node with the key = 2.34 field added\n";
  if (tree1.insert(8.76))
    std::cout << "Node with the key = 8.76 field added\n";
  if (tree1.insert(9.23))
    std::cout << "Node with the key = 9.23 field added\n";
  if (tree1.insert(0))
    std::cout << "Node with the key = 0 field added\n";
  if (tree1.insert(1))
    std::cout << "Node with the key = 1 field added\n";
  BinarySearchTree<double> tree2;
  std::cout << "\ntree2\n";
  if (tree2.insert(2.5))
    std::cout << "Node with the key = 2.5 field added\n";
  if (tree2.insert(-1.234))
    std::cout << "Node with the key = -1.234 field added\n";
  if (tree2.insert(4))
    std::cout << "Node with the key = 4 field added\n";
  if (tree2.insert(2.34))
    std::cout << "Node with the key = 2.34 field added\n";
  if (tree2.insert(8.76))
    std::cout << "Node with the key = 8.76 field added\n";
  if (tree2.insert(9.23))
    std::cout << "Node with the key = 9.23 field added\n";
  if (tree2.insert(0))
    std::cout << "Node with the key = 0 field added\n";
  if (tree2.insert(1))
    std::cout << "Node with the key = 1 field added\n";
  std::cout<<"tree1 = ";
  tree1.print(std::cout);
  std::cout<<"tree2 = ";
  tree2.print(std::cout);
  std::cout << (tree1 == tree2 ? "Trees tree1 and tree2 are equal\n\n" :
                "Trees tree1 and tree2 are not equal\n");
  BinarySearchTree<double> tree3;
  std::cout << "tree3\n";
  if (tree3.insert(0))
    std::cout << "Node with the key = 2.5 field added\n";
  if (tree3.insert(1.5))
    std::cout << "Node with the key = -1.234 field added\n";
  if (tree3.insert(-2.5))
    std::cout << "Node with the key = 4 field added\n";
  if (tree3.insert(4.85))
    std::cout << "Node with the key = 2.34 field added\n";
  std::cout<<"tree2 = ";
  tree2.print(std::cout);
  std::cout<<"tree3 = ";
  tree3.print(std::cout);
  std::cout << (tree3 == tree2 ? "Trees tree3 and tree2 are equal\n" :
                "Trees tree3 and tree2 are not equal\n");

}
#endif
