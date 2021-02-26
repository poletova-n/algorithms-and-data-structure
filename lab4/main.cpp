#include "BinarySearchTree.h"
#include <string>
#include <utility>

void firstTree();
void secondTree();
void thirdTree();

int main()
{
  firstTree();
  secondTree();
  thirdTree();
  return 0;
}

void firstTree()
{
  std::cout << "Create int tree!\n";
  BinarySearchTree<int> tree1;

  std::cout << (tree1.insert(8) ? "correct insert 8\n" : "oops... we can't insert 8\n");
  std::cout << (tree1.insert(12) ? "correct insert 12\n" : "oops... we can't insert 12\n");
  std::cout << (tree1.insert(6) ? "correct insert 6\n" : "oops... we can't insert 6\n");
  std::cout << (tree1.insert(8) ? "correct insert 8\n" : "oops... we can't insert 8 again\n");
  std::cout << (tree1.insert(7) ? "correct insert 7\n" : "oops... we can't insert 7\n");
  std::cout << (tree1.insert(5) ? "correct insert 5\n" : "oops... we can't insert 5\n");
  std::cout << (tree1.insert(-3) ? "correct insert -3\n" : "oops... we can't insert -3\n");
  std::cout << (tree1.insert(10) ? "correct insert 10\n" : "oops... we can't insert 10\n");
  std::cout << (tree1.insert(17) ? "correct insert 17\n" : "oops... we can't insert 17\n");
  std::cout << (tree1.insert(15) ? "correct insert 15\n" : "oops... we can't insert 15\n");
  std::cout << (tree1.insert(11) ? "correct insert 11\n" : "oops... we can't insert 11\n");

  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "At int tree now we have " << tree1.getCount() << " nodes\n";
  std::cout << "------------------------------------------------------------------------------------\n";

  std::cout << (tree1.deleteKey(-3) ? "correct delete -3\n" : "oops... we can't delete -3\n");
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree1.deleteKey(90) ? "correct delete 90\n" : "oops... we can't delete 90\n");
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree1.deleteKey(7) ? "correct delete 7\n" : "oops... we can't delete 7\n");
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree1.deleteKey(6) ? "correct delete 6\n" : "oops... we can't delete 6\n");
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree1.deleteKey(10) ? "correct delete 10\n" : "oops... we can't delete 10\n");
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree1.deleteKey(12) ? "correct delete 12\n" : "oops... we can't delete 12\n");
  std::cout << "Int tree now: "; tree1.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";

  std::cout << "At int tree now we have " << tree1.getCount() << " nodes\n";

  std::cout << "Iterative infix walk: "; tree1.iterativeInorderWalk();
  std::cout << "Recursive infix walk: "; tree1.inorderWalk();
  std::cout << "------------------------------------------------------------------------------------\n";

  std::cout << "Try to find key = 11: " << (tree1.iterativeSearch(11) ? "Yes, we found\n" : "No, we didn't find\n");
  std::cout << "Try to find key = 7: " << (tree1.iterativeSearch(7) ? "Yes, we found\n" : "No, we didn't find\n");
  std::cout << "------------------------------------------------------------------------------------\n\n\n";
}


