#include <iostream>
#include <algorithm>
#include "utility.hpp"
#include "encryption.hpp"

int main()
{
  preparation::Symbols map;
  std::vector<char> text = preparation::readFromFile(map);
  map.showAll();
  std::vector<BinaryTree::Node*> vec = encryption::makeTree(map);
  std::map<char, std::vector<bool>> table = encryption::makeTable(vec);
  std::vector<bool> encryptedText = encryption::encrypt(text, table);
  std::cout << "\n encrypted text: \n";
  for (auto it = encryptedText.begin(); it != encryptedText.end(); ++it)
  {
    std::cout << *it;
  }
  std::cout << '\n';
  BinaryTree::Node* root = details::findRoot(vec);
  std::vector<char> decryptedText = decryption::decrypt(encryptedText, root);
  std::cout << "\n decrypted text: \n";
  for (auto it = decryptedText.begin(); it != decryptedText.end(); ++it)
  {
    std::cout << *it;
  }
  std::cout << '\n';
}
