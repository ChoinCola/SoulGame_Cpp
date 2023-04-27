#include <iostream>

using namespace std;

class Data
{
	int value1;
	mutable int value2; // 여의치 않을 때 사용하는 느낌이라고 생각하면 된다. 상수화 된 class에서 수정해야 할 경우가 생기면 사용한다.

public:
	Data() : value1(0) {}

	int& Getvalue() { cout << "not const" << endl; return value1; }

	//int& Getvalue1() const { cout << "const"; return value1; } 오류가 난다! 상수형태로 나타나기 떄문, 리턴이 안됨

	const int& Getvalue1() const { cout << "const"; return value1; } // 객체 자체를 상수화 시켜야 한다.
	// 중간에 const 선언이 된 이유는.상수함수라는 표시, 앞부분 const는 외부에서 값이 변경되는것 을 막기 위해 사용.
	// 오버로딩이 된다. const가 붙었기 때문!

	//void Setvalue(int value) const { this->value1 = value; }
	void Setvalue(int value) const { this->value2 = value; } // 일반적인 함수는 변경이 상수화되어 불가능하다.
	const int& Setvalue2(int value) const { this->value2 = value; }
	// 그러나, mutable 선언시 가능하다.
};

void Print(const Data& data)
{
	data.Getvalue1();
}

int main()
{
	Data data1;
	const Data data2;

	data1.Getvalue();
	data2.Getvalue1();
	data2.Getvalue1(); // 상수화 된 class는 상수화 된 값만 불러올 수 있다.

	Print(data2);

	return 0;
}