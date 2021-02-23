#include"my_exception.h"

std::string StackOverflow::what()
{
	return reason_;
}
std::string StackUnderflow::what()
{
	return reason_;
}
std::string WrongStackSize::what()
{
	return reason_;
}