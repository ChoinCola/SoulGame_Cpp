#include <iostream>

using namespace std;

// ���ø� Ư��ȭ
// ���ø��� ��� �ڷ����� ���� �����ϵ��� �ִ°ǵ�,
// Ư���� �ڷ����� ���� ����ó���� �ϱ� ���� ��������� ��.

template<typename T>
T GetMax(T x, T y)
{
	return (x > y) ? x : y;
}

template<>
char GetMax(char x, char y)
{
	cout << "Warning : comparing chars" << endl;
	return (x > y) ? x : y;
}

template<class T>
class Storage
{
	T value;
public:
	Storage(T value)
		:value(value)
	{}

	void Print()
	{
		cout << value << endl;
	}
};

 // �̿� ���� ���� template ���� �������� ���� �� �ϳ��� �� �� �� �ִ�.
template <>
void Storage<double>::Print()
{
	cout << "double : " << value << endl;
}

int main()
{
	cout << GetMax<int>(1, 2) << endl;
	cout << GetMax<float>(1.1f, 2.2f) << endl;
	cout << GetMax<char>(1, 2) << endl;
	cout << GetMax('a', 'b') << endl;

	Storage<int> s1(5);
	s1.Print();

	Storage<double> s2(5.5);
	s2.Print();

	return 0;
}