#include <iostream>
// ����Ʈ ������ ���� ����
using namespace std;
// * -> �Ѵ� ���� ������ ��, �����ε� �ȴ�.

class Number
{
	int num;
public:

	Number(int n) : num(n) {}

	void ShowData()
	{
		cout << num << endl;
	}

	// -> �� ��ü �ڽ��� �ּҰ��� ��ȯ���ش�.
	Number* operator ->() // �ڱ��ּ� ��ȯ
	{
		return this;
	}

	Number& operator*()
	{
		return *this;
	}
};
int main()
{
	Number num(20);
	num.ShowData();
	(*num) = 30;
	num->ShowData();
	// num.operator->()->showData(); �� ���·� ���� �� �ִ�.

	num.operator*() = 30;
	num.operator*().ShowData();

	return 0;
}