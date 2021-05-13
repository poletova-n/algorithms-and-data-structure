#include "tests.hpp"

#include <iostream>
#include <string>

#include "binarySearchTree.hpp"
#include "list.hpp"

void addNonRussianWordToList()
{
  List testList;
  std::string englishWord = ("EnglishWord");
  testList.addElem(englishWord);
}

void addNonRussianWordToTree()
{
  List testList;
  std::string russianWord = "Слово";
  testList.addElem(russianWord);
  BinarySearchTree testTree;
  testTree.insert(russianWord, testList);
}

void addToTreeWordThatIsThere()
{
  List testList;
  std::string russianWord = "Слово";
  std::string englishWord = "Test";
  testList.addElem(russianWord);
  BinarySearchTree testTree;
  testTree.insert(englishWord, testList);
  testTree.insert(englishWord, testList);
}

void removeWordFromEmptyTree()
{
  BinarySearchTree emptyTree;
  std::string testWord = "Test";
  emptyTree.remove(testWord);
}

void deleteWordThatIsNotInTree()
{
  List testList;
  std::string russianWord = "Слово";
  std::string englishWord = "Test";
  std::string englishWord2 = "Tester";
  testList.addElem(russianWord);
  BinarySearchTree testTree;
  testTree.insert(englishWord, testList);
  testTree.remove(englishWord2);
}

void executeCorrectly()
{
  std::cout << "Create an empty tree and correctly add words and translations to it\n";
  BinarySearchTree testTree;
  std::string firstWord = "Make";
  std::string secondWord = "dog";
  std::string thirdWord = "box";
  std::string fourthWord = "table";
  std::string fifthWord = "take";
  std::string firstWordTranslation1 = "делать";
  std::string firstWordTranslation2 = "производить";
  std::string firstWordTranslation3 = "совершать";
  std::string secondWordTranslation = "собака";
  std::string thirdWordTranslation = "коробка";
  std::string fourthWordTranslation = "стол";
  std::string fifthWordTranslation1 = "принимать";
  std::string fifthWordTranslation2 = "брать";
  List translationWord1;
  List translationWord2;
  List translationWord3;
  List translationWord4;
  List translationWord5;
  translationWord1.addElem(firstWordTranslation1);
  translationWord1.addElem(firstWordTranslation2);
  translationWord1.addElem(firstWordTranslation3);
  translationWord2.addElem(secondWordTranslation);
  translationWord3.addElem(thirdWordTranslation);
  translationWord4.addElem(fourthWordTranslation);
  translationWord5.addElem(fifthWordTranslation1);
  translationWord5.addElem(fifthWordTranslation2);
  testTree.insert(firstWord, translationWord1);
  testTree.insert(secondWord, translationWord2);
  testTree.insert(thirdWord, translationWord3);
  testTree.insert(fourthWord, translationWord4);
  testTree.insert(fifthWord, translationWord5);
  std::cout << "Lets print our tree:\n\nList view:";
  testTree.print(std::cout);
  std::cout << "\nAs a hierarchy:\n";
  testTree.printWithHierarchy(std::cout);
  std::cout << "\nLets remove word from tree\n";
  testTree.remove(firstWord);
  std::cout << "Lets print our tree:\n\nList view:";
  testTree.print(std::cout);
  std::cout << "\nAs a hierarchy:\n";
  testTree.printWithHierarchy(std::cout);
}
