#include <iostream>
#include <random>
#include "sorts.h"

int main()
{
  std::ios::sync_with_stdio(false);

  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::uniform_real_distribution<> dis(1, 999);

  const size_t SIZE = 20;

  int arrBucket[SIZE];

  std::cout << "Test bucket sort:\ninput:\n";

  for (int & i : arrBucket) {
    i = dis(gen);
    std::cout << i << ' ';
  }

  std::cout << "\nOutput:\n";
  bucketSort(arrBucket, SIZE);

  for (int i : arrBucket) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  int arrCounting[SIZE];

  std::cout << "Test counting sort:\ninput:\n";

  for (int & i : arrCounting) {
    i = dis(gen);
    std::cout << i << ' ';
  }

  std::cout << "\nOutput:\n";

  bucketSort(arrCounting, SIZE);

  for (int i : arrCounting) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  int arrRadix[SIZE];

  std::cout << "Test radix sort:\ninput:\n";

  for (int & i : arrRadix) {
    i = dis(gen);
    std::cout << i << ' ';
  }

  std::cout << "\nOutput:\n";

  bucketSort(arrRadix, SIZE);

  for (int i : arrRadix) {
    std::cout << i << ' ';
  }
  std::cout << '\n';

  return 0;
}
