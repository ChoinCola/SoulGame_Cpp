#include <iostream>

using namespace std;
/*
	dynamic cast
	- ������ �ٿ�ĳ���� �� ���

*/

class Base
{
public:
	int i = 0;
	virtual void Print() { cout << "Base" << endl; }

};

class Derived1 : public Base
{
public:
	int j = 1;
	virtual void Print() override { cout << "Derived1" << endl; }
};

class Derived2 : public Base
{
public:
	int k = 2;
	virtual void Print() override { cout << "Derived2" << endl; }
};

void DoSomething(Base* b)
{
	//Derived2* baseToD2 = static_cast<Derived2*>(b);
	//baseToD2->k = 888;
	// ���Ͱ��� ������� �����ϸ� j �� 888�� ��������.
	Derived2* baseToD2 = dynamic_cast<Derived2*>(b);
	baseToD2->k = 888;
	// ��Ÿ�� ��Ȳ���� ����ش�.
}

int main()
{
	Derived1 d1;
	Base* base = &d1;

	Derived1* baseToD1 = static_cast<Derived1*>(base);
	baseToD1->Print();

	DoSomething(&d1);
	// j�� ������ �ִ� d1�� d2�� �ٲپ k���� �ٲپ���.

	cout << d1.j << endl;
	// �������� ����ȯ�� �Ͼ�� ������, ������ �ʴ� ������ ��ȯ�� �̷���� �� �ִ�.

	// ���̳��� �ɽ����� ��Ÿ�� �� ������ ����ش�. �׷��� ���� ���� �� �ִ�.

	return 0;
}