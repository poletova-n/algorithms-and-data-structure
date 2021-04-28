#include <iostream>
#include <vector>

#include "functions.hpp"
#include "countingSort.hpp"
#include "radixSort.hpp"
#include "bucketSort.hpp"

int main()
{
  std::vector<int> vectorForCountingSort({ 2,5,3,0,2,3,0,3 });
  const size_t size = 8;
  const int maxElement = 5;
  std::vector<int> resultForCountingSort(countingSort(vectorForCountingSort, size, maxElement));
  std::cout << "Counting sort\n"
    << "Input: ";
  print(vectorForCountingSort, std::cout);
  std::cout << "\nOutput: ";
  print(resultForCountingSort, std::cout);
  std::cout << "\n\nRadix sort\n"
    << "Input: ";
  std::vector<int> vectorForRadixSort({ 39,47,54,1534,2,7722,5321,59,7534,147,165,34,1,41,101,32 });
  const int length = 4;
  const int rang = 10;
  print(vectorForRadixSort, std::cout);
  std::cout << "\nOutput: ";
  std::vector<int> resultForRadixSort(radixSort(vectorForRadixSort, length, rang));
  print(resultForRadixSort, std::cout);
  std::cout << "\n\nBucket sort\n"
    << "Input: ";
  std::vector<double> vectorForBucketSort({ 0.48,0.54,0.74,0.576,0.421,0.57,0.3,0.5,0.6,0.7 });
  print(vectorForBucketSort, std::cout);
  std::vector<double> resultForBucketSort(bucketSort(vectorForBucketSort));
  std::cout << "\nOutput: ";
  print(resultForBucketSort, std::cout);
  std::cout << "\n";
}