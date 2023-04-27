#include <iostream>

using namespace std;
// 외부에서 프랜드에게 프라이빗을 접근할 수 있게 하는것.
// a가 b에게 프렌드 선언하면 b는 a의 프라이빗에 접근할 수 있다.
// 그러나, a는 b에 접근할 수 없다. 프랜드 선언이 안되어있기 떄문.

#pragma region friend global function
//class A
//{
//	int value = 1;
//
//	friend void doSomething1(const A& a);
//	// 이러면 전역함수 취급을 받을 수 있다.
//	friend void doSomething2(const A& a)
//	{
//		cout << a.value << endl;
//	}
//};
//
//void doSomething1(const A& a)
//{
//	cout << a.value << endl;
//}
//
//int main()
//{
//	A a;
//	doSomething1(a);
//	doSomething2(a);
//
//	return 0;
//}
//
// //사실상 위와 같이 전역식으로 접근하는 것 보다는 특정 함수가 접근할 때 사용한다

#pragma endregion

#pragma region friend member class
//class A
//{
//public:
//	void attack(B& b);
//private:
//	int a;
//	
//};
//
//class B
//{
//	friend void A::attack(B& b);
//	// 원래라면, A는 B에 있는 hp 100을 사용할 수 없지만.
//	// 위와 같이 함수에 대해 허용을 해주면 접근을 할 수 있다.
//private:
//	int hp = 100;
//};
//
//void A::attack(B& b)
//{
//	cout << "b의 채력 : " << b.hp << endl;
//
//	cout << "공격!" << endl;
//	b.hp -= 10;
//}
//
//int main()
//{
//	A a;
//	B b;
//	// b.a; // 이런식으로는 접근이 안된다. b에는 friend 키워들르 제공하지 않았기 때문
//	
//}
// //가장 많이사용하는 방식.
#pragma endregion

#pragma region friend class
class A
{
public:
	void PrintBvalue1(class B& b);
	void PrintBvalue2(class B& b);
};

class B
{
	friend class A;
	// B에 있는 모든 함수를 A에 허용하고 싶을 때.
	// 어떠한 변수 하나만 찍어서 공유는 할 수 없다.
	int value1 = 10;
	int value2 = 20;
};

void A::PrintBvalue1(B& b)
{
	cout << b.value1 << endl;
}

void A::PrintBvalue2(B& b)
{
	cout << b.value2 << endl;
}

int main()
{
	A a;
	B b;

	a.PrintBvalue1(b);
	a.PrintBvalue2(b);

	return 0;
}
#pragma endregion

