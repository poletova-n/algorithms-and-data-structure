#ifndef QUICKSORT_H
#define QUICKSORT_H

#include <vector>

void swap(int* a, int* b)
{
  int t = *a;
  *a = *b;
  *b = t;
}

int partition(std::vector<int>& vect, int l, int h)
{
  int x = vect[h];
  int i = (l - 1);

  for (int j = l; j <= h - 1; j++)
  {
    if (vect[j] <= x)
    {
      i++;
      swap(&vect[i], &vect[j]);
    }
  }
  swap(&vect[i + 1], &vect[h]);
  return (i + 1);
}

void quickSort(std::vector<int>& vect, int l, int h)
{
  std::vector<int> stack(h - l + 1);

  int top = -1;

  stack[++top] = l;
  stack[++top] = h;

  while (top >= 0)
  {
    h = stack[top--];
    l = stack[top--];

    int p = partition(vect, l, h);

    if (p - 1 > l)
    {
      stack[++top] = l;
      stack[++top] = p - 1;
    }

    if (p + 1 < h)
    {
      stack[++top] = p + 1;
      stack[++top] = h;
    }
  }
}

#endif
