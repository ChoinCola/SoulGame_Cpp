#include <iostream>

using namespace std;
// Ŭ������ �ν��Ͻ�ȭ ���� �ʰ� �׳� ����Ϸ��� �� ��

class A
{
public:
	void print()
	{
		cout << "print" << endl;
	}
};

int main()
{
	A().print(); // �͸�ü�� ����ϴ� ��.

	return 0;
}