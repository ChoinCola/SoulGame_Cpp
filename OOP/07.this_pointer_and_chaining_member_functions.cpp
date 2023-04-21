//#include <iostream>
//
//using namespace std;
//
///*
//	this pointer : 객체 자신을 가리키는 용도로 사용되는 포인터
//	this 는 포인터를 돌려주는 코드 라고 생각하면된다.
//*/
//
//class Test
//{
//	int num;
//
//public:
//	Test(int n) : num(n)
//	{
//		cout << "num = " << num << endl;
//		cout << "num address : " << &num << endl;
//		cout << "this address : " << this << endl;
//	}
//
//	void ShowTestData()
//	{
//		cout << num << endl;
//	}
//
//	Test* GetThisPionter()
//	{
//		return this;
//	}
//};
//
//class Test2
//{
//	int a;
//	int b;
//	int c;
//
//public:
//	Test2() {}
//	~Test2() {}
//
//	auto GetA()
//	{
//		cout << this << endl;
//		return a;
//	}
//
//	//void SetA(const int& a) { a = a; } // 이런 방식으로는 사용할 수 없다. 모호성문제
//	void SetA(const int& a) {this-> a = a; } // 주소값 참조를 사용하여. 모호성 문제가 나타나지 않는다.
//};
//
//int main()
//{
//	Test t1(100);
//	Test* ptr1 = t1.GetThisPionter();
//	cout << ptr1 << endl;
//	ptr1->ShowTestData();
//
//	Test t2(200);
//	Test* ptr2 = t2.GetThisPionter();
//	cout << ptr2 << endl;
//	ptr2->ShowTestData();
//	return 0;
//}


#pragma region chaining member function
class Calc
{
	int value;

public:
	Calc(int value) : value(value) {}

	//void Add(int value) { this->value += value; }
	//void Sub(int value) { this->value -= value; }
	//void Mul(int value) { this->value *= value; }
	//void Div(int value) { this->value /= value; }
	//void Mod(int value) { this->value %= value; }
	// 셀프 레퍼런스 형태로 리턴시키는것. 값이 자기 자신이 되는것이다.

	Calc& Add(int value) { this->value += value; return *this; } // 참조값을 반환하게 된다. 나의 메모리 자체를 접근하는것.
	Calc& Sub(int value) { this->value += value; return *this; } // 응용이라고 생각하면 된다.
	Calc& Mul(int value) { this->value += value; return *this; }
	Calc& Div(int value) { this->value += value; return *this; }
	Calc& Mod(int value) { this->value += value; return *this; }




};

int main()
{
	Calc calc(10);
	calc.Add(5);
	calc.Div(2);

	//ananimous object
	Calc(20).Add(1).Add(2);
	cout << "a" << "b" << "c" << "d" << "e" << endl; // 체인은 잘 사용하지는 않는다.

	return 0;
}

#pragma endregion

// 화살표 타이밍 게임 만들기. 시간동안 칸이 조금씩 달아지고, 화살표를 시간안에 전부 눌러야한다.