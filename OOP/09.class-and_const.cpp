#include <iostream>

using namespace std;

class Data
{
	int value1;
	mutable int value2; // ����ġ ���� �� ����ϴ� �����̶�� �����ϸ� �ȴ�. ���ȭ �� class���� �����ؾ� �� ��찡 ����� ����Ѵ�.

public:
	Data() : value1(0) {}

	int& Getvalue() { cout << "not const" << endl; return value1; }

	//int& Getvalue1() const { cout << "const"; return value1; } ������ ����! ������·� ��Ÿ���� ����, ������ �ȵ�

	const int& Getvalue1() const { cout << "const"; return value1; } // ��ü ��ü�� ���ȭ ���Ѿ� �Ѵ�.
	// �߰��� const ������ �� ������.����Լ���� ǥ��, �պκ� const�� �ܺο��� ���� ����Ǵ°� �� ���� ���� ���.
	// �����ε��� �ȴ�. const�� �پ��� ����!

	//void Setvalue(int value) const { this->value1 = value; }
	void Setvalue(int value) const { this->value2 = value; } // �Ϲ����� �Լ��� ������ ���ȭ�Ǿ� �Ұ����ϴ�.
	const int& Setvalue2(int value) const { this->value2 = value; }
	// �׷���, mutable ����� �����ϴ�.
};

void Print(const Data& data)
{
	data.Getvalue1();
}

int main()
{
	Data data1;
	const Data data2;

	data1.Getvalue();
	data2.Getvalue1();
	data2.Getvalue1(); // ���ȭ �� class�� ���ȭ �� ���� �ҷ��� �� �ִ�.

	Print(data2);

	return 0;
}