#ifndef TEST_HPP
#define TEST_HPP
#include <iostream>
#include "sort.hpp"

void print(int* arr, int size);

void testSelectionSort()
{
    const int size = 10;
    std::cout << "Best case\n";
    int arr[size] = { 1, 1, 2, 2, 3, 3, 4, 4, 5, 5};
    std::cout << "Array before sorting: ";
    print(arr, size);
    insertionSort(arr, size);
    std::cout << "Array after sorting: ";
    print(arr, size);

    std::cout << "\nMiddle case\n";
    int arr2[size] = { 38, 2, 30, 4, 5, 16, 7, 3, 99 ,100 };
    std::cout << "Array before sorting: ";
    print(arr2, size);
    insertionSort(arr2, size);
    std::cout << "Array after sorting: ";
    print(arr2, size);

    std::cout << "\nWorst case\n";
    int arr3[size] = {99, 60, 55, 39, 23, 17, 15, 9, 8 , 1};
    std::cout << "Array before sorting: ";
    print(arr3, size);
    insertionSort(arr3, size);
    std::cout << "Array after sorting: ";
    print(arr3, size);
}

void testRadixSort()
{
    const int size = 9;
    std::cout << "Best case\n";
    int arr[size] = { 1, 2, 3, 4, 5, 6, 7, 8, 9};
    std::cout << "Array before sorting: ";
    print(arr, size);
    radixSort(arr, size);
    std::cout << "Array after sorting: ";
    print(arr, size);

    std::cout << "\nMiddle case\n";
    int arr2[size] = { 5,67, 9, 8, 13, 22, 110, 200};
    std::cout << "Array before sorting: ";
    print(arr2, size);
    radixSort(arr2, size);
    std::cout << "Array after sorting: ";
    print(arr2, size);

    std::cout << "\nWorst case\n";
    int arr3[size] = {100, 30, 9, 88, 77, 99, 8, 3 };
    std::cout << "Array before sorting: ";
    print(arr3, size);
    radixSort(arr3, size);
    std::cout << "Array after sorting: ";
    print(arr3, size);
}

void testMergeSort()
{
    const int size = 8;
    std::cout << "Best case\n";
    int arr[size] = { 2,3,4,4,4,4,4,5 };
    std::cout << "Array before sorting: ";
    print(arr, size);
    mergeSort(arr, size);
    std::cout << "Array after sorting: ";
    print(arr, size);

    std::cout << "\nMiddle case\n";
    int arr2[size] = { 5, 65, 7, 99, 13, 17, 88 };
    std::cout << "Array before sorting: ";
    print(arr2, size);
    mergeSort(arr2,size);
    std::cout << "Array after sorting: ";
    print(arr2, size);

    std::cout << "\nWorst case\n";
    int arr3[size] = { 9, 8 ,7, 6, 5 ,4, 3, 2 };
    std::cout << "Array before sorting: ";
    print(arr3, size);
    mergeSort(arr3, size);
    std::cout << "Array after sorting: ";
    print(arr3, size);
}

void print(int* arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}
#endif 
