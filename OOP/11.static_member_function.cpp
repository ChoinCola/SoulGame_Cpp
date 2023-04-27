#include <iostream>

using namespace std;

class Test
{
	int value;
	static int value2;

public:
	Test() {}
	void Temp1() { this->Temp1; }
	void Temp() const { this->value; }

	static void Temp2() { this->value; }
	// 전역 함수 이기 때문에, 전역변수만 사용이 가능하다.
};

int main()
{
	Test t1;
	t1.Temp1();

	Test::Temp2();

	void (*ptr1)() = Test::Temp2; // 함수 포인터 처리 사용 또한 가능하다.
	void (*ptr1)() = Test::Temp1; // 소유자를 알 수 없기 떄문에 해당 방식은 불가능하다.

	/*
		멤버 포인터
	*/
	int Test::* ptr2 = &Test::Test;
	t1.*ptr2 = 10; // 이러면 포인터가 내부에 생성된다.

	void (Test:: * ptr3)() = &Test::Temp1; // 단순 주소만 소유한 것 이 만들어졌다.
	(t1.*ptr3)();

	return 0;
}