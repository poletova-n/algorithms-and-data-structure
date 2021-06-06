#ifndef MAIN_CPP_QUEUE_HPP
#define MAIN_CPP_QUEUE_HPP

template <class T>
class Queue
{
public:
    virtual ~Queue () = default;
    virtual void insertQueue(const T& e) = 0;
    virtual int deQueue () = 0;
    virtual bool isEmpty() = 0;
};

#endif
