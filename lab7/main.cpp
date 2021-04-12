#include <algorithm>
#include <iostream>
#include <vector>
#include <stdlib.h>

void countingSort(std::vector<int>& array);
void countingSort(std::vector<int>& array, int div);
void radixSort(std::vector<int>& array);
void bucketSort(std::vector<float>& arr);
template < typename T >
bool isSorted(std::vector<T>& array);

const int NBUCKETS = 10;

int main()
{
  try {
    int size = 0;
    std::cout << "COUNTING SORT\nEnter size of array: ";
    std::cin >> size;

    std::vector <int> myArray(size);

    std::cout << "Before sorting:";
    for (int i = 0; i < size; i++)
    {
      myArray[i] = rand() % 20;
      std::cout << myArray[i] << " ";
      //std::cin>>myArray[i];
    }
    std::cout << std::endl;
    countingSort(myArray); \
      std::cout << "\nAfter sorting: ";
    for (int i = 0; i < size; i++)
    {
      std::cout << myArray[i] << " ";
    }


    std::cout << "\n\nRADIX SORT\nEnter size of second array: ";
    std::cin >> size;

    std::vector <int> mySecondArray(size);

    std::cout << "Before sorting: ";
    for (int i = 0; i < size; i++)
    {
      mySecondArray[i] = rand() % 1000;
      std::cout << mySecondArray[i] << " ";
      //std::cin>>mySecondArray[i];
    }
    std::cout << std::endl;
    radixSort(mySecondArray);
    std::cout << "\nAfter sorting: ";
    for (int i = 0; i < size; i++)
    {
      std::cout << mySecondArray[i] << " ";
    }


    std::cout << "\n\nBUCKET SORT\nEnter size of third array: ";
    std::cin >> size;

    std::vector <float> myThirdArray(size);

    std::cout << "Before sorting: ";
    for (int i = 0; i < size; i++)
    {
      myThirdArray[i] = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
      std::cout << myThirdArray[i] << " ";
      //std::cin>>myThirdArray[i];
    }
    std::cout << std::endl;
    bucketSort(myThirdArray);

    std::cout << "\nAfter sorting: ";
    for (int i = 0; i < size; i++)
    {
      std::cout << myThirdArray[i] << " ";
    }

    std::cout << "\n\nARE ARRAYS SORTED?\nFirst array (counting sort): " << (isSorted(myArray) ? "YES" : "NO") <<
      "\nSecond array (radix sort): " << (isSorted(mySecondArray) ? "YES" : "NO") <<
      "\nThird array (bucket sort): " << (isSorted(myThirdArray) ? "YES" : "NO");

  }
  catch (...)
  {
    std::cout << " Oops! Something went wrong. Try once again!";
    return -1;
  }
  return 0;
}

void countingSort(std::vector<int>& array)
{
  if (array.size() == 0)
  {
    throw - 1;
  }
  int max = *max_element(array.begin(), array.end());
  int min = *min_element(array.begin(), array.end());
  int range = max - min + 1;
  std::vector<int> sortedArray(array.size());
  std::vector<int> countingArray(range);

  for (int i = 0; i < array.size(); i++)
  {
    countingArray[array[i] - min]++;
  }

  for (int i = 1; i < range; i++)
  {
    countingArray[i] += countingArray[i - 1];
  }

  for (int i = array.size() - 1; i >= 0; i--) 
  {
    sortedArray[countingArray[array[i] - min] - 1] = array[i];
    countingArray[array[i] - min]--;
  }

  for (int i = 0; i < array.size(); i++)
  {
    array[i] = sortedArray[i];
  }
}

void radixSort(std::vector<int>& array)
{
  if (array.size() == 0)
  {
    throw - 1;
  }
  int max = *max_element(array.begin(), array.end());
  for (int div = 1; max/div > 0; div*=10)
  {
    countingSort(array, div);
  }
}

void bucketSort(std::vector<float>& arr) 
{
  if ((arr.size() == 0)|| (arr.size() == 1))
  {
    throw - 1;
  }

  std::vector <float> bucket[NBUCKETS];

  for (int i = 0; i < arr.size(); i++)
  {
    int bindex = NBUCKETS * arr[i];
    bucket[bindex].push_back(arr[i]);
  }
  for (int i = 0; i < NBUCKETS; i++)
  {
    sort(bucket[i].begin(), bucket[i].end());
  }
  int index = 0;
  for (int i = 0; i < NBUCKETS; i++)
  {
    for (int j = 0; j < bucket[i].size(); j++)
    {
      arr[index++]= bucket[i][j];
    }
  }

}

void countingSort(std::vector<int>& array, int div)
{
  std::vector<int> sortedArray(array.size());
  std::vector<int> countingArray(10);

  for (int i = 0; i < array.size(); i++)
  {
    countingArray[ (array[i]/div) % 10 ]++;
  }

  for (int i = 1; i < 10; i++)
  {
    countingArray[i] += countingArray[i - 1];
  }

  for (int i = array.size() - 1; i >= 0; i--)
  {
    sortedArray[countingArray[(array[i]/div)%10] - 1] = array[i];
    countingArray[ (array[i]/div) % 10]--;
  }

  for (int i = 0; i < array.size(); i++)
  {
    array[i] = sortedArray[i];
  }
}

template < typename T >
bool isSorted(std::vector<T>& array)
{
  for (int i = 0; i < array.size(); i++)
  {
    if (array[i] < array[i + 1])
    {
      return 1;
    }
    else
      return 0;
  }
}
