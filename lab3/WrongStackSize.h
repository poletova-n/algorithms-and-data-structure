#ifndef WRONGSTACKSIZE_H
#define WRONGSTACKSIZE_H

#include <exception>
#include <string>

class WrongStackSize : public std::exception
{
public:
	WrongStackSize() : error_("Wrong Stack size") {}
	const std::string& what() { return error_; }
private:
	const std::string error_;
};
#endif