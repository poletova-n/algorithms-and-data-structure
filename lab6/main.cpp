#include <iostream>
#include <ctime>
#include <algorithm>

void printArray(const int* arr, int size);
int* shakerSort(const int* arr, int size);
int* countingSort(const int* arr, int size);
void merge(int* a, int sizeA, int* b, int sizeB);
int* mergeSort(const int* arr, int size);
bool checkSort(const int* arr, int size);
void fillRandom(int* arr, int size);

int main()
{
  const int SIZE_SHAKER = 500;
  int SHAKER_SORT_WORST[SIZE_SHAKER],
      SHAKER_SORT_BEST[SIZE_SHAKER];
  for (int i = 0; i < SIZE_SHAKER; i++)
  {
    SHAKER_SORT_WORST[i] = SIZE_SHAKER - i;
    SHAKER_SORT_BEST[i] = i;
  }
  
  const int SIZE_MERGE = 100;
  int MERGE_SORT_WORST[SIZE_MERGE],
      MERGE_SORT_BEST[SIZE_MERGE];
  for (int i = 0; i < SIZE_MERGE; i++)
  {
    if (i % 2 == 0)
      MERGE_SORT_WORST[i / 2] = i;
    else
      MERGE_SORT_WORST[(i / 2) + (SIZE_MERGE / 2)] = i;
    if (i < SIZE_MERGE / 2)
      MERGE_SORT_BEST[(SIZE_MERGE / 2) + i] = i;
    else
      MERGE_SORT_BEST[i - (SIZE_MERGE / 2)] = i;
  }

  const int SIZE_COUNTING = 100;
  int COUNTING_SORT_1[SIZE_COUNTING],
      COUNTING_SORT_2[SIZE_COUNTING];
  for (int i = 0; i < SIZE_COUNTING; i++)
  {
    COUNTING_SORT_1[i] = SIZE_COUNTING - i;
    COUNTING_SORT_2[i] = i;
  }

  int* res;

  unsigned int timeBegin = 0,
               timeEnd = 0,
               time = 0;
  
  // Shaker sort
  timeBegin = clock();
  res = shakerSort(SHAKER_SORT_WORST, SIZE_SHAKER);
  timeEnd = clock();
  time = timeEnd - timeBegin;
  std::cout << "Shaker sort worst case ; "
            << "Sort ok? : " << checkSort(res, SIZE_SHAKER) << " ; "
            << "Time : " << time << " ms" << "\n";

  delete[] res;
  timeBegin = clock();
  res = shakerSort(SHAKER_SORT_BEST, SIZE_SHAKER);
  timeEnd = clock();
  time = timeEnd - timeBegin;
  std::cout << "Shaker sort best case ; "
            << "Sort ok? : " << checkSort(res, SIZE_SHAKER) << " ; "
            << "Time : " << time << " ms" << "\n";

  int arrShaker[SIZE_SHAKER];
  fillRandom(arrShaker, SIZE_SHAKER);
  delete[] res;
  timeBegin = clock();
  res = shakerSort(arrShaker, SIZE_SHAKER);
  timeEnd = clock();
  time = timeEnd - timeBegin;
  std::cout << "Shaker sort middle case ; "
            << "Sort ok? : " << checkSort(res, SIZE_SHAKER) << " ; "
            << "Time : " << time << " ms" << "\n\n";

  // Merge sort
  delete[] res;
  timeBegin = clock();
  res = mergeSort(MERGE_SORT_WORST, SIZE_MERGE);
  timeEnd = clock();
  time = timeEnd - timeBegin;
  std::cout << "Merge sort worst case ; "
            << "Sort ok? : " << checkSort(res, SIZE_MERGE) << " ; "
            << "Time : " << time << " ms" << "\n";

  delete[] res;
  timeBegin = clock();
  res = mergeSort(MERGE_SORT_BEST, SIZE_MERGE);
  timeEnd = clock();
  time = timeEnd - timeBegin;
  std::cout << "Merge sort best case ; "
            << "Sort ok? : " << checkSort(res, SIZE_MERGE) << " ; "
            << "Time : " << time << " ms" << "\n";
  
  int arrMerge[SIZE_MERGE];
  fillRandom(arrMerge, SIZE_MERGE);
  delete[] res;
  timeBegin = clock();
  res = mergeSort(arrMerge, SIZE_MERGE);
  timeEnd = clock();
  time = timeEnd - timeBegin;
  std::cout << "Merge sort middle case ; "
            << "Sort ok? : " << checkSort(res, SIZE_MERGE) << " ; "
            << "Time : " << time << " ms" << "\n\n";

  // Counting sort
  timeBegin = clock();
  delete[] res;
  res = countingSort(COUNTING_SORT_1, SIZE_COUNTING);
  timeEnd = clock();
  time = timeEnd - timeBegin;
  std::cout << "Counting sort case 1 (1 2 3 ...); "
            << "Sort ok? : " << checkSort(res, SIZE_COUNTING) << " ; "
            << "Time : " << time << " ms" << "\n";

  timeBegin = clock();
  delete[] res;
  res = countingSort(COUNTING_SORT_2, SIZE_COUNTING);
  timeEnd = clock();
  time = timeEnd - timeBegin;
  std::cout << "Counting sort case 2 (3 2 1 ...); "
    << "Sort ok? : " << checkSort(res, SIZE_COUNTING) << " ; "
    << "Time : " << time << " ms" << "\n";

  int arrCounting[SIZE_COUNTING];
  fillRandom(arrCounting, SIZE_COUNTING);
  delete[] res;
  timeBegin = clock();
  res = countingSort(arrCounting, SIZE_COUNTING);
  timeEnd = clock();
  time = timeEnd - timeBegin;
  std::cout << "Counting sort middle case ; "
            << "Sort ok? : " << checkSort(res, SIZE_COUNTING) << " ; "
            << "Time : " << time << " ms" << "\n\n";

  delete[] res;

  return 0;
}

