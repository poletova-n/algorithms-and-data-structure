#include <iostream>

#include "algorithmSorts.h"

const size_t SIZE = 8;

int main()
{
  std::cout << "\t\t\t\tTest in the best case of sort functions:\n";
  std::cout << "The best case with counting sort:\n";
  int contingsortArr1[SIZE] = { 6,4,2,1,3,5,0,7 };
  countingSort(contingsortArr1, SIZE);
  print(contingsortArr1, SIZE);
  std::cout << '\n';
  std::cout << "The best case with radix sort:\n";
  int radixsortArr1[SIZE] = { 36, 54, 72, 81, 13, 25, 40, 67 };
  radixSort(radixsortArr1, SIZE);
  print(radixsortArr1, SIZE);
  std::cout << '\n';
  std::cout << "The best case with bucket sort:\n";
  double bucketsortArr1[SIZE] = { 0.5, 0.1, 0.3, 0.2, 0.6, 0.8, 0.4, 0.7 };
  bucketSort(bucketsortArr1, SIZE);
  print(bucketsortArr1, SIZE);
  std::cout << '\n';


  std::cout << "\t\t\t\tTest in the average case of sort functions:\n";
  std::cout << "The average case with counting sort:\n";
  int contingsortArr2[SIZE] = { 6,14,20,11,3,5,0,7 };
  countingSort(contingsortArr2, SIZE);
  print(contingsortArr2, SIZE);
  std::cout << '\n';
  std::cout << "The average case with radix sort:\n";
  int radixsortArr2[SIZE] = { 3, 14, 32, 81, 15, 25, 40, 6 };
  radixSort(radixsortArr2, SIZE);
  print(radixsortArr2, SIZE);
  std::cout << '\n';
  std::cout << "The average case with bucket sort:\n";
  double bucketsortArr2[SIZE] = { 0.15, 0.1, 0.36, 0.21, 0.82, 0.84, 0.89, 0.17 };
  bucketSort(bucketsortArr2, SIZE);
  print(bucketsortArr2, SIZE);
  std::cout << '\n';


  std::cout << "\t\t\t\tTest in the worst case of sort functions:\n";
  std::cout << "The worst case with counting sort:\n";
  int contingsortArr3[SIZE] = { 6,14,20,11,3,5,0,10000 };
  countingSort(contingsortArr3, SIZE);
  print(contingsortArr3, SIZE);
  std::cout << '\n';
  std::cout << "The worst case with radix sort:\n";
  int radixsortArr3[SIZE] = { 3, 11, 21, 31, 41, 1, 40, 6090 };
  radixSort(radixsortArr3, SIZE);
  print(radixsortArr3, SIZE);
  std::cout << '\n';
  std::cout << "The worst case with bucket sort:\n";
  double bucketsortArr3[SIZE] = { 8, 3, 7, 12, 10, 4, 90, 1000 };
  bucketSort(bucketsortArr3, SIZE);
  print(bucketsortArr3, SIZE);
  std::cout << '\n';

  return 0;
}
