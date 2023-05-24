#include <iostream>

// static binding(Early binding)
// binding �� ���� ���Ŀ� ������ �������ε� [ ������ Ÿ�� �� ȣ���� �Լ��� ������ ]
// Dynamic binding(late binding)
// binding �� ���� ���߿� ������ ���߹��ε� [ ��Ÿ�� ���� �� ȣ���� �Լ��� ������ ]
// �Լ� �����ͷ� ���ϴ´���

using namespace std;

int add(int x, int y) { return x + y; }
int subract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
	cin >> op;

	// ���� ���ε�
	int result;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subract(x, y); break;
	case 2: result = multiply(x, y); break;
	}

	cout << result << endl;

	// ���� ���ε�
	// ������ ���·� ���ݴ� ��ü���������� ���� �� ����ϰ� �ȴ�.
	int(*funcPtr)(int, int) = nullptr;

	switch (op)
	{
	case 0: funcPtr = add; break;
	case 1: funcPtr = subract; break;
	case 2: funcPtr = multiply; break;
	}

	cout << result << endl;

	return 0;
}