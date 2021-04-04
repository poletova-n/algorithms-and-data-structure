#ifndef STACKUNDERFLOW_H
#define STACKUNDERFLOW_H

#include <exception>
#include <string>

class StackUnderflow : public std::exception
{
public:
	StackUnderflow() : error_("Stack Underflow") {}
	const std::string& what() { return error_; }
private:
	const std::string error_;
};
#endif