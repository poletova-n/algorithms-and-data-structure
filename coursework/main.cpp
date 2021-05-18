#include <vector>
#include "test-undirectedGraph.hpp"

void dijkstra(); //find the shortest paths from given vertex to other vertexes
//diameter is the highest count of vertices from all count of shortest paths between every vertexes

int main()
{
  testUndirectedGraph();
  dijkstra();
  return 0;
}

void dijkstra()
{
  for (int i = 0; i < 30; i++)
  {
    std::cout << "-";
  }
  std::cout << "\nTEST: SHORTEST DIST\n";
  int size, index;
  std::cout << "Enter count of vertexes and index of vertex which will be start point:  ";
  std::cin >> size >> index;
  std::vector<std::vector<int> > a(size, std::vector<int>(size, 0));
  //std::vector<int> a(size)(size); //contacts
  std::vector<int> d(size); //min dist
  std::vector<int> v(size); //used vertexes
  int temp, minIndex, min;
  int beginIndex = index;
  //initialize contacts
  for (int i = 0; i < size; i++)
  {
    a[i][i] = 0;
    for (int j = i + 1; j < size; j++)
    {
      std::cout << "Enter dist between vertexes: " << i + 1 << " - " << j + 1 << ": ";
      std::cin >> temp;
      a[i][j] = temp;
      a[j][i] = temp;
    }
  }
  //initialize vertexes
  for (int i = 0; i < size; i++)
  {
    d[i] = 10000;
    v[i] = 1;
  }
  d[beginIndex] = 0;

  do {
    minIndex = 10000;
    min = 10000;
    for (int i = 0; i < size; i++)
    { //if vertexes isn't used and weight < min
      if ((v[i] == 1) && (d[i] < min))
      { //rewrite to new
        min = d[i];
        minIndex = i;
      }
    }
    //Plus finding min weight to current weight, then compare with current min weight
    if (minIndex != 10000)
    {
      for (int i = 0; i < size; i++)
      {
        if (a[minIndex][i] > 0)
        {
          temp = min + a[minIndex][i];
          if (temp < d[i])
          {
            d[i] = temp;
          }
        }
      }
      v[minIndex] = 0;
    }
  } while (minIndex < 10000);

  int diameter = -1;
  std::cout << "Shortest dists to other vertexes (index-weight): \n";
  for (int i = 0; i < size; i++) {
    std::cout << i + 1 << " - " << d[i] << "   ";
    if (d[i] > diameter) {
      diameter = d[i];
    }
  }
  std::cout << "\nDiameter of this graph: " << diameter << std::endl;
}
