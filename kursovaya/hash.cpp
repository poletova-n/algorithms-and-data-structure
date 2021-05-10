#include "hash.hpp"
#include <iostream>
#include <string>

int hash_horner(const std::string& s, int table_size, const int key){
  int hash_result = 0;
  for (int i = 0; i < s.size(); ++i){
    hash_result += (key * hash_result + s[i]) % table_size;
  }
  hash_result = (hash_result * 2 + 1) % table_size;
  return hash_result;
}
int my_hash(const std::string& s, int table_size){
  int hash_result = 0;
  int max_simv = 0;
  int sred_simv = 0;
  for(int i =0; i<s.size();i++){
    if(max_simv<s[i]){
      max_simv = s[i];
    }
    sred_simv += s[i];
  }
  sred_simv /= s.size();
  hash_result = (max_simv + s.size() - sred_simv)%table_size;
  return hash_result;
}