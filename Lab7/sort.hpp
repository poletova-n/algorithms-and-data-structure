#ifndef SORT_HPP
#define SORT_HPP

#include<iostream>

template <class T>
T* sort_count(T* arr, size_t size);
void sort_digit(int arr[], size_t size);
void bucket_sort(int arr[], size_t size);
bool check_sort_1(int arr[], size_t size);
template <class T>
bool check_sort_2(T* arr, size_t size);
void print(int arr[], size_t size);
template <class T>
void print_2(T* arr, size_t size);

template <class T>
T max_num(T* arr, size_t size) {
  T max = arr[0];
  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }
  return max;
}

template <class T>
T* sort_count(T* arr, size_t size) {
  for (int i = 0; i < size; i++) {
    int count = 0;
    for (int j = 0; j < size; j++) {
      if (arr[i] > arr[j]) {
        count++;
      }
    }
    T temp = arr[count];
    arr[count] = arr[i];
    arr[i] = temp;
  }
  return arr;
}

void sort_digit(int arr[], size_t size)
{
  int sign = 1;
  int s_sort[size];
  int max_n = max_num<int>(arr, size);

  while (max_n / sign > 0) {
    int razr[10] = { 0 };
    for (int i = 0; i < size; i++) {
      razr[(arr[i] / sign) % 10]++;
    }
    for (int i = 1; i < 10; i++) {
      razr[i] += razr[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
      s_sort[--razr[(arr[i] / sign) % 10]] = arr[i];
    }
    for (int i = 0; i < size; i++) {
      arr[i] = s_sort[i];
    }
    sign *= 10;
  }
}

void bucket_sort(int arr[], size_t size) {
  const int max = size;
  int bucket[10][max + 1];
  for (int x = 0; x < 10; x++)
    bucket[x][max] = 0;
  for (int digit = 1; digit <= 1000000000; digit *= 10) {
    for (size_t i = 0; i < max; ++i) {
      int dig = (arr[i] / digit) % 10;
      bucket[dig][bucket[dig][max]++] = arr[i];
    }
    int idx = 0;
    for (int x = 0; x < 10; ++x) {
      for (int y = 0; y < bucket[x][max]; y++) {
        arr[idx++] = bucket[x][y];
      }
      bucket[x][max] = 0;
    }
  }
}

bool check_sort_1(int arr[], size_t size) {
  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }
  return true;
}

template <class T>
bool check_sort_2(T* arr, size_t size) {
  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) {
      return false;
    }
  }
  return true;
}

void print(int arr[], size_t size) {
  std::cout<<"\n------------------------------------\n";
  for(int i =0; i<size; i++){
    std::cout << arr[i] << " ";
  }
  std::cout<<"\n------------------------------------\n";
}

template <class T>
void print_2(T* arr, size_t size) {
  std::cout<<"\n------------------------------------\n";
  for(int i =0; i<size; i++){
    std::cout << arr[i] << " ";
  }
  std::cout<<"\n------------------------------------\n";
}
#endif
