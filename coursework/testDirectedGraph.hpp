#ifndef TESTDIRECTEDGRAPH_HPP
#define TESTDIRECTEDGRAPH_HPP

#include "directedGraph.hpp"
#include <iostream>

void testCorrectAddNodeAndLineDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(7);
    graph.addNode(6);
    graph.addNode(-8);
    graph.addLine(1, 7);
    graph.addLine(2, 7);
    graph.addLine(-8, 1);
    graph.addLine(2, 6);
    graph.addLine(7, -8);
    graph.print();
  }
  catch (const GraphWrongLine &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testAddingAnExistingNodeDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(7);
    graph.addNode(6);
    graph.addNode(2);
    graph.print();
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testAddingAnExistingLineDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(7);
    graph.addNode(6);
    graph.addNode(-8);
    graph.addLine(1, 7);
    graph.addLine(2, 7);
    graph.addLine(-8, 1);
    graph.addLine(2, 6);
    graph.addLine(1, 7);
    graph.print();
  }
  catch (const GraphWrongLine &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testAddingLineInTheOppositeDirectionDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph;
    graph.addNode(1);
    graph.addNode(2);
    graph.addNode(7);
    graph.addNode(6);
    graph.addNode(-8);
    graph.addLine(1, 7);
    graph.addLine(2, 7);
    graph.addLine(-8, 1);
    graph.addLine(2, 6);
    graph.addLine(7, 1);
    graph.print();
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphWrongLine &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testIsIncludeNodeAndIsIncludeLineDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph;
    std::cout << ((graph.isIncludeLine(12, 1)) ? "There is a line from 10 to 12" : "No line from 10 to 12") << "\n";
    std::cout << ((graph.isIncludeNode(1)) ? "There is a node with the value 1" : "No node with value 1") << "\n";
    graph.addNode(10);
    graph.addNode(12);
    graph.addNode(1);
    graph.addNode(13);
    graph.addNode(6);
    graph.addLine(10, 12);
    graph.addLine(12, 1);
    graph.addLine(12, 13);
    graph.addLine(13, 10);
    graph.addLine(6, 1);
    graph.print();
    std::cout << ((graph.isIncludeLine(12, 1)) ? "There is a line from 10 to 12" : "No line from 10 to 12") << "\n";
    std::cout << ((graph.isIncludeLine(6, 10)) ? "There is a line from 6 to 10" : "No line from 6 to 10") << "\n";
    std::cout << ((graph.isIncludeNode(1)) ? "There is a node with the value 1" : "No node with value 1") << "\n";
    std::cout << ((graph.isIncludeNode(4)) ? "There is a node with the value 4" : "No node with value 4") << "\n";
  }
  catch (const GraphWrongLine &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testDFCDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph1;
    graph1.addNode(1);
    graph1.addNode(4);
    graph1.addNode(3);
    graph1.addNode(9);
    graph1.addNode(2);
    graph1.addNode(8);
    graph1.addLine(1, 4);
    graph1.addLine(1, 3);
    graph1.addLine(4, 2);
    graph1.addLine(2, 8);
    graph1.addLine(3, 9);
    graph1.addLine(2, 8);
    graph1.print();
    graph1.DFC();
  }
  catch (const GraphWrongLine &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphFreeNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphFreeNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphEmpty &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphDFCError &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testDFCCyclicDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph1;
    graph1.addNode(10);
    graph1.addNode(12);
    graph1.addNode(1);
    graph1.addNode(13);
    graph1.addNode(6);
    graph1.addLine(10, 12);
    graph1.addLine(12, 1);
    graph1.addLine(12, 13);
    graph1.addLine(13, 10);
    graph1.addLine(1, 6);
    graph1.addLine(1, 10);
    graph1.print();
    graph1.DFC();
    std::cout << "\n";
    DirectedGraph<int> graph2;
    graph2.addNode(10);
    graph2.addNode(12);
    graph2.addNode(1);
    graph2.addNode(13);
    graph2.addNode(6);
    graph2.addLine(10, 12);
    graph2.addLine(12, 1);
    graph2.addLine(1, 13);
    graph2.addLine(13, 6);
    graph2.addLine(6, 10);
    graph2.print();
    graph2.DFC();
  }
  catch (const GraphWrongLine &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphFreeNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphEmpty &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphDFCError &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testDFCFreeNodeDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph;
    graph.addNode(3);
    graph.addNode(18);
    graph.addNode(16);
    graph.addNode(14);
    graph.addNode(12);
    graph.addNode(10);
    graph.addLine(3, 10);
    graph.addLine(12, 14);
    graph.addLine(14, 18);
    graph.print();
    graph.DFC();
  }

  catch (const GraphWrongLine &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphFreeNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphEmpty &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphDFCError &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testDFCEmptyDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph;
    graph.DFC();
  }
  catch (const GraphFreeNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphEmpty &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphDFCError &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}
void testDFCErrorDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph;
    graph.addNode(2);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addNode(1);
    graph.addLine(1, 2);
    graph.addLine(2, 4);
    graph.addLine(1, 4);
    graph.addLine(3, 2);
    graph.addLine(3, 4);
    graph.addLine(3, 5);
    graph.addLine(4, 5);
    graph.print();
    graph.DFC();
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphFreeNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphEmpty &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphDFCError &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}
void testTopologicalSort()
{
  try
  {
    DirectedGraph<int> graph;
    graph.addNode(1);
    graph.addNode(3);
    graph.addNode(4);
    graph.addNode(10);
    graph.addNode(8);
    graph.addNode(5);
    graph.addNode(6);
    graph.addLine(1, 4);
    graph.addLine(1, 3);
    graph.addLine(3, 10);
    graph.addLine(4, 8);
    graph.addLine(4, 10);
    graph.addLine(4, 5);
    graph.addLine(5, 10);
    graph.addLine(10, 6);
    graph.print();
    graph.topologicalSort();
    std::cout << "\n";
    graph.print();
  }

  catch (const GraphWrongLine &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphFreeNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphCycle &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphEmpty &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testTopologicalSortCyclic()
{
  try
  {
    DirectedGraph<int> graph;
    graph.addNode(10);
    graph.addNode(12);
    graph.addNode(1);
    graph.addNode(13);
    graph.addNode(6);
    graph.addLine(10, 12);
    graph.addLine(12, 1);
    graph.addLine(12, 13);
    graph.addLine(13, 10);
    graph.addLine(6, 1);
    graph.addLine(1, 10);
    graph.print();
    graph.topologicalSort();
    std::cout << "\n";
    graph.print();
  }
  catch (const GraphWrongLine &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphFreeNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphCycle &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphEmpty &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testTopologicalSortFreeNode()
{
  try
  {
    DirectedGraph<int> graph;
    graph.addNode(3);
    graph.addNode(18);
    graph.addNode(16);
    graph.addNode(14);
    graph.addNode(12);
    graph.addNode(10);
    graph.addLine(3, 10);
    graph.addLine(12, 14);
    graph.addLine(14, 18);
    graph.print();
    graph.topologicalSort();
    graph.print();
  }

  catch (const GraphWrongLine &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphFreeNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphCycle &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphEmpty &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testTopologicalSortEmptyGraph()
{
  try
  {
    DirectedGraph<int> graph;
    graph.topologicalSort();
  }
  catch (const GraphFreeNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphCycle &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphEmpty &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testDeleteNodeAndLineDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph;
    graph.addNode(3);
    graph.addNode(18);
    graph.addNode(16);
    graph.addNode(14);
    graph.addNode(12);
    graph.addNode(10);
    graph.addLine(3, 10);
    graph.addLine(12, 14);
    graph.addLine(14, 18);
    graph.addLine(18, 3);
    graph.addLine(14, 16);
    graph.print();
    std::cout << "\ndelete 12\n";
    graph.deleteNode(12);
    graph.print();
    std::cout << "\ndelete 3\n";
    graph.deleteNode(3);
    graph.print();
    std::cout << "\ndelete line 14->18\n";
    graph.deleteLine(14, 18);
    graph.print();
  }
  catch (const GraphWrongLine &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testDeleteNodeEmptyDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph;
    graph.deleteNode(1);
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphEmpty &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testDeleteLineEmptyDirectedGraph()
{
  try
  {
    DirectedGraph<int> graph;
    graph.deleteLine(1, 2);
  }
  catch (const GraphWrongLine &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
  catch (const GraphEmpty &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

#endif
