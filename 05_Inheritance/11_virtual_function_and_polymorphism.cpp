#include <iostream>
// �����Լ� ���� �������Ͽ� ����ϴ� ����.
using namespace std;

class A
{
public:
	void Print() { cout << "A" << endl; }
	virtual void Print1()		{ cout << "A1" << endl; }
	virtual void Print2()		{ cout << "A2" << endl; }
	virtual void Print3()		{ cout << "A3" << endl; }
	virtual void Print4() final { cout << "A4" << endl; }
};

class B : public A
{
public:
	void Print() { cout << "B" << endl; }
	virtual void Print1()		{ cout << "B1" << endl; }
	virtual void Print2()		{ cout << "B2" << endl; }
	virtual void Print3() final { cout << "B3" << endl; }
//	virtual void Print4() final { cout << "A4" << endl; }
};

class C : public B
{
public:
	void Print() { cout << "C" << endl; }
	virtual void Print1()		{ cout << "C1" << endl; }
	virtual void Print2() final { cout << "C2" << endl; }
//	virtual void Print3() final { cout << "C3" << endl; }
//	virtual void Print4() final { cout << "C4" << endl; }
};

class D : public C
{
public:
	void Print() { cout << "D" << endl; }
	virtual void Print1() final	{ cout << "D1" << endl; }
//	virtual void Print2() final { cout << "D2" << endl; }
//	virtual void Print3() final { cout << "D3" << endl; }
//	virtual void Print4() final { cout << "D4" << endl; }
};
int main()
{
	A a;
	a.Print1();

	B b;
	b.Print1();

	C c;
	c.Print1();

	D d;
	d.Print1();

	cout << endl;

	A& refB = b;
	A& refC = c;
	A& refD = d;

	cout << "######### A" << endl;
	a.Print();
	a.Print1();
	a.Print2();
	a.Print3();
	a.Print4();

	cout << "######### refB" << endl;
	refB.Print();
	refB.Print1();
	refB.Print2();
	refB.Print3();
	refB.Print4();

	cout << "######### refC" << endl;
	refC.Print();
	refC.Print1();
	refC.Print2();
	refC.Print3();
	refC.Print4();

	cout << "######### refD" << endl;
	refD.Print();
	refD.Print1();
	refD.Print2();
	refD.Print3();
	refD.Print4();

	D d1;
	D d2;
	// d1 �� d2�� �ּҴ� ����.
	// �����Լ� ���̺��� �Լ� ������ �迭�̶�� �����ϸ� �ȴ�. �����Լ��� �迭�� ������ �����ϰ� �ȴ�.
	// �����Լ� ���̺��� �����ּҿʹ� �ٸ��ٰ� �����ϸ� �ȴ�.
	// ���Լ��� ������� ��������鼭 �����̵ȴ�.

	return 0;
}

/*
	vehicle �̶�� class�� �����, ������̵�, �ڵ����̵� �� �������� ��ü�� ������ �� ��ü�� 5������ ���� �� ������, �̵���ü ���� 5�� �ʰ��˴ϴ�. ��� ��Ÿ����
	���� ���� �ȵǰ� ������.
	virtual void movement() {} �� ����ϰ� ���鶧.

*/