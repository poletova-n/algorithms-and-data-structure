#pragma once
#include <iostream>
class List
{
public:
    int value_;
    List* next_;
    List* head_;
    List(int value);
    List();
    List(List* src);
    List(List&& src);
    ~List();
    void insert(int value);
    friend std::ostream& operator<<(std::ostream& out, List& src);
    friend std::ostream& operator+=(int item, List& src);
    bool operator==(List& src);
    friend List operator| (List& src1, List& src2);
    friend List operator& (List& src1, List& src2);
    void merge(List& src);
};