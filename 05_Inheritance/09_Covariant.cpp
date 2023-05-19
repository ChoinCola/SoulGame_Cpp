#include <iostream>

using namespace std;
// 자기자신을 가리키는 포인터를 출력할 때 는 상속자 기준으로 출력이 아니라 포인터 기준으로 출력된다.

class A
{
public:
	virtual A* GetThisPointer() { cout << "A" << endl; return this; }
	void print() { cout << "A" << endl; }
};

class B : public A
{
public:
	B* GetThisPointer() override { cout << "B" << endl; return this; }
	void print() { cout << "B" << endl; }
};

int main()
{
	B b;

	b.print();
	cout << "Address : " << b.GetThisPointer() << endl;
	cout << "typeid : " << typeid(b.GetThisPointer()).name() << endl;

	A& ref = b;
	ref.print(); // A가 참조되어서, override가 되지 않았기 때문에, A가 출력된다.
	cout << "Adress : " << ref.GetThisPointer() << endl; // B를 출력하기 때문에 B가 출력되는것 이 맞다.
	cout << "typeid : " << typeid(ref.GetThisPointer()).name() << endl; // 타입 자체는 A이기 때문에 A의 타입이 반환되는것 이다.

	return 0;
}