void secondTree()
{
  std::cout << "Create string tree!\n";
  BinarySearchTree<std::string> tree2;

  std::cout << (tree2.insert("Sunday") ? "correct insert Sunday\n" : "oops... we can't insert Sunday\n");
  std::cout << (tree2.insert("Monday") ? "correct insert Monday\n" : "oops... we can't insert Monday\n");
  std::cout << (tree2.insert("Tuesday") ? "correct insert Tuesday\n" : "oops... we can't insert Tuesday\n");
  std::cout << (tree2.insert("Wednesday") ? "correct insert Wednesday\n" : "oops... we can't insert Wednesday again\n");
  std::cout << (tree2.insert("Thursday") ? "correct insert Thursday\n" : "oops... we can't insert Thursday\n");
  std::cout << (tree2.insert("Friday") ? "correct insert Friday\n" : "oops... we can't insert Friday\n");
  std::cout << (tree2.insert("Saturday") ? "correct insert Saturday\n" : "oops... we can't insert Saturday\n");
  std::cout << (tree2.insert("March") ? "correct insert March\n" : "oops... we can't insert March\n");
  std::cout << (tree2.insert("April") ? "correct insert April\n" : "oops... we can't insert April\n");
  std::cout << (tree2.insert("June") ? "correct insert June\n" : "oops... we can't insert June\n");
  std::cout << (tree2.insert("December") ? "correct insert December\n" : "oops... we can't insert 11\n");

  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << "String tree now: "; tree2.print(std::cout);
  std::cout << "At string tree now we have " << tree2.getCount() << " nodes\n";
  std::cout << "------------------------------------------------------------------------------------\n";

  std::cout << (tree2.deleteKey("June") ? "correct delete June\n" : "oops... we can't delete June\n");
  std::cout << "String tree now: "; tree2.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree2.deleteKey("October") ? "correct delete October\n" : "oops... we can't delete October\n");
  std::cout << "String tree now: "; tree2.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree2.deleteKey("Wednesday") ? "correct delete Wednesday\n" : "oops... we can't delete Wednesday\n");
  std::cout << "String tree now: "; tree2.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree2.deleteKey("Tuesday") ? "correct delete Tuesday\n" : "oops... we can't delete Tuesday\n");
  std::cout << "String tree now: "; tree2.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree2.deleteKey("Friday") ? "correct delete Friday\n" : "oops... we can't delete Friday\n");
  std::cout << "String tree now: "; tree2.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree2.deleteKey("December") ? "correct delete December\n" : "oops... we can't delete December\n");
  std::cout << "String tree now: "; tree2.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";

  std::cout << "At string tree now we have " << tree2.getCount() << " nodes\n";

  std::cout << "Iterative infix walk: "; tree2.iterativeInorderWalk();
  std::cout << "Recursive infix walk: "; tree2.inorderWalk();
  std::cout << "------------------------------------------------------------------------------------\n";

  std::cout << "Try to find key = March: " << (tree2.iterativeSearch("March") ? "Yes, we found\n" : "No, we didn't find\n");
  std::cout << "Try to find key = OOO: " << (tree2.iterativeSearch("OOO") ? "Yes, we found\n" : "No, we didn't find\n");
  std::cout << "------------------------------------------------------------------------------------\n\n\n";
}


void thirdTree()
{
  std::cout << "Create first double tree!\n";
  BinarySearchTree<double> tree3;

  std::cout << "First Double tree now: "; tree3.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
  std::cout << (tree3.deleteKey(12.43) ? "correct delete 12.43\n" : "oops... we can't delete 12.43\n");
  std::cout << "First Double tree now: "; tree3.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n\n\n";

  std::cout << "Create second double tree!\n";
  BinarySearchTree<double> tree4;
  std::cout << "Second Double tree now: "; tree4.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";

  if (tree3 == tree4)
    std::cout << "This double binary trees is equal!\n";
  else
    "\nThis double binary trees is NOT equal!\n";
  std::cout << "------------------------------------------------------------------------------------\n";

  std::cout << (tree4.insert(8.54) ? "correct insert 8.54\n" : "oops... we can't insert 8.54\n");
  std::cout << "Second Double tree now: "; tree4.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";

  if (tree3 == tree4)
    std::cout << "\nThis double binary trees is equal!\n";
  else
    std::cout << "This double binary trees is NOT equal!\n"; 
  std::cout << "------------------------------------------------------------------------------------\n";


  std::cout << "Create copy double tree!\n";
  BinarySearchTree<double> tree5(std::move(tree4));
  std::cout << "Copy Double tree now: "; tree5.print(std::cout);
  std::cout << "Second Double tree now: "; tree4.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";

  std::cout << "And now we assign tree5 to tree3!\n";
  tree3 = std::move(tree5);
  std::cout << "Copy Double tree now: "; tree5.print(std::cout);
  std::cout << "First Double tree now: "; tree3.print(std::cout);
  std::cout << "------------------------------------------------------------------------------------\n";
}