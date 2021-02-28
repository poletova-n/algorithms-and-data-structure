#ifndef STACK_STACK_H
#define STACK_STACK_H
template <class T>
class Stack
{
public:

    virtual ~Stack() = 0;
    virtual void push(const T& e) = 0;
    virtual const T& pop() = 0;
    virtual bool isEmpty() = 0;
};
#endif //STACK_STACK_H
