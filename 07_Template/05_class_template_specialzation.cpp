#include<iostream>

using namespace std;
// 클래스 자체, 전체의 특수화 이다.

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

// class 자체를 특수화 하였을 때. 매개함수를 바꾸어줄 수 있다.
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
	//achar.Test(); achar에는 Test 인수가 없다.


	return 0;
}