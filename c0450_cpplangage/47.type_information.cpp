#include <iostream>

using namespace std;

int add(int a, int b) { return a + b; }
short add(short a, short b) { return a + b; }
float add(float a, float b) { return a + b; }
// Ÿ���� ������. �Լ� �����ε� �� �̾߱��Ѵ�.

/*
	template
*/
// �����ε��� ���� �ʾƵ�
template <typename T>
T add(T a, T b)
{
	return a + b;
}
// template���� �������� ����� �� �ִ�. ������ ���� ���� ���ø� ���캸��.

int main()
{
	cout << add(10, 20) << endl;
	cout << add(10.0f, 20.0f) << endl;
	cout << add(20.1, 50.2) << endl;

	return 0;
}