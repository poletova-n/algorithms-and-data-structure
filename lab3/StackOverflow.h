#ifndef STACKOVERFLOW_H
#define STACKOVERFLOW_H
#include <exception>
#include <string>
class StackOverflow : public std::exception
{
public:
	StackOverflow() : exception_("Stack Overflow") {}
	const std::string& what() { return exception_; }
private:
	const std::string exception_;
};
#endif

