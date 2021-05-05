#ifndef COURSEWORK_TESTS_HPP
#define COURSEWORK_TESTS_HPP

#include <stdexcept>
#include "avltree.hpp"

void testDictionaryWithCorrectArguments()
{
  AVLTree dictionary;
  try {
    dictionary.insert("actress - актриса");
    dictionary.insert("absently - рассеянно");
    dictionary.insert("case - случай, дело");
    dictionary.insert("actor - актер");

    dictionary.print(std::cout);
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what();
  }
}

void testDictionaryWithInvalidArguments()
{
  AVLTree dictionary;
  try {
    dictionary.insert("abse4242ntly - рассеянно");
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    dictionary.insert("");
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    dictionary.insert("elevator- лифт");
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    dictionary.insert("elevator - лифт");
    dictionary.insert("elevator - лифт");
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  }
}

void testSearch()
{
  AVLTree dictionary;
  try {
    dictionary.insert("elevator - лифт");
    dictionary.insert("actress - актриса");
    dictionary.insert("absently - рассеянно");
    dictionary.insert("case - случай, дело");
    dictionary.insert("actor - актер");
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << dictionary.search("elevator") << '\n';
    std::cout << dictionary.search("actor") << '\n';
    std::cout << dictionary.search("absently") << '\n';
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << dictionary.search("hello") << '\n';
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    std::cout << dictionary.search("elev43ator") << '\n';
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  }
}

void testDelete()
{
  AVLTree dictionary;
  try {
    dictionary.insert("elevator - лифт");
    dictionary.insert("actress - актриса");
    dictionary.insert("absently - рассеянно");
    dictionary.insert("case - случай, дело");
    dictionary.insert("actor - акfтер");
    std::cout << "Dictionary before:\n";
    dictionary.print(std::cout);
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    dictionary.deleteKey("elevator");
    std::cout << "Dictionary after deletion \"elevator\":\n";
    dictionary.print(std::cout);
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  }

  try {
    dictionary.deleteKey("elevator");
    std::cout << "Dictionary after deletion \"elevator\":\n";
    dictionary.print(std::cout);
  } catch (const std::invalid_argument& e) {
    std::cerr << e.what() << '\n';
  }
}

#endif
