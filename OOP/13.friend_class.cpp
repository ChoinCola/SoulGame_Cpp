#include <iostream>

using namespace std;
// �ܺο��� �����忡�� �����̺��� ������ �� �ְ� �ϴ°�.
// a�� b���� ������ �����ϸ� b�� a�� �����̺��� ������ �� �ִ�.
// �׷���, a�� b�� ������ �� ����. ������ ������ �ȵǾ��ֱ� ����.

#pragma region friend global function
//class A
//{
//	int value = 1;
//
//	friend void doSomething1(const A& a);
//	// �̷��� �����Լ� ����� ���� �� �ִ�.
//	friend void doSomething2(const A& a)
//	{
//		cout << a.value << endl;
//	}
//};
//
//void doSomething1(const A& a)
//{
//	cout << a.value << endl;
//}
//
//int main()
//{
//	A a;
//	doSomething1(a);
//	doSomething2(a);
//
//	return 0;
//}
//
// //��ǻ� ���� ���� ���������� �����ϴ� �� ���ٴ� Ư�� �Լ��� ������ �� ����Ѵ�

#pragma endregion

#pragma region friend member class
//class A
//{
//public:
//	void attack(B& b);
//private:
//	int a;
//	
//};
//
//class B
//{
//	friend void A::attack(B& b);
//	// �������, A�� B�� �ִ� hp 100�� ����� �� ������.
//	// ���� ���� �Լ��� ���� ����� ���ָ� ������ �� �� �ִ�.
//private:
//	int hp = 100;
//};
//
//void A::attack(B& b)
//{
//	cout << "b�� ä�� : " << b.hp << endl;
//
//	cout << "����!" << endl;
//	b.hp -= 10;
//}
//
//int main()
//{
//	A a;
//	B b;
//	// b.a; // �̷������δ� ������ �ȵȴ�. b���� friend Ű���鸣 �������� �ʾұ� ����
//	
//}
// //���� ���̻���ϴ� ���.
#pragma endregion

#pragma region friend class
class A
{
public:
	void PrintBvalue1(class B& b);
	void PrintBvalue2(class B& b);
};

class B
{
	friend class A;
	// B�� �ִ� ��� �Լ��� A�� ����ϰ� ���� ��.
	// ��� ���� �ϳ��� �� ������ �� �� ����.
	int value1 = 10;
	int value2 = 20;
};

void A::PrintBvalue1(B& b)
{
	cout << b.value1 << endl;
}

void A::PrintBvalue2(B& b)
{
	cout << b.value2 << endl;
}

int main()
{
	A a;
	B b;

	a.PrintBvalue1(b);
	a.PrintBvalue2(b);

	return 0;
}
#pragma endregion

