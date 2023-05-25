#include <iostream>

using namespace std;
/*
	dynamic cast
	- 안전한 다운캐스팅 에 사용

*/

class Base
{
public:
	int i = 0;
	virtual void Print() { cout << "Base" << endl; }

};

class Derived1 : public Base
{
public:
	int j = 1;
	virtual void Print() override { cout << "Derived1" << endl; }
};

class Derived2 : public Base
{
public:
	int k = 2;
	virtual void Print() override { cout << "Derived2" << endl; }
};

void DoSomething(Base* b)
{
	//Derived2* baseToD2 = static_cast<Derived2*>(b);
	//baseToD2->k = 888;
	// 위와같은 방식으로 진행하면 j 에 888이 들어가버린다.
	Derived2* baseToD2 = dynamic_cast<Derived2*>(b);
	baseToD2->k = 888;
	// 런타임 상황에서 잡아준다.
}

int main()
{
	Derived1 d1;
	Base* base = &d1;

	Derived1* baseToD1 = static_cast<Derived1*>(base);
	baseToD1->Print();

	DoSomething(&d1);
	// j의 정보가 있는 d1을 d2로 바꾸어서 k값을 바꾸었다.

	cout << d1.j << endl;
	// 강제적인 형변환이 일어나기 때문에, 원하지 않는 정보의 변환이 이루어질 수 있다.

	// 다이나믹 케스팅은 런타임 때 오류를 잡아준다. 그래서 조금 느릴 수 있다.

	return 0;
}