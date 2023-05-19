#include <iostream>

using namespace std;
// �ڱ��ڽ��� ����Ű�� �����͸� ����� �� �� ����� �������� ����� �ƴ϶� ������ �������� ��µȴ�.

class A
{
public:
	virtual A* GetThisPointer() { cout << "A" << endl; return this; }
	void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	B* GetThisPointer() override { cout << "B" << endl; return this; }
	void print() { cout << "B" << endl; }
};

int main()
{
	B b;

	b.print();
	cout << "Address : " << b.GetThisPointer() << endl;
	cout << "typeid : " << typeid(b.GetThisPointer()).name() << endl;

	A& ref = b;
	ref.print(); // A�� �����Ǿ, override�� ���� �ʾұ� ������, A�� ��µȴ�.
	cout << "Adress : " << ref.GetThisPointer() << endl; // B�� ����ϱ� ������ B�� ��µǴ°� �� �´�.
	cout << "typeid : " << typeid(ref.GetThisPointer()).name() << endl; // Ÿ�� ��ü�� A�̱� ������ A�� Ÿ���� ��ȯ�Ǵ°� �̴�.

	return 0;
}