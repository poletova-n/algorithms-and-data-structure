#ifndef STACKUNDERFLOW_H
#define STACKUNDERFLOW_H
#include <exception>
#include <string>
class StackUnderflow : public std::exception
{
public:
	StackUnderflow() : exception_("Stack Underflow") {}
	const std::string& what() { return exception_; }
private:
	const std::string exception_;
};
#endif