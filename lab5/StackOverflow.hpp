#ifndef STACKOVERFLOW_HPP
#define STACKOVERFLOW_HPP

#include <exception> 

class StackOverflow : public std::exception
{
public:
    StackOverflow() : error_("Stack Overflow") {};
    const char* getError() const
    {
        return error_;
    }

private:
    const char* error_;
};
#endif