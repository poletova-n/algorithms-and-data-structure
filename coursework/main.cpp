#include <iostream>
#include <fstream>
#include <windows.h>
#include "binaryTree.h"

int main() {
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(866);
  Dictionary<std::string> vocabulary;
  std::string filename = "D:\\my_vocabulary.txt"; //поставить свой путь к файлу
  std::ifstream stream(filename);
  try {
    if (!stream.is_open()) {
      throw std::runtime_error("CANNOT OPEN THE FILE");
    }
  }
  catch (const std::runtime_error &error) {
    std::cerr << error.what() << "\n";
    return 2;
  }
  while (!stream.eof()) {
    std::string word;
    getline(stream, word);
    if (word != "") {
      vocabulary.INSERTWORD(word);
    }
    std::string translation;
    getline(stream, translation);
    getline(stream, translation);
    while (translation != "")
    {
      if (translation != "no translations") {
        vocabulary.ADDTRANSLATION(word, translation);
      }
      getline(stream, translation);
    }
  }
  std::string operation;
  std::cout << "Enter the operation code\n";
  std::cin >> operation;
  while (operation != "end") {
    if (operation == "wr") {
      std::string newWord;
      std::cout << "Enter the word you'd like to add\n";
      std::cin >> newWord;
      vocabulary.INSERTWORD(newWord);
    }
    else if (operation == "wrtr") {
      std::string word;
      std::cout << "Enter the word you'd like to add a translation to\n";
      std::cin >> word;
      std::string translation;
      std::cout << "Enter new translation to this word\n";
      std::cin >> translation;
      vocabulary.ADDTRANSLATION(word, translation);
    }
    else if (operation == "tr") {
      std::string word;
      std::cout << "Enter the word you'd like to translate\n";
      std::cin >> word;
      vocabulary.TRANSLATEWORD(word);
    }
    else if (operation == "del") {
      std::string word;
      std::cout << "Enter the word you'd like to delete\n";
      std::cin >> word;
      vocabulary.DELETEWORD(word);
    }
    else if (operation == "check") {
      vocabulary.VIEWALLWORDS();
    }
    else {
      std::cout << "INCORRECT OPERATION, PLEASE TRY AGAIN\n";
    }
    std::cout << "Enter the operation code\n";
    std::cin >> operation;
  }
  vocabulary.reloadTheDictionary(filename);
  return 0;
}
