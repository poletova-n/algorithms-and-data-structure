#ifndef TESTUNDIRECTEDRAPH_HPP
#define TESTUNDIRECTEDRAPH_HPP

#include "undirectedGraph.hpp"
#include <iostream>

void testCorrectAddNodeAndLineUndirectedGraph()
{
  try
  {
    UndirectedGraph<int> graph;
    graph.addNode(1);
    graph.addNode(3);
    graph.addNode(8);
    graph.addNode(2);
    graph.addNode(4);
    graph.addLine(1, 4);
    graph.addLine(3, 8);
    graph.addLine(2, 4);
    graph.addLine(1, 3);
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

void testAddingAnExistingNodeUndirectedGraph()
{
  try
  {
    UndirectedGraph<int> graph;
    graph.addNode(3);
    graph.addNode(2);
    graph.addNode(3);
    graph.print();
  }
  catch (const GraphWrongNode &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testAddingExistingLineUndirectedGraph()
{
  try
  {
    UndirectedGraph<int> graph;
    graph.addNode(-2);
    graph.addNode(-3);
    graph.addNode(4);
    graph.addNode(5);
    graph.addLine(-2, 5);
    graph.addLine(-3, 4);
    graph.addLine(-2, -3);
    graph.addLine(-3, 4);
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

void testDeleteNodeAndLineUndirectedGraph()
{
  try
  {
    UndirectedGraph<int> graph;
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

void testDeleteNodeEmptyUndirectedGraph()
{
  try
  {
    UndirectedGraph<int> graph;
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

void testDeleteLineEmptyUndirectedGraph()
{
  try
  {
    UndirectedGraph<int> graph;
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

void testIsIncludeNodeAndIsIncludeLineUndirectedGraph()
{
  try
  {
    UndirectedGraph<int> graph;
    graph.addNode(5);
    graph.addNode(10);
    graph.addNode(15);
    graph.addNode(20);
    graph.addNode(25);
    graph.addLine(10, 5);
    graph.addLine(15, 25);
    graph.addLine(25, 5);
    graph.addLine(10, 20);
    graph.print();
    std::cout << ((graph.isIncludeLine(10, 15)) ? "There is a line from 10 to 15" : "No line from 10 to 15") << "\n";
    std::cout << ((graph.isIncludeLine(20, 10)) ? "There is a line from 20 to 10" : "No line from 20 to 10") << "\n";
    std::cout << ((graph.isIncludeNode(25)) ? "There is a node with the value 25" : "No node with value 25") << "\n";
    std::cout << ((graph.isIncludeNode(4)) ? "There is a node with the value 4" : "No node with value 4") << "\n";
    std::cout << ((graph.isIncludeLine(12, -2)) ? "There is a line from 12 to -1" : "No line from 12 to -1") << "\n";
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

void testDFCUndirectedGraph()
{
  try
  {
    UndirectedGraph<int> graph1;
    graph1.addNode(1);
    graph1.addNode(4);
    graph1.addNode(8);
    graph1.addNode(2);
    graph1.addNode(3);
    graph1.addNode(-1);
    graph1.addLine(1, 4);
    graph1.addLine(4, 8);
    graph1.addLine(8, 2);
    graph1.addLine(2, 3);
    graph1.addLine(3, -1);
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
  catch (const GraphEmpty &e)
  {
    std::cout << "\n" << e.what() << "\n";
  }
}

void testDFCFreeNodeUndirectedGraph()
{
  try
  {
    UndirectedGraph<int> graph;
    graph.addNode(3);
    graph.addNode(18);
    graph.addNode(16);
    graph.addNode(14);
    graph.addNode(12);
    graph.addNode(10);
    graph.addLine(3, 10);
    graph.addLine(12, 14);
    graph.addLine(14, 18);
    std::cout << "\n";
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
}

void testDFCEmptyUndirectedGraph()
{
  try
  {
    UndirectedGraph<int> graph;
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
}

#endif
