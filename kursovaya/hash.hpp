#ifndef KURSOVAYA_HASH_HPP
#define KURSOVAYA_HASH_HPP
#include <iostream>
#include <string>

int hash_horner(const std::string& s, int table_size, const int key);
int my_hash(const std::string& s, int table_size);
struct hash_1
{
  int operator()(const std::string& s, int table_size) const
  {
    return hash_horner(s, table_size, table_size - 1);
  }
};
struct hash_2
{
  int operator()(const std::string& s) const
  {
    return my_hash(s, 3);
  }
};
#endif
