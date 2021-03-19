#ifndef CPP_PROJECTS_STACK_HPP
#define CPP_PROJECTS_STACK_HPP

template<class T>
class Stack
{
public:
    virtual ~Stack() = default;

    virtual void push( const T & ) = 0;

    virtual const T &pop() = 0;

    virtual bool isEmpty() = 0;

    virtual T &top() const = 0;
};

#endif
