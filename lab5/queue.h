#ifndef QUEUUE_H
#define QUEUUE_H

template<class T>
class Queue
{
public:
	virtual ~Queue() {}
	virtual void enQueue(const T&) = 0;
	virtual T deQueue() = 0;
	virtual bool isEmpty() = 0;
};

#endif
