#ifndef LAB6_TESTSORTS_HPP
#define LAB6_TESTSORTS_HPP
#include <cstdlib>
#include <ostream>
bool isSorted(const int *array);
void printArray(int* array, size_t size, std::ostream &out);
void testShakerSort();
void testBucketSort();
void testQuickSort();
#endif
