#ifndef LAB6_QUEUEEXCEPTION_HPP
#define LAB6_QUEUEEXCEPTION_HPP

#include <exception>

class QueueOverflow : public std::exception
{
public:
    QueueOverflow():
            reason("Queue Overflow")
    {}
    const char* what() const noexcept override{ return reason; }

private:
    const char* reason;
};

class QueueUnderflow : public std::exception
{
public:
    QueueUnderflow() :
            reason("Queue Underflow")
    {}
    const char *what() const noexcept override{ return reason; }

private:
    const char *reason;
};

class WrongQueueSize : public std::exception
{
public:
    WrongQueueSize():
            reason("Wrong Queue Size")
    {}
    const char* what() const noexcept override{ return reason; }

private:
    const char* reason;
};

#endif
