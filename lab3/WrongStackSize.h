#ifndef WRONGSTACKSIZE_H
#define WRONGSTACKSIZE_H
#include <exception>
#include <string>
class WrongStackSize : public std::exception
{
public:
	WrongStackSize() : exception_("Wrong Stack size") {}
	const std::string& what() { return exception_; }
private:
	const std::string exception_;
};
#endif
