#include <iostream>

using namespace std;

class Test
{
	int value;
	static int value2;

public:

	Test() {}
	void Temp1() { this->value; }
	void Temp1() const { this->value; }

	static void Temp2() { }//this->value; }
	// ���� �Լ� �̱� ������, ���������� ����� �����ϴ�.
	int test
};

int main()
{
	Test t1;
	t1.Temp1();

	Test::Temp2();

	void (*ptr1)() = Test::Temp2; // �Լ� ������ ó�� ��� ���� �����ϴ�.
	//void (*ptr1)() = Test::Temp1; // �����ڸ� �� �� ���� ������ �ش� ����� �Ұ����ϴ�.

	/*
		��� ������
	*/
	int Test::* ptr2 = &Test::test;
	t1.*ptr2 = 10; // �̷��� �����Ͱ� class ���ο� �����ȴ�.

	void (Test:: * ptr3)() = &Test::Temp1; // �ܼ� �ּҸ� ������ �� �� ���������.
	(t1.*ptr3)();

	return 0;
}