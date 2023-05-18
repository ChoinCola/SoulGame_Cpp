// 소멸자 관련 이야기

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
	// 페딩바이트가 여러개 있을떄 cpu가 중복접근을 할 수 있기 때문에, 그걸 막기위해 페딩바이트를 추가해주어서 하는것.
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