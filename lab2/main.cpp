#include <iostream>
#include "SinglyLinkedOrderedList.h" 
int main()
{
SinglyLinkedOrderedList<int> a;
a.insert(7); //���������� ����� � �������
a.insert(7);
a.insert(4);
a.insert(4);
a.insert(8);
a.insert(8);
a.insert(2);
a.insert(2);
a.insert(4);
a.insert(4);
a.insert(1);
a.insert(6);
std::cout << "a: " << a; // ����� �������

std::cout << "Searching for 1, 2, 3, 4 in a: ";
std::cout << a.search(1) << a.search(2) << a.search(3) << a.search(4) << '\n'; //����� ������ � �������

SinglyLinkedOrderedList<int> b; 
b.insert(2);
b.insert(1);
b.insert(-8);
b.insert(3);
b.insert(6);
b.insert(-7);
std::cout << "b: " << b;

b.deleteItem(-8); //�������� ������ �� �������
b.deleteItem(1);
b.deleteItem(6);
std::cout << "Deleted -8, 1 and 6 in b: " << b << "a: " << a << "b: " << b;
std::cout << "Intersection of a and b: " << a.intersect(b); //�������� ����� ���������
std::cout << "Difference between a and b: " << a.subtract(b); //�������� ����� ������ � ������ �������
std::cout << "Difference between b and a: " << b.subtract(a); //�������� ����� ������ � ������ �������
std::cout << "Union of a and b: " << a.unite(b) << "After union b is empty: " << b; //����������� ��������
std::cout << "Intersection of a and b: " << a.intersect(b);
}
