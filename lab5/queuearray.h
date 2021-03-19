#ifndef QUEUEARRAY_H
#define QUEUEARRAY_H

#include "exceptionQ.h"

template <class T>
class Queue
{
public:
	virtual ~Queue() {}
	// ����������� �������� �� ������
	virtual void enQueue(const T& e) = 0; // ���������� �������� � ���� 
	virtual T deQueue() = 0;// �������� � ����������� �������� ��������. 
						 // ���� ��������� ���, ����� ���������� QueueUnderflow 
	virtual bool isEmpty() const = 0; // �������� �� ������� 

};

template <typename T>
class QueueArray final : public Queue<T> // ����������� final ��������� ������������ �� ������
{
public:
	QueueArray(size_t size);   // size ������ ������ "�� ���������"
	QueueArray(const QueueArray<T>& src) = delete;
	QueueArray(QueueArray<T>&& src);  // 

	QueueArray<T>& operator= (QueueArray<T>&& src); // �������� ������������� ������������

	virtual ~QueueArray() override { delete[] array_; }

	void enQueue(const T& e) override;
	T deQueue() override;
	bool isEmpty() const override { return head_ == tail_; }

private:
	T* array_;         // ������ ��������� �������
	size_t head_ = 1;  // ������� �����, ����  head[Q] = tail[Q]. 
	size_t tail_ = 1;  // �������������: head[Q] = tail[Q] = 1;
	size_t size_;      // ������ ������� 
	void swap(QueueArray<T>& right);
};

template <typename T>
QueueArray<T>::QueueArray(size_t size) :
	size_(size+1), head_(1), tail_(1)
{
	try {
		array_ = new T[size + 1];// �������� �������� ������ ��� �������� �������...
	}
	catch (...) {        // ���� ���-�� ��������� (��������, ������ ������� �������
		throw WrongQueueSize();  // ��� ...) - ��������� ����.�������� bad_alloc
	}

}

template <typename T>
void QueueArray<T>::swap(QueueArray<T>& right)
{
	std::swap(*this.array_, right.array_);
	std::swap(*this.head_, right.head_);
	std::swap(*this.tail_, right.tail_);
	std::swap(*this.size_, right.size_);

}

template <typename T>
QueueArray<T>::QueueArray(QueueArray<T>&& src)
{
	this->array_ = std::move(src.array_);
	this->head_ = src.head_;
	this->tail_ = src.tail_;
	this->size_ = src.size;
	src.array_ = nullptr;
	src.head_ = 1;
	src.tail_ = 1;
	src.size_ = 0;
}

template <typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& src)
{
	this->swap(src);
	src.array_ = nullptr;
	src.head_ = 1;
	src.tail_ = 1;
	src.size_ = 0;
	return *this;
}

template <typename T>
void QueueArray<T>::enQueue(const T& e)
{
	if (head_ == tail_ + 1)
		throw QueueOverflow(); // ��� ����� ��� ������ ��������
	array_[tail_++] = e;
	tail_ %= size_;
}

template <typename T>
T QueueArray<T>::deQueue()
{
	if (head_ == tail_)
		throw QueueUnderflow(); // ������� �����
	size_t temp = head_++;
	head_ = head_ % size_;
	return array_[temp];
}

#endif