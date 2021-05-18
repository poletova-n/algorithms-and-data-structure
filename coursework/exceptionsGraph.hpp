#ifndef EXCEPTIONSGRAPH_HPP
#define EXCEPTIONSGRAPH_HPP

#include <exception>

class EmptyGraph : public std::exception
{
public:
  EmptyGraph() : error_("Graph is empty") {};
  const char* getError() const
  {
    return error_;
  }

private:
  const char* error_;
};

class WrongVertexGraph : public std::exception
{
public:
  WrongVertexGraph() : error_("Wrong vertex of graph") {};
  const char* getError() const
  {
    return error_;
  }

private:
  const char* error_;
};

class WrongEdgeGraph : public std::exception
{
public:
  WrongEdgeGraph() : error_("Wrong edge of graph") {};
  const char* getError() const
  {
    return error_;
  }

private:
  const char* error_;
};

class GraphBFSError : public std::exception
{
public:
  GraphBFSError() : error_(" - Wrong BFS passage")
  {}

  const char* getError() const
  {
    return error_;
  }

private:
  const char* error_;
};

#endif
