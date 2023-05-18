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
		:/*Parent() , */b(10.0) // 부모클래스의 생성자가 먼저 호출 되고 자식클래스가 생성되면서, 자식클래스의 맴버 클래스 생성자가 만들어 지면서 만들어지게 된다.
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
	// D만 호출하더라도, 나머지의 class의 생성자가 전부 생성되어 나타나게 된다.
	return 0;
}