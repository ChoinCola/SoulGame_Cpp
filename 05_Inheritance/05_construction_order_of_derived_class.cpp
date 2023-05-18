#include <iostream>

using namespace std;

class Parent
{
	int a;
public:
	Parent()
		:a(10)
	{
		cout << "Base Constructor" << endl;
	}
};

class Child : public Parent
{
	double b;

public:
	Child()
		:/*Parent() , */b(10.0) // �θ�Ŭ������ �����ڰ� ���� ȣ�� �ǰ� �ڽ�Ŭ������ �����Ǹ鼭, �ڽ�Ŭ������ �ɹ� Ŭ���� �����ڰ� ����� ���鼭 ��������� �ȴ�.
	{
		cout << "Derved Constructor" << endl;
	}
};

class A				{ public: A() { cout << "A constructor" << endl; } };
class B : public A	{ public: B() { cout << "B constructor" << endl; } };
class C : public B	{ public: C() { cout << "C constructor" << endl; } };
class D : public C	{ public: D() { cout << "D constructor" << endl; } };

int main()
{
	Child child;


	D d;
	// D�� ȣ���ϴ���, �������� class�� �����ڰ� ���� �����Ǿ� ��Ÿ���� �ȴ�.
	return 0;
}