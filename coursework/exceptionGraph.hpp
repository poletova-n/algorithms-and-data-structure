#ifndef EXCEPTIONGRAPH_HPP
#define EXCEPTIONGRAPH_HPP

#include <iostream>
#include <exception>

class GraphWrongNode
  : public std::exception
{
  public:
  GraphWrongNode() : reason_("Wrong node")
  {}

  const char *what() const noexcept override
  { return reason_.c_str(); }

  private:
  std::string reason_;
};

class GraphWrongLine
  : public std::exception
{
  public:
  GraphWrongLine() : reason_("Wrong line")
  {}

  const char *what() const noexcept override
  { return reason_.c_str(); }

  private:
  std::string reason_;
};

class GraphCycle
  : public std::exception
{
  public:
  GraphCycle() : reason_("The graph is cyclic")
  {}

  const char *what() const noexcept override
  { return reason_.c_str(); }

  private:
  std::string reason_;
};

class GraphFreeNode
  : public std::exception
{
  public:
  GraphFreeNode() : reason_("There is a free node")
  {}

  const char *what() const noexcept override
  { return reason_.c_str(); }

  private:
  std::string reason_;
};
class GraphEmpty
  : public std::exception
{
  public:
  GraphEmpty() : reason_("Graph is empty")
  {}

  const char *what() const noexcept override
  { return reason_.c_str(); }

  private:
  std::string reason_;
};
class GraphBFCError
  : public std::exception
{
  public:
  GraphBFCError() : reason_("Cannot pass all nodes")
  {}

  const char *what() const noexcept override
  { return reason_.c_str(); }

  private:
  std::string reason_;
};
#endif
