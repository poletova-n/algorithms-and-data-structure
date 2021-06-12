#include "algorithms.h"

std::string NeedlemanWunsch(const std::string& firstString, const std::string& secondString)
{
  int rows = firstString.length() + 1;
  int columns = secondString.length() + 1;
  int* matrix = new int[rows * columns]{ 0 };

  int index;
  for (int i = 1; i < rows; ++i)
  {
    for (int j = 1; j < columns; ++j)
    {
      index = i * columns + j;

      if (firstString[i - 1] == secondString[j - 1])
      {
        matrix[index] = matrix[index - columns - 1] + 1;
      }
      else
      {
        matrix[index] = std::max(matrix[index - columns], matrix[index - 1]);
      }
    }
  }

  std::string result = "";
  int xIndex = rows;
  int yIndex = columns;

  while (xIndex > 0 && yIndex > 0)
  {
    if (firstString[xIndex - 1] == secondString[yIndex - 1])
    {
      result += firstString[xIndex - 1];
      xIndex--;
      yIndex--;
    }
    else if (matrix[(xIndex - 1) * columns + yIndex] > matrix[xIndex * columns + yIndex - 1])
    {
      xIndex--;
    }
    else
    {
      yIndex--;
    }
  }

  delete[] matrix;
  return reverseString(result);
}

std::string Hirschberg(const std::string& firstString, const std::string& secondString)
{
  int firstLength = firstString.length();
  int secondLength = secondString.length();

  if (firstLength == 0)
  {
    return std::string();
  }
  else if (firstLength == 1)
  {
    for (int i = 0; i < secondLength; ++i)
    {
      if (firstString[0] == secondString[i])
      {
        return firstString[0] + std::string();
      }
    }

    return std::string();
  }
  else
  {
    int newSize = firstLength / 2;
    std::string firstHalf = firstString.substr(0, newSize);
    std::string secondHalf = firstString.substr(newSize, firstLength);

    int* firstHalfMatrix = getMatrixLastRow(firstHalf, secondString);
    int* secondHalfMatrix = getMatrixLastRow(reverseString(secondHalf), reverseString(secondString));

    int buffer;
    for (unsigned int i = 1; i <= (secondLength + 1) / 2; ++i)
    {
      buffer = secondHalfMatrix[i];
      secondHalfMatrix[i] = secondHalfMatrix[secondLength + 1 - i];
      secondHalfMatrix[secondLength + 1 - i] = buffer;
    }

    int secondDivisionIndex = 0;
    int max = firstHalfMatrix[0] + secondHalfMatrix[1];
    for (unsigned int i = 0; i < secondLength; ++i)
    {
      if (firstHalfMatrix[i] + secondHalfMatrix[i + 1] > max)
      {
        max = firstHalfMatrix[i] + secondHalfMatrix[i + 1];
        secondDivisionIndex = i;
      }
      if (firstHalfMatrix[secondLength] > max)
      {
        secondDivisionIndex = secondLength;
      }
    }

    delete[] firstHalfMatrix;
    delete[] secondHalfMatrix;

    return Hirschberg(firstHalf, secondString.substr(0, secondDivisionIndex)) + Hirschberg(secondHalf, secondString.substr(secondDivisionIndex, secondLength));
  }
}

int* getMatrixLastRow(const std::string& firstString, const std::string& secondString)
{
  int columns = firstString.length() + 1;
  int rows = secondString.length() + 1;

  int* currentRow = new int[rows] {0};
  int* previousRow = new int[rows] {0};

  for (int i = 1; i < columns; ++i)
  {
    for (int j = 0; j < rows; ++j)
    {
      previousRow[j] = currentRow[j];
    }

    for (int k = 1; k < rows; ++k)
    {
      if (secondString[k - 1] == firstString[i - 1])
      {
        currentRow[k] = previousRow[k - 1] + 1;
      }
      else
      {
        currentRow[k] = std::max(currentRow[k - 1], previousRow[k]);
      }
    }
  }

  delete[] previousRow;

  return currentRow;
}

std::string reverseString(const std::string& src)
{
  std::string result;

  for (int i = src.length() - 1; i >= 0; i--)
  {
    result += src[i];
  }

  return result;
}
