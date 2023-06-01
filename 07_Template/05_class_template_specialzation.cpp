#include<iostream>

using namespace std;
// Ŭ���� ��ü, ��ü�� Ư��ȭ �̴�.

template<class T>
class A
{
public:
	A(const T& input) {}
	void DoSomthing()
	{
		cout << typeid(T).name() << endl;
	}

	void Test() {}
};

// class ��ü�� Ư��ȭ �Ͽ��� ��. �Ű��Լ��� �ٲپ��� �� �ִ�.
template<>
class A<char>
{
public:
	A(const char& input) {}
	void DoSomthing()
	{
		cout << "char type specialization" << endl;
	}
};

int main()
{
	A<int> aint(10);
	A<double> adouble(10.1);
	A<char> achar('a');

	aint.DoSomthing();
	adouble.DoSomthing();
	achar.DoSomthing();

	aint.Test();
	adouble.Test();
	//achar.Test(); achar���� Test �μ��� ����.


	return 0;
}