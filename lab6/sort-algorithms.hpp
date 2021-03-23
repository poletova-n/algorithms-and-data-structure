#ifndef SORT_ALGORITHMS_HPP
#define SORT_ALGORITHMS_HPP

template <typename T>
void shakerSort(T* array, size_t size)
{
  bool isSwapped = true;
  int begin = 0;
  int end = size - 1;

  while (isSwapped) {
    isSwapped = false;
    for (int i = begin; i < end; i++) {
      if (array[i] > array[i + 1]) {
        std::swap(array[i], array[i + 1]);
        isSwapped = true;
      }
    }
    end--;
    if (!isSwapped) {
      break;
    }
    isSwapped = false;
    for (int i = end - 1; i > begin - 1; i--) {
      if (array[i] > array[i + 1]) {
        std::swap(array[i], array[i + 1]);
        isSwapped = true;
      }
    }
    begin++;
  }
}

void countingSort(int* array, size_t size)
{
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }
  int* count = new int[max + 1];
  for (int i = 0; i <= max; i++) {
    count[i] = 0;
  }
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }
  int* result = new int[size];
  for (int i = size - 1; i >= 0; i--) {
    result[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }
  delete[] count;
  for (int i = 0; i < size; i++) {
    array[i] = result[i];
  }
  delete[] result;
}

template<typename T>
void heapify(T* array, size_t size, int initialParent)
{
  int newParent = initialParent;
  int left = 2 * newParent + 1;
  int right = 2 * newParent + 2;
  if (left < size && array[left] > array[newParent]) {
    newParent = left;
  }
  if (right < size && array[right] > array[newParent]) {
    newParent = right;
  }
  if (newParent != initialParent) {
    std::swap(array[newParent], array[initialParent]);
    heapify(array, size, newParent);
  }
}

template <typename T>
void heapSort(T* array, size_t size)
{
  for (int i = size / 2 - 1; i >= 0; i--) {
    heapify(array, size, i);
  }
  for (int i = size - 1; i >= 0; i--) {
    std::swap(array[0], array[i]);
    heapify(array, i, 0);
  }
}

#endif
