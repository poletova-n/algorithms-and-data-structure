#ifndef SORTS_HPP
#define SORTS_HPP

int binarySearchForInsertionSort(int data, int* array, int left, int right);
void insertionSort(int* array, int size);
int findMaxForRadixSort(int* array, int size);
void radixSort(int* array, int size);
void shellSortWithShellStep(int* array, int size);
void shellSortWithHibbardStep(int* array, int size);
int increment(int* array, int size);
void shellSortWithSedgewickStep(int* array, int size);

#endif
