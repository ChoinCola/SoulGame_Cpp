#include <iostream>
#include <functional>

using namespace std;

bool func(const int& x) // L-value ���۷���
{
	return x > 0;
}

typedef bool(*funcPtr)(const int&); // �Լ� �����͸� �������� �� �ִ�. 

using funcType = bool(*)(const int&); // �̿� ���� ������� �Լ� �����͸� �������� ���� �ִ�.

int main()
{
	bool (*pf)(const int&) = func; // �Լ� ������ ���۹��.

	funcPtr f = func; // �Լ� �����͸� �������༭ ����ϴ� ���.

	funcType f2 = func;

	std::function<bool(const int&)> f3 = func; // �Լ� �����Ϳ� ���ۿ����� ����. #include <functional> ����� ����Ͽ� �ڵ��ϴ°�.


	return 0;
}