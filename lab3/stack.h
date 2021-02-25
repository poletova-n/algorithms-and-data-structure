#ifndef STACK_
#define STACK_

template <class T>
class Stack
{
public:
  virtual ~Stack() {} 
  virtual void push(const T& e) = 0; // ���������� �������� � ����
  virtual T pop() = 0; // �������� � ����������� �������� ��������. // ���� ��������� ���, ����� ���������� StackUnderflow
  virtual bool isEmpty() = 0; // �������� ����� �� �������
  virtual const T& top() = 0; // ����������� �������� �������� (��� ��� �������� �� �����)
};

#endif
