#ifndef BINARYSEARCHTREE_HPP
#define BINARYSEARCHTREE_HPP

#include "binarySearchTree.hpp"

void testBinarySearchTree()
{
  BinarySearchTree<double> tree1;
  std::cout << "\ntree1\n";
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
  std::cout << "tree2\n";
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

  std::cout << "\n\tTEST1. IDENTICAL TREES\n";
  std::cout << "\ntree1 = ";
  tree1.print(std::cout);
  std::cout << "tree1 (iterativeInorderWalk) = ";
  tree1.iterativeInorderWalk();
  std::cout << "\ntree2 = ";
  tree2.print(std::cout);
  std::cout << "tree2 (iterativeInorderWalk) = ";
  tree2.iterativeInorderWalk();
  std::cout << (tree1.similarTree(tree2) ? "\n\nTrees tree1 is similar to tree2\n\n" :
                "\n\nTrees tree1 is not similar to tree2\n");

 BinarySearchTree<double> tree3;
  std::cout << "tree3\n";
  if (tree3.insert(0))
    std::cout << "Node with the key = 0 field added\n";
  if (tree3.insert(1.5))
    std::cout << "Node with the key = 1.5 field added\n";
  if (tree3.insert(-2.5))
    std::cout << "Node with the key = -2.5 field added\n";
  if (tree3.insert(4.85))
    std::cout << "Node with the key = 4.85 field added\n";

  std::cout << "\n\tTEST 2. DIFFERENT TREES OF DIFFERENT NUMBER OF NODES\n";
  std::cout << "\ntree3 = ";
  tree3.print(std::cout);
  std::cout << "tree3 (iterativeInorderWalk) = ";
  tree3.iterativeInorderWalk();
  std::cout << "\ntree2 = ";
  tree2.print(std::cout);
  std::cout << "tree2 (iterativeInorderWalk) = ";
  tree2.iterativeInorderWalk();
  std::cout << (tree3.similarTree(tree2) ? "\n\nTrees tree3 is similar to tree2\n\n" :
                "\n\nTrees tree3 is not similar to tree2\n\n");

  std::cout << "tree4\n";
  BinarySearchTree<int> tree4;
  if (tree4.insert(3))
    std::cout << "Node with the key = 2 field added\n";
  if (tree4.insert(1))
    std::cout << "Node with the key = 1 field added\n";
  if (tree4.insert(4))
    std::cout << "Node with the key = 3 field added\n";
  std::cout << "tree5\n";
  BinarySearchTree<int> tree5;
  if (tree5.insert(4))
    std::cout << "Node with the key = 3 field added\n";
  if (tree5.insert(1))
    std::cout << "Node with the key = 1 field added\n";
  if (tree5.insert(3))
    std::cout << "Node with the key = 2 field added\n";

  std::cout << "\n\tTEST 3. SIMILAR TREES (NOT EMPTY, NOT DEGENERATE)\n";
  std::cout << "\ntree4 = ";
  tree4.print(std::cout);
  std::cout << "tree4 (iterativeInorderWalk) = ";
  tree4.iterativeInorderWalk();
  std::cout << "\ntree5 = ";
  tree5.print(std::cout);
  std::cout << "tree5 (iterativeInorderWalk) = ";
  tree5.iterativeInorderWalk();
  std::cout << (tree4.similarTree(tree5) ? "\n\nTrees tree4 is similar to tree5\n" :
                "\n\nTrees tree4 is not similar to tree5\n");

  BinarySearchTree<int> tree6;
  BinarySearchTree<int> tree7;

  std::cout << "\n\t TEST 4. EMPTY TREES\n";
  std::cout << "\ntree6 =";
  tree6.print(std::cout);
  std::cout << "tree6 (iterativeInorderWalk) = ";
  tree6.iterativeInorderWalk();
  std::cout << "\ntree7 =";
  tree7.print(std::cout);
  std::cout << "tree7 (iterativeInorderWalk) = ";
  tree7.iterativeInorderWalk();
  std::cout << (tree6.similarTree(tree7) ? "\n\nTrees tree6 is similar to tree7\n" :
                "\n\nTrees tree6 is not similar to tree7\n");

  std::cout << "\n\tTEST 5. EMPTY TREE AND ORDINARY TREE\n";
  std::cout << "\ntree6 =";
  tree6.print(std::cout);
  std::cout << "tree6 (iterativeInorderWalk) = ";
  tree6.iterativeInorderWalk();
  std::cout << "\ntree4 =";
  tree4.print(std::cout);
  std::cout << "tree4 (iterativeInorderWalk) = ";
  tree4.iterativeInorderWalk();
  std::cout << (tree6.similarTree(tree4) ? "\n\nTrees tree6 is similar to tree4\n" :
                "\n\nTrees tree6 is not similar to tree4\n");

  std::cout << "tree8\n";
  BinarySearchTree<int> tree8;
  if (tree8.insert(3))
    std::cout << "Node with the key = 3 field added\n";
  if (tree8.insert(1))
    std::cout << "Node with the key = 1 field added\n";
  if (tree8.insert(-2))
    std::cout << "Node with the key = -2 field added\n";
  if (tree8.insert(-4))
    std::cout << "Node with the key = -4 field added\n";
  if (tree8.insert(-6))
    std::cout << "Node with the key = -6 field added\n";

  std::cout << "\n\tTEST 6. EMPTY TREE AND DEGENERATE TREE\n";
  std::cout << "\ntree6 =";
  tree6.print(std::cout);
  std::cout << "tree6 (iterativeInorderWalk) = ";
  tree6.iterativeInorderWalk();
  std::cout << "\ntree8 =";
  tree8.print(std::cout);
  std::cout << "tree8 (iterativeInorderWalk) = ";
  tree8.iterativeInorderWalk();
  std::cout << (tree6.similarTree(tree8) ? "\n\nTrees tree6 is similar to tree8\n" :
                "\n\nTrees tree6 is not similar to tree8\n");

  std::cout << "\n\tTEST 7. DEGENERATE TREE AND ORDINARY TREE\n";
  std::cout << "\ntree5 =";
  tree5.print(std::cout);
  std::cout << "tree5 (iterativeInorderWalk) = ";
  tree5.iterativeInorderWalk();
  std::cout << "\ntree8 =";
  tree8.print(std::cout);
  std::cout << "tree8 (iterativeInorderWalk) = ";
  tree8.iterativeInorderWalk();
  std::cout << (tree5.similarTree(tree8) ? "\n\nTrees tree5 is similar to tree8\n" :
                "\n\nTrees tree5 is not similar to tree8\n");

  std::cout << "tree9\n";
  BinarySearchTree<int> tree9;
  if (tree9.insert(-6))
    std::cout << "Node with the key = -6 field added\n";
  if (tree9.insert(-8))
    std::cout << "Node with the key = -8 field added\n";
  if (tree9.insert(-23))
    std::cout << "Node with the key = -23 field added\n";
  if (tree9.insert(-24))
    std::cout << "Node with the key = -24 field added\n";
  if (tree9.insert(-25))
    std::cout << "Node with the key = -25 field added\n";

  std::cout << "\n\tTEST 8. NOT SIMILAR DEGENERATE TREES\n";
  std::cout << "\ntree9 =";
  tree9.print(std::cout);
  std::cout << "tree9 (iterativeInorderWalk) = ";
  tree9.iterativeInorderWalk();
  std::cout << "\ntree8 =";
  tree8.print(std::cout);
  std::cout << "tree8 (iterativeInorderWalk) = ";
  tree8.iterativeInorderWalk();
  std::cout << (tree9.similarTree(tree8) ? "\n\nTrees tree9 is similar to tree8\n\n" :
                "\n\nTrees tree9 is not similar to tree8\n\n");

  BinarySearchTree<int> tree10;
  std::cout << "tree10\n";
  if (tree10.insert(3))
    std::cout << "Node with the key = 3 field added\n";
  if (tree10.insert(1))
    std::cout << "Node with the key = 1 field added\n";
  if (tree10.insert(-2))
    std::cout << "Node with the key = -2 field added\n";
  if (tree10.insert(-4))
    std::cout << "Node with the key = -4 field added\n";
  if (tree10.insert(-6))
    std::cout << "Node with the key = -6 field added\n";

  std::cout << "\n\tTEST 9. SIMILAR DEGENERATE TREES\n";
  std::cout << "\ntree10 =";
  tree10.print(std::cout);
  std::cout << "tree10 (iterativeInorderWalk) = ";
  tree10.iterativeInorderWalk();
  std::cout << "\ntree8 =";
  tree8.print(std::cout);
  std::cout << "tree8 (iterativeInorderWalk) = ";
  tree8.iterativeInorderWalk();
  std::cout << (tree10.similarTree(tree8) ? "\n\nTrees tree10 is similar to tree8\n" :
                "\n\nTrees tree10 is not similar to tree8\n");

 std::cout << "\n\n\tTEST 10. HORIZONTAL PASS\n";
 std::cout << "\ntree1 = ";
  tree1.horizontalPass();
  std::cout << "\ntree2 = ";
  tree2.horizontalPass();
  std::cout << "\ntree3 = ";
  tree3.horizontalPass();
  std::cout << "\ntree4 = ";
  tree4.horizontalPass();
  std::cout << "\ntree5 = ";
  tree5.horizontalPass();
  std::cout << "\ntree6 = ";
  tree6.horizontalPass();
  std::cout << "\ntree7 = ";
  tree7.horizontalPass();
  std::cout << "\ntree8 = ";
  tree8.horizontalPass();
  std::cout << "\ntree9 = ";
  tree9.horizontalPass();
  std::cout << "\ntree10 = ";
  tree10.horizontalPass();
}
#endif
