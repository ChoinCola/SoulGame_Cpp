#include <iostream>
// 스마트 포인터 형태 제작
using namespace std;
// * -> 둘다 단항 연산자 로, 오버로딩 된다.

class Number
{
	int num;
public:

	Number(int n) : num(n) {}

	void ShowData()
	{
		cout << num << endl;
	}

	// -> 는 객체 자신의 주소값을 반환해준다.
	Number* operator ->() // 자기주소 반환
	{
		return this;
	}

	Number& operator*()
	{
		return *this;
	}
};
int main()
{
	Number num(20);
	num.ShowData();
	(*num) = 30;
	num->ShowData();
	// num.operator->()->showData(); 의 형태로 써줄 수 있다.

	num.operator*() = 30;
	num.operator*().ShowData();

	return 0;
}