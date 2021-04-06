#include <iostream>
#include <iomanip>

#include "testDirectedGraph.hpp"
#include "testUndirectedraph.hpp"

int main()
{
  std::cout << std::setw(46) << "TESTING A DIRECTED GRAPH\n\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(48) << "Testing correct add node and line\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testCorrectAddNodeAndLineDirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing adding an existing node\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  testAddingAnExistingNodeDirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing adding an existing line\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  testAddingAnExistingLineDirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }

  std::cout << "\n" << std::setw(55) << "Testing adding line in the opposite direction\n";

  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  testAddingLineInTheOppositeDirectionDirectedGraph();

  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing is Include node and line\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testIsIncludeNodeAndIsIncludeLineDirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(38) << "Testing BFC\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testBFCDirectedGraph();
  std::cout << "\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing BFC (cyclic graph)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testBFCCyclicDirectedGraph();
  std::cout << "\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(44) << "Testing BFC (graph is empty)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }

  testBFCEmptyDirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(50) << "Testing BFC (graph with free node)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testBFCFreeNodeDirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(40) << "Testing BFC (error BFC)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testBFCErrorDirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(40) << "Testing topological sort\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testTopologicalSort();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(48) << "Testing topological sort (cyclic graph)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testTopologicalSortCyclic();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(52) << "Testing topological sort (graph with free node)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testTopologicalSortFreeNode();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(52) << "Testing topological sort (graph is empty)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  testTopologicalSortEmptyGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing delete node and line\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testDeleteNodeAndLineDirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing delete node (graph is empty)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  testDeleteNodeEmptyDirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing delete line (graph is empty)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  testDeleteLineEmptyDirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n\n" << std::setw(47) << "TESTING A UNDIRECTED GRAPH\n\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(48) << "Testing correct add node and line\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testCorrectAddNodeAndLineUndirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing adding an existing node\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  testAddingAnExistingNodeUndirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing adding an existing line\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  testAddingExistingLineUndirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing delete node and line\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testDeleteNodeAndLineUndirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing delete node (graph is empty)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  testDeleteNodeEmptyUndirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing delete line (graph is empty)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  testDeleteLineEmptyUndirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(46) << "Testing is Include node and line\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testIsIncludeNodeAndIsIncludeLineUndirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(38) << "Testing BFC\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n";
  testBFCUndirectedGraph();
  std::cout << "\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(48) << "Testing BFC (graph with free node)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  testBFCFreeNodeUndirectedGraph();
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  std::cout << "\n" << std::setw(44) << "Testing BFC (graph is empty)\n";
  for (int i = 0; i < 60; i++)
  {
    std::cout << "-";
  }
  testBFCEmptyUndirectedGraph();

  return 0;
}
