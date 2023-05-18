// �Ҹ��� ���� �̾߱�

#include <iostream>

using namespace std;

class A
{
	int a;
	// 4byte
public:
	A() { cout << "A constructor" << endl; }
	~A() { cout << "A destructor" << endl; }
};

class B : public A
{
	double b;
	// 16byte
public:

	B() { cout << "B constructor" << endl; }
	~B() { cout << "B destructor" << endl; }
};

int main()
{
	B b;
	cout << sizeof(A) << endl;
	cout << sizeof(B) << endl;
	// �������Ʈ�� ������ ������ cpu�� �ߺ������� �� �� �ֱ� ������, �װ� �������� �������Ʈ�� �߰����־ �ϴ°�.
	return 0;
}

struct S
{
	char c1; // 1 byte
	char c2;
	char c3;
	short s1; // 2 byte
	short s2; // 7
	int i1; // 4 byte
	int i2; // 8
	double d1; // 8
	double d2; // 8
};