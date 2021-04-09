#include <iostream>

#include "sorts.hpp"

int main()
{
  int size = 0;
  std::cout << "Enter array size: \n";
  std::cin >> size;
  if (std::cin.fail())
  {
    std::cerr << "Error in size";
    return 1;
  }
  std::cout << "Created array of " << size << " unsigned integers: \n";
  std::vector<int> arr = utility::createVector(size);
  utility::print(arr);
  std::cout << "Sorted array by counting sort: \n";
  std::vector<int> sorted = sorts::countingSort(arr);
  utility::print(sorted);
  std::cout << "Sorted array by radix sort: \n";
  std::vector<int> sorted2 = sorts::radixSort(arr);
  utility::print(sorted2);
  std::cout << "Sorted array by bucket sort: \n";
  std::vector<int> sorted3 = sorts::bucketSort(arr, 12);
  utility::print(sorted3);



  std::cout << "Started test for best and worst scenario: \n";
  std::cout << "Counting sort: \n";
  std::cout << "Best scenario: \n";
  std::vector<int> sortedCountBest = sorts::countingSort({1, 4, 2, 9, 5, 1});
  utility::print(sortedCountBest);
  std::cout << "Worst scenario: \n";
  std::vector<int> sortedCountWorst = sorts::countingSort({12402105, 215215, 125126, 4363147, 3234235, 32532363});
  utility::print(sortedCountWorst);
  std::cout << "Radix sort: \n";
  std::cout << "Best scenario: \n";
  std::vector<int> sortedRadixBest = sorts::radixSort({1, 4, 2, 9, 5, 1});
  utility::print(sortedRadixBest);
  std::cout << "Worst scenario: \n";
  std::vector<int> sortedRadixWorst = sorts::radixSort({1124215, 2125125, 2326327, 12373256, 254854, 1548548});
  utility::print(sortedRadixWorst);
  std::cout << "Bucket sort: \n";
  std::cout << "Best scenario: \n";
  std::vector<int> sortedBucketBest = sorts::bucketSort({1, 4, 2, 9, 5, 1, 4, 2, 3, 11, 10, 11}, 12);
  utility::print(sortedBucketBest);
  std::cout << "Worst scenario: \n";
  std::vector<int> sortedBucketWorst = sorts::bucketSort({1002, 4124, 215215, 91255, 5125126, 121521,
                                                          1002, 4124, 215215, 91255, 5125126, 121521}, 12);
  utility::print(sortedBucketWorst);
  return 0;
}