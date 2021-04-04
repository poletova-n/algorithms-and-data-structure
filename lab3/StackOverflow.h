#ifndef STACKOVERFLOW_H
#define STACKOVERFLOW_H

#include <exception>
#include <string>

class StackOverflow : public std::exception
{
public:
	StackOverflow() : error_("Stack Overflow") {}
	const std::string& what() { return error_; }
private:
	const std::string error_;
};
#endif
