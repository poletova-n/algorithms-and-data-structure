#ifndef FUNCTION_SORT_HPP
#define FUNCTION_SORT_HPP

#include "iostream"

int binarySearch(int* arr, int left, int right, int key)
{
	if (left >= right) {
		return (key > arr[left] ? left + 1 : left);
	}
	else {
		int middle = (left + right) / 2;
		if (arr[middle] == key) {
			return middle + 1;
		}
		else if (arr[middle] > key) {
			return binarySearch(arr, left, middle - 1, key);
		}
		else if (arr[middle] < key) {
			return binarySearch(arr, middle + 1, right, key);
		}
	}
}

void insertionSort(int* arr, int size)
{
	if (size <= 0) {
		return;
	}

	int key;
	for (int i = 0; i < size; i++) {
		int j = i;
		key = arr[i];
		int select = binarySearch(arr, 0, j - 1, key);
		while (j > select) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = key;
	}
}

void radixSort(int* arr, int size)
{
	if (size <= 0) {
		return;
	}

	int max = arr[0];
	for (int i = 1; i < size; i++)
	{
		if (max < arr[i]) {
			max = arr[i];
		}
	}

	for (int i = 1; max / i > 0; i *= 10) {
		int* out = new int[size];
		int count[10] = { 0 };

		for (int j = 0; j < size; j++){
			count[(arr[j] / i) % 10]++;
		}

		for (int j = 1; j < 10; j++) {
			count[j] += count[j-1];
		}

		for (int j = size-1; j >= 0; j--) {
			out[count[(arr[j] / i) % 10] - 1] = arr[j];
			count[(arr[j] / i) % 10]--;
		}

		for (int j = 0; j < size; j++) {
			arr[j] = out[j];
		}

		delete[] out;
	}
}

void merge(int arr[], int first, int last, int mid) 
{
	int i, size = last - first + 1;
	int a_first = first, a_last = mid - 1;
	int b_first = mid, b_last = last;
	int* temp = new int[size];

	for (i = 0; i < size; i++) {

		if (a_first <= a_last) {

			if (b_first <= b_last) {

				if (arr[a_first] <= arr[b_first])

					temp[i] = arr[a_first++];

				else temp[i] = arr[b_first++];
			}

			else temp[i] = arr[a_first++];
		}

		else temp[i] = arr[b_first++];
	}

	for (i = 0; i < size; i++) {
		arr[first + i] = temp[i];
	}

	delete[] temp;
}

void mergeSort(int* arr, int size)
{
	int i, left; 
	for (i = 1; i <= size - 1; i = 2 * i)
	{
		for (left = 0; left < size - 1; left = left + i * 2)
		{
			int right = left + (i * 2) - 1;
			int middle = (left + right + 1) / 2;

			if (right >= size) {
				right = size - 1;
			}
			merge(arr, left, right, middle);
		}
	}
}
#endif
