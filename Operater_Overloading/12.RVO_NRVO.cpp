#include <iostream>

/*
	RVO = Retrun Value Optimization
	������ �� �̸����� ��ü�� �ڵ�����ȭ. ���簡�ƴ϶� ��������
	NRVO = Named Return Value Optimization
	�̸��ִ� �̸��ִ� ��ü�� RVOó�� ���ִ°�. 
	����ȭ �Ҷ� ����ϴ� ���.

*/

using namespace std;

class Test
{
	int value1;
	int value2;

public:
	static int count;

	Test(int value)
		:value1(value),
		value2(count++) // ������ ������ ī��Ʈ�� �־��ش�.
	{
		cout << "constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	Test(const Test& rhs)
		:value1(rhs.value1), value2(count++)
	{
		cout << "copy constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	~Test()
	{
		cout << "destructor : " << this->value1 << ", " << this->value2 << endl;
	}
};

int Test::count = 1;

Test MakeRVO(int value)
{
	return Test(value);
	// �ӽð�ü�� ������ �̷������ �ʰ� �׳� ��ȯ���ȴ�.
}

Test MakeNRVO(int value)
{
	Test test(value);
	return test;
	// �ӽð�ü�� ������ �̷������ ��ȯ�ȴ�. ��������ڰ� ȣ��ȴ�.
}

int main()
{
	cout << "---RVO---" << endl;
	Test t1 = MakeRVO(1);

	cout << "---NRVO---" << endl;
	Test t2 = MakeNRVO(1);
	// �����Ϸ� ������ �̷��� ������ ��Ÿ����, ��������� ��Ÿ���� �ʴ´�.
	return 0;
}