#include <iostream>

using namespace std;

class A //final
	// final = Ŭ������ ��ӽ�ų �� ���� �����ϴ� Ű���� �̴�. �̰� ���̸� 
	// ���� ���̻� �� �Լ��� ������� �ʰڴ�. ��� �ǹ��̴�.
{
public:
	virtual void Print(int x) { cout << "A" << endl; }
	// virtual = �����Լ� ��� �ǹ̷�, ����Ŭ�������� �� �Լ��� ������ ���� �� ������ ������ִ� ��.

	int i = 0;
};

class B /*final*/ : public A
	// B���� ���̸�, B�� ���Ŀ� ��ӽ�Ű�� �ʰڴ�. ��� �ǹ�.
{
public:
	void Print(int x) override /*final*/ { cout << "B" << endl; }
	// override �� �� �Լ��� �θ��� �Լ��� �������� ��Ȱ �̶�� �� �� ������ִ°�.

	// �̶� ���ڰ� �� ��ȯ���� ������ ���ƾ� �Ѵ�.
	// �Լ��� final�� ���̸�, �Լ� �����ؼ� ����� ��Ű�� ���� �� �ִ�.
};

class C : public B
{
public:
	void Print(int x) override { cout << "C" << endl; }
};

int main()
{
	A a;
	B b;
	C c;

	a.Print(1);
	b.Print(2);
	c.Print(3);

	A* aptr = new B();
	// B* bptr = aptr;

	B* bb = new B();
	A* aa = bb; // A�����Ͱ� B�� ����ų�� A���� ��µǰ� B�� ��µ��� �ʴ´�.
	// �̴� �������̵� ������ ȣ���� �������� �������� �����̴�.

	return 0;
}