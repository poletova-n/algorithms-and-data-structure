#include "tests.h"
#include "AVLTree.h"
#include "details.h"
#include "list.h"
#include <iostream>


void testAVLTree()
{
  AVLTree dictionary;
  dictionary.insert("ab", "about");
  std::cout << "\nTree after the node(ab, about) is added: \n";
  dictionary.printTree(std::cout);
  dictionary.insert("ce", "certain");
  std::cout << "\nTree after the node(ce, certain) is added: \n";
  dictionary.printTree(std::cout);
  dictionary.insert("ab", "above");
  std::cout << "\nTree after the node(ab, above) is added: \n";
  dictionary.printTree(std::cout);
  dictionary.insert("di", "different");
  std::cout << "\nTree after the node(di, different) is added: \n";
  dictionary.printTree(std::cout);
  dictionary.insert("ab", "absolutely");
  std::cout << "\nTree after the node(ab, absolutely) is added: \n";
  dictionary.printTree(std::cout);
  dictionary.insert("re", "removed");
  std::cout << "\nTree after the node(re, removed) is added: \n";
  dictionary.printTree(std::cout);
  dictionary.insert("ti", "tired");
  std::cout << "\nTree after the node(ti, tired) is added: \n";
  dictionary.printTree(std::cout);
  dictionary.insert("he", "hello");
  std::cout << "\nTree after the node(he, hello) is added: \n";
  dictionary.printTree(std::cout);
  dictionary.insert("ae", "aesthetic");
  std::cout << "\nTree after the node(ae, aesthetic) is added: \n";
  dictionary.printTree(std::cout);
  std::cout << "\nNumber of nodes present in the tree: " << dictionary.getCount() << '\n';
  std::cout << "The complete AVL tree(tree browsed left-right-parent): \n";
  dictionary.printTree(std::cout);
  std::cout << '\n';
}

void testInsert()
{
  AVLTree dictionary;
  std::cout << "\nAdded wrong keyword (34): ";
  try
  {
    dictionary.insert("34", "abcxyz");
  }
  catch (const myExceptions::ErrorSyntax exp)
  {
    std::cout << exp.what() << '\n';
  }
  std::cout << "Added wrong keyword (a b): ";
  try
  {
    dictionary.insert("a b", "abcxyz");
  }
  catch (const myExceptions::ErrorSyntax exp)
  {
    std::cout << exp.what() << '\n';
  }
  std::cout << "\n";
  std::cout << "Added wrong word (cdsc4vfv): ";
  try
  {
    dictionary.insert("ab", "abcdsc4vfv");
  }
  catch (const myExceptions::ErrorSyntax exp)
  {
    std::cout << exp.what() << '\n';
  }
  std::cout << "Added wrong word (about absolutely): ";
  try
  {
    dictionary.insert("ab", "about absolutely");
  }
  catch (const myExceptions::ErrorSyntax exp)
  {
    std::cout << exp.what() << '\n';
  }
  std::cout << "Added wrong word (about.): ";
  try
  {
    dictionary.insert("ab", "about.");
  }
  catch (const myExceptions::ErrorSyntax exp)
  {
    std::cout << exp.what() << '\n';
  }
  std::cout << "\n";
  std::cout << "Added right keyword and word (ab, abcxyz): \n";
  dictionary.insert("ab", "abcxyz");
  dictionary.printTree(std::cout);
  std::cout << "\n";
}

void testSearch()
{
  AVLTree dictionary;
  std::cout << "\nSearch for words in a blank dictionary: ";
  try
  {
    dictionary.search("ab");
  }
  catch (const myExceptions::EmptyDictionary& exp)
  {
    std::cout << exp.what() << '\n';
  }
  dictionary.insert("ab", "about");
  dictionary.insert("ce", "certain");
  dictionary.insert("ab", "above");
  dictionary.insert("di", "different");
  dictionary.insert("ab", "absolutely");
  dictionary.insert("ab", "able");
  dictionary.insert("ae", "aesthetic");
  dictionary.insert("re", "removed");
  dictionary.insert("ti", "tired");
  dictionary.insert("he", "hello");

  std::cout << "\nIn case of the wrong keyword search (ab2): ";
  try
  {
    dictionary.search("ab2");
  }
  catch (const myExceptions::ErrorSyntax& exp)
  {
    std::cout << exp.what() << '\n';
  }
  std::cout << "\nIn the case of the dictionary, there is no word in the keyword to be searched: ";
  try
  {
    dictionary.search("ve");
  }
  catch (const myExceptions::NoWordFound& exp)
  {
    std::cout << exp.what() << '\n';
  }
  std::cout << "\nFind words with keywords (ab) in the dictionary: ";
  dictionary.search("ab").print(std::cout);
  std::cout << "\nFind words with keywords (AB) in the dictionary: ";
  dictionary.search("ab").print(std::cout);
  std::cout << "\nFind words with keywords (Ab) in the dictionary: ";
  dictionary.search("ab").print(std::cout);

  std::cout << "\n\n";

}

void testDeleteKey()
{
  AVLTree dictionary;
  std::cout << "\nIn case of deleting a keyword from an empty dictionary: ";
  try
  {
    dictionary.deleteKey("ab");
  }
  catch (const myExceptions::EmptyDictionary& exp)
  {
    std::cout << exp.what() << '\n';
  }
  std::cout << "\nKeywords to delete syntax error(abc): ";
  try
  {
    dictionary.deleteKey("ab2");
  }
  catch (const myExceptions::ErrorSyntax& exp)
  {
    std::cout << exp.what() << '\n';
  }
  std::cout << "\nKeywords to delete syntax error(abc): ";
  dictionary.insert("ab", "about");
  dictionary.insert("ce", "certain");
  dictionary.insert("ab", "above");
  dictionary.insert("di", "different");
  dictionary.insert("ab", "absolutely");
  dictionary.insert("ab", "able");
  dictionary.insert("ae", "aesthetic");
  dictionary.insert("re", "removed");
  dictionary.insert("ti", "tired");
  dictionary.insert("he", "hello");

  std::cout << "The complete AVL tree(tree browsed left-right-parent): \n";
  dictionary.printTree(std::cout);
  std::cout << '\n';

  std::cout << "\nTree after deleting keyword (ab): \n";
  dictionary.deleteKey("ab");
  dictionary.printTree(std::cout);
  std::cout << "\nTree after deleting keyword (re): \n";
  dictionary.deleteKey("re");
  dictionary.printTree(std::cout);
  std::cout << "\nTree after deleting keyword (ae): \n";
  dictionary.deleteKey("ae");
  dictionary.printTree(std::cout);
  std::cout << "\nTree after deleting keyword (ce): \n";
  dictionary.deleteKey("ce");
  dictionary.printTree(std::cout);

  std::cout << "\nTree after deleting keyword (he): \n";
  dictionary.deleteKey("he");
  dictionary.printTree(std::cout);
  std::cout << "\nTree after deleting keyword (ti): \n";
  dictionary.deleteKey("ti");
  dictionary.printTree(std::cout);
  std::cout << "\nTree after deleting keyword (di): \n";
  dictionary.deleteKey("di");
  dictionary.printTree(std::cout);
  std::cout << '\n';
}
