#include <iostream>
#include <windows.h>

#include "RedBlackTree.hpp"

void emptyDictionaryTest();

void dictionaryTest();

int main()
{
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(866);
  std::cout << std::boolalpha;

  emptyDictionaryTest();
  dictionaryTest();

  return 0;
}

void emptyDictionaryTest()
{
  RedBlackTree emptyDictionary;
  std::cout << "Empty dictionary:\n";
  emptyDictionary.print(std::cout);
  std::cout << "After removing the word river from empty dictionary:\n";
  emptyDictionary.print(std::cout);
  std::cout << "Dictionary contains word river: " << emptyDictionary.find("river");
}

void dictionaryTest()
{
  RedBlackTree dictionary;
  std::cout << "\n\nTrying to add record with invalid english word w1n:\n";
  try {
    dictionary.add("w1n", "победа, выигрыш");
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << '\n';
  }

  std::cout << "Trying to add record without translation:\n";
  try {
    dictionary.add("log", "");
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << '\n';
  }

  std::cout << "Trying to add record with invalid russian word д0м:\n";
  try {
    dictionary.add("house", "д0м");
  } catch (const std::invalid_argument& e) {
    std::cout << e.what() << '\n';
  }

  std::cout << "\nDictionary:\n";
  dictionary.add("wealth", "богатство, ценность");
  dictionary.add("try", "пытаться, пробовать");
  dictionary.add("deny", "отрицать, отказывать");
  dictionary.add("diet", "диета, питание");
  dictionary.add("call", "позвонить, позвать");
  dictionary.add("add", "добавлять, складывать");
  dictionary.add("win", "победа, выигрыш");
  dictionary.add("river", "река, речка");
  dictionary.add("one", "один, единица");
  dictionary.add("tea", "чай");
  dictionary.add("clear", "очистить, убрать");
  dictionary.add("get", "получить, достать");
  dictionary.add("mortal", "смертный, летальный, фатальный");
  dictionary.print(std::cout);
  std::cout << "\nDictionary contains word tea: " << dictionary.find("tea");
  std::cout << "\nDictionary contains word coffee: "<< dictionary.find("coffee");
  dictionary.remove("tea");
  std::cout << "\nAfter removing the word tea, dictionary contains word tea: " << dictionary.find("tea");
  std::cout << std::endl;
}
