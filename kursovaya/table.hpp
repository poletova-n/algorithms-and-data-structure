#ifndef KURSOVAYA_TABLE_HPP
#define KURSOVAYA_TABLE_HPP
#include "hash.hpp"
#include <string>
#include <vector>
#include <exception>
#include <algorithm>

template <class t_hash_1 = hash_1, class t_hash_2 = hash_2>
class Table
{
  static const int default_size = 100;
  struct Node
  {
    std::vector<std::string> first_value;
    std::vector<std::string> second_value;
    std::vector<std::string> third_value;
    bool first_full;
    bool second_full;
    bool third_full;
    int create_count;
    bool status;
    bool first_deleted;
    bool second_deleted;
    bool third_deleted;
    Node(){
      status = false;
      first_deleted = false;
      second_deleted = false;
      third_deleted = false;
      first_full = false;
      second_full = false;
      third_full = false;
      create_count = 0;
    }
  };
  std::vector<Node> arr;
  int buffer_size;
  int count;
public:
  Table(int size_ = default_size)
  {
    if(size_ <= 0 ) {
      throw std::invalid_argument("Size must be greater than 0! \n");
    }
    count =0;
    buffer_size = size_;
    for(int i =0; i<buffer_size; i++) {
      arr.push_back(Node());
    }
  }
  ~Table()
  {
    for(int i=0; i<buffer_size; i++) {
      arr[i].first_value.clear();
      arr[i].second_value.clear();
      arr[i].third_value.clear();
    }
    arr.clear();
  }

bool Add(std::string en_word, std::string ru_word, const t_hash_1& hash1 = t_hash_1(), const t_hash_2& hash2 = t_hash_2()) {
    if(count == buffer_size - 1) {
      throw std::runtime_error("Table overflow! \n");
    }
  if(en_word.size() <= 1) {
    throw std::invalid_argument("Word must be longer than 1 letter! \n");
  }
  int h1 = hash1(en_word, buffer_size);
  int h2 = hash2(en_word);
  create(h1);
  switch (h2) {
    case 0:
      arr[h1].first_value.push_back(ru_word);
      arr[h1].status = true;
      arr[h1].first_full = true;
      sort(arr[h1].first_value.begin(), arr[h1].first_value.end());
      break;
    case 1:
      arr[h1].second_value.push_back(ru_word);
      arr[h1].status = true;
      arr[h1].second_full = true;
      sort(arr[h1].second_value.begin(), arr[h1].second_value.end());
      break;
    case 2:
      arr[h1].third_value.push_back(ru_word);
      arr[h1].status = true;
      arr[h1].third_full = true;
      sort(arr[h1].third_value.begin(), arr[h1].third_value.end());
      break;
    default:
      throw std::runtime_error("Error with second hash function! \n");
      break;
  }
  return true;
}

  bool Search(std::string en_word, const t_hash_1& hash1 = t_hash_1(), const t_hash_2& hash2 = t_hash_2()) {
    if(en_word.size() <= 1) {
      throw std::invalid_argument("Word must be longer than 1 letter! \n");
    }
    int h1 = hash1(en_word, buffer_size);
    int h2 = hash2(en_word);
    switch (h2) {
      case 0:
        if(arr[h1].status && !arr[h1].first_deleted && arr[h1].first_full){
          for(int i=0; i<arr[h1].first_value.size(); i++){
            std::cout<<"Translation " << en_word << " to RU is "<< arr[h1].first_value[i]<< "\n";
          }
          return true;
        }else{return false;}
        break;
      case 1:
        if(arr[h1].status && !arr[h1].second_deleted && arr[h1].second_full){
          for(int i=0; i<arr[h1].second_value.size(); i++){
            std::cout<<"Translation " << en_word << " to RU is "<< arr[h1].second_value[i]<< "\n";
          }
          return true;
        }else{return false;}
        break;
      case 2:
        if(arr[h1].status && !arr[h1].third_deleted && arr[h1].third_full){
          for(int i=0; i<arr[h1].third_value.size(); i++){
            std::cout<<"Translation " << en_word << " to RU is "<< arr[h1].third_value[i]<< "\n";
          }
          return true;
        }else{return false;}
        break;
      default:
        throw std::runtime_error("Error with second hash function! \n");
        break;
    }
  }
  void Delete(std::string en_word, const t_hash_1& hash1 = t_hash_1(), const t_hash_2& hash2 = t_hash_2()) {
    int h1 = hash1(en_word, buffer_size);
    int h2 = hash2(en_word);
    switch (h2) {
      case 0:
        arr[h1].first_deleted = true;
        break;
      case 1:
        arr[h1].second_deleted = true;
        break;
      case 2:
        arr[h1].third_deleted = true;
        break;
      default:
        throw std::runtime_error("Error with second hash function! \n");
        break;
    }
    rehash();
    count--;
  }
private:
  void rehash() {
    std::vector<Node> temp (arr);
    arr.clear();
    for(int i =0; i<buffer_size; i++) {
      if(temp[i].first_deleted){
        temp[i].first_value.clear();
        temp[i].first_deleted = false;
        temp[i].first_full = false;
      }
      if(temp[i].second_deleted){
        temp[i].second_value.clear();
        temp[i].second_deleted = false;
        temp[i].second_full = false;
      }
      if(temp[i].third_deleted){
        temp[i].third_value.clear();
        temp[i].third_deleted = false;
        temp[i].third_full = false;
      }
      arr.push_back(temp[i]);
    }
    temp.clear();
  }
  void create(int hash){
    if(arr[hash].create_count<3){
      arr[hash].create_count++;
      count++;
    }else{
      throw std::runtime_error("Collision error, 3 hash function collision cases were expected, but the value is exceeded! \n");
    }
  }
};

#endif