void printArray(const int* arr, int size)
{
  for (int i = 0; i < size; i++)
    std::cout << arr[i] << " ";
  std::cout << "\n";
}

int* shakerSort(const int* arr, int size)
{
  int* ret = new int[size];
  for (int i = 0; i < size; i++)
  {
    ret[i] = arr[i];
  }
  int left = 0,
      right = size - 1;
  while (left < right)
  {
    for (int i = left; i < right; i++)
    {
      if (ret[i] > ret[i + 1])
      {
        std::swap(ret[i], ret[i + 1]);
      }
    }
    right--;
    for (int i = right; i > left; i--)
    {
      if (ret[i] < ret[i - 1])
      {
        std::swap(ret[i], ret[i - 1]);
      }
    }
    left++;
  }
  return ret;
}

int* countingSort(const int* arr, int size)
{
  int k = arr[0];
  for (int i = 1; i < size; i++)
  {
    k = std::max(k, arr[i]);
  }
  k++;
  int* ret = new int[size];
  for (int i = 0; i < size; i++)
  {
    ret[i] = 0;
  }
  int* c = new int[k];
  for (int i = 0; i < k; i++)
  {
    c[i] = 0;
  }
  for (int i = 0; i < size; i++)
  {
    c[arr[i]] += 1;
  }
  for (int i = 1; i < k; i++)
  {
    c[i] += c[i - 1];
  }
  for (int i = size - 1; i >= 0; i--)
  {
    ret[c[arr[i]] - 1] = arr[i];
    c[arr[i]]--;
  }
  delete[] c;
  return ret;
}

void merge(int* a, int sizeA, int* b, int sizeB)
{
  int* bufA = new int[sizeA];
  for (int i = 0; i < sizeA; i++)
  {
    bufA[i] = a[i];
  }
  int* bufB = new int[sizeB];
  for (int i = 0; i < sizeB; i++)
  {
    bufB[i] = b[i];
  }
  int i = 0,
      iA = 0,
      iB = 0;
  while (i < sizeA + sizeB)
  {
    if (iA == sizeA)
    {
      a[i] = bufB[iB];
      iB++;
    }
    else if (iB == sizeB)
    {
      a[i] = bufA[iA];
      iA++;
    }
    else if (bufA[iA] <= bufB[iB])
    {
      a[i] = bufA[iA];
      iA++;
    }
    else
    {
      a[i] = bufB[iB];
      iB++;
    }
    i++;
  }
  delete[] bufA;
  delete[] bufB;
}

int* mergeSort(const int* arr, int size)
{
  int* ret = new int[size];
  for (int i = 0; i < size; i++)
  {
    ret[i] = arr[i];
  }
  int k = 1;
  while (k < size)
  {
    for (int i = 0; i < size; i += 2 * k)
    {
      if (i + k < size)
      {
        if (i + k + k < size)
        {
          merge(ret + i, k, ret + i + k, k);
        }
        else
        {
          merge(ret + i, k, ret + i + k, size - i - k);
        }
      }
      else
      {
        merge(ret + i, size - i, ret + i + k, 0);
      }
    }
    k *= 2;
  }
  return ret;
}

bool checkSort(const int* arr, int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {
      return false;
    }
  }
  return true;
}

void fillRandom(int* arr, int size)
{
  srand(time(0));
  for (int i = 0; i < size; i++)
  {
    arr[i] = rand();
  }
}
