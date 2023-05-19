#include <iostream>
// 가상함수 에서 재정의하여 출력하는 예시.
using namespace std;

class A
{
public:
	void Print() { cout << "A" << endl; }
	virtual void Print1()		{ cout << "A1" << endl; }
	virtual void Print2()		{ cout << "A2" << endl; }
	virtual void Print3()		{ cout << "A3" << endl; }
	virtual void Print4() final { cout << "A4" << endl; }
};

class B : public A
{
public:
	void Print() { cout << "B" << endl; }
	virtual void Print1()		{ cout << "B1" << endl; }
	virtual void Print2()		{ cout << "B2" << endl; }
	virtual void Print3() final { cout << "B3" << endl; }
//	virtual void Print4() final { cout << "A4" << endl; }
};

class C : public B
{
public:
	void Print() { cout << "C" << endl; }
	virtual void Print1()		{ cout << "C1" << endl; }
	virtual void Print2() final { cout << "C2" << endl; }
//	virtual void Print3() final { cout << "C3" << endl; }
//	virtual void Print4() final { cout << "C4" << endl; }
};

class D : public C
{
public:
	void Print() { cout << "D" << endl; }
	virtual void Print1() final	{ cout << "D1" << endl; }
//	virtual void Print2() final { cout << "D2" << endl; }
//	virtual void Print3() final { cout << "D3" << endl; }
//	virtual void Print4() final { cout << "D4" << endl; }
};
int main()
{
	A a;
	a.Print1();

	B b;
	b.Print1();

	C c;
	c.Print1();

	D d;
	d.Print1();

	cout << endl;

	A& refB = b;
	A& refC = c;
	A& refD = d;

	cout << "######### A" << endl;
	a.Print();
	a.Print1();
	a.Print2();
	a.Print3();
	a.Print4();

	cout << "######### refB" << endl;
	refB.Print();
	refB.Print1();
	refB.Print2();
	refB.Print3();
	refB.Print4();

	cout << "######### refC" << endl;
	refC.Print();
	refC.Print1();
	refC.Print2();
	refC.Print3();
	refC.Print4();

	cout << "######### refD" << endl;
	refD.Print();
	refD.Print1();
	refD.Print2();
	refD.Print3();
	refD.Print4();

	D d1;
	D d2;
	// d1 과 d2의 주소는 같다.
	// 가상함수 테이블은 함수 포인터 배열이라고 생각하면 된다. 가상함수의 배열의 순서로 접근하게 된다.
	// 가상함수 테이블은 변수주소와는 다르다고 생각하면 된다.
	// 선입선출 방식으로 덮어씌워지면서 생성이된다.

	return 0;
}

/*
	vehicle 이라는 class를 만들고, 비행기이동, 자동차이동 등 여러개의 객체가 생성될 때 객체가 5개까지 만들 수 있지만, 이동객체 수가 5가 초과됩니다. 라고 나타나게
	또한 생성 안되게 만들어보기.
	virtual void movement() {} 를 출력하게 만들때.

*/