#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <exception>

class QueueOverflow : public std::exception
{
public:
    QueueOverflow() :reason_("Queue Overflow") {}
    const char* what() const noexcept override { return reason_; }
private:
    const char* reason_;
};

class QueueUnderflow : public std::exception
{
public:
    QueueUnderflow() :reason_("QueueUnderflow") {}
    const char* what() const noexcept override { return reason_; }
private:
    const char* reason_;
};

template <class T>
class Queue
{
public:
    virtual ~Queue() {}
    virtual void enQueue(const T& e) = 0;
    virtual T deQueue() = 0;
    virtual bool isEmpty() const = 0;
};

class WrongQueueSize : public std::exception
{
public:
    WrongQueueSize() :reason_("WrongQueueSize") {}
    const char* what() const noexcept override { return reason_; }
private:
    const char* reason_;
};

template <typename T>
class QueueArray final : public Queue<T>
{
public:
    QueueArray(size_t size);
    QueueArray(const QueueArray<T>& src) = delete;
    QueueArray(QueueArray<T>&& src);

    QueueArray<T>& operator= (const QueueArray<T>& src) = delete;
    QueueArray<T>& operator= (QueueArray<T>&& src);

    virtual ~QueueArray() override { delete[] array_; }
    void enQueue(const T& e) override;
    T deQueue() override;
    void print();
    bool isEmpty() const override { return head_ == tail_; }

private:
    T* array_;
    size_t head_ = 1;
    size_t tail_ = 1;
    size_t size_;
    void swap(QueueArray<T>& right);
};

template <typename T>
QueueArray<T>::QueueArray(size_t size) :
    size_(size),
    head_(1),
    tail_(1)
{
    array_ = new T[size + 1];
}

template <typename T>
void QueueArray<T>::swap(QueueArray<T>& right)
{
    std::swap(*this.head_, right.head_);
    std::swap(*this.tail_, right.tail_);
    std::swap(*this.size_, right.size_);
    std::swap(*this.array_, right.array_);
}

template <typename T>
QueueArray<T>::QueueArray(QueueArray<T>&& src)
{
    head_ = src.head_;
    tail_ = src.tail_;
    size_ = src.size_;
    array_ = std::move(src.array_);
    src.size_ = 0;
    src.head_ = 0;
    src.tail_ = 0;
    src.array_ = nullptr;
}

template <typename T>
QueueArray<T>& QueueArray<T>::operator=(QueueArray<T>&& src)
{
    swap(src);
    src.size_ = 0;
    src.head_ = 0;
    src.tail_ = 0;
    src.array_ = nullptr;
    return *this;
}

template <typename T>
void QueueArray<T>::enQueue(const T& e)
{
    if (head_ == (tail_ + 1)) {
        throw QueueOverflow();
    }
    array_[tail_++] = e;
    tail_ %= size_;
}

template<typename T>
T QueueArray<T>::deQueue()
{
    if (head_ == tail_) {
        throw QueueUnderflow();
    }
    size_t temp = head_;
    head_++;
    head_ %= size_;
    return array_[temp];
}

template<typename T>
void QueueArray<T>::print()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty\n";
    }
    else
    {
        std::cout << "Queue:\n";
        for (size_t i = head_; i < tail_; i++)
        {
            std::cout << array_[i] << " ";
        }
        std::cout << "\n";
    }
}

#endif