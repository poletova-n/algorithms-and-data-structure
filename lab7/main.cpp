#include <iostream>
#include <vector>

#include "sort.hpp"

int main()
{
  std::cout << "\nSorting by count sort\n";
  {
    std::vector<int> array = {5, 3, 7, 8, 1, 2, 0};
    std::vector<int> originArray = array;
    std::cout << "1 array: ";
    print(array);
    std::cout << "\n";
    countingSort(array);
    std::cout << "sorted by counting sort 1 array: ";
    print(array);
    std::cout << "\n";
    isSorted(originArray, array);
    std::cout << "\n";

    std::vector<int> array2 = {102300, 80700, 34000, 82902, 354526};
    std::vector<int> originArray2 = array2;
    std::cout << "2 array: ";
    print(array2);
    std::cout << "\n";
    countingSort(array2);
    std::cout << "sorted by counting sort 2 array: ";
    print(array2);
    std::cout << "\n";
    isSorted(originArray2, array2);
  }

  std::cout << "\nSorting by radix sort\n";

  {
    std::vector<int> array = {5, 3, 7, 8, 1, 2, 0};
    std::vector<int> originArray = array;
    std::cout << "1 array: ";
    print(array);
    std::cout << "\n";
    radixSort(array);
    std::cout << "sorted by radix sort 1 array: ";
    print(array);
    std::cout << "\n";
    isSorted(originArray, array);
    std::cout << "\n";

    std::vector<int> array2 = {102300, 80700, 34000, 82902, 354526};
    std::vector<int> originArray2 = array2;
    std::cout << "2 array: ";
    print(array2);
    std::cout << "\n";
    countingSort(array2);
    std::cout << "sorted by radix sort 2 array: ";
    print(array2);
    std::cout << "\n";
    isSorted(originArray2, array2);
  }

  std::cout << "\nSorting by bucket sort\n";

  {
    std::vector<int> array = {5, 3, 7, 8, 1, 2, 0};
    std::vector<int> originArray = array;
    std::cout << "1 array: ";
    print(array);
    std::cout << "\n";
    bucketSort(array);
    std::cout << "sorted by bucket sort 1 array: ";
    print(array);
    std::cout << "\n";
    isSorted(originArray, array);
    std::cout << "\n";

    std::vector<int> array2 = {102300, 80700, 34000, 82902, 354526};
    std::vector<int> originArray2 = array2;
    std::cout << "2 array: ";
    print(array2);
    std::cout << "\n";
    bucketSort(array2);
    std::cout << "sorted by bucket sort 2 array: ";
    print(array2);
    std::cout << "\n";
    isSorted(originArray2, array2);
  }

  return 0;
}
