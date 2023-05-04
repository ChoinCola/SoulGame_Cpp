#include <iostream>

// 형 변환 연산자 역시 operator 해줄 수 있다.
using namespace std;

class Won
{
	int value = 0; // 변수가 두개 이상일 경우, 맞지 않는 사용법 이다. 기억해야한다.
public:
	Won(int value = 0) : value(value) {}
	operator int()
	{
		return value;
	}
};

class Point
{
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
public:
	Point(float x, float y, float z)
		:x(x), y(y), z(z)
	{}

	operator float* () // 이런식으로 포인터 형태로 받아오면 가능하다.왜냐하면, 연속된 주소값을 가져오기 때문에 전채를 끌어온것 이라고 볼 수 있기 때문,
	{
		return &x;
	}
};

void PrintPoint(float points[3])
{
	cout << points[0] << endl;
	cout << points[1] << endl;
	cout << points[2] << endl;
}

void Print(int val)
{
	cout << val << endl;
}

int main()
{
	Won w(10);

	Print(w);
	// 적절한 형 변환자가 없다고 나타난다.
	// 그러나 11번 줄 처럼 return value값을 돌려줌으로 가능하다.

	Point p(1.0f, 1.0f, 1.0f);

	PrintPoint(p);
	return 0;
}

//// 시간 구하기
//class Hour
//{
//
//};
//
//class Minute
//{
//
//};
//
//class Second
//{
//
//};
//
//class MilliSecond
//{
//
//};
//
//Hour h(1);
//PrintHour(h); 1
//Printminute(h); 60
//PirntSecond(h); 60 * 60
//PrintMilliSecond(h); 60 * 60 * 1000
//// 시간 각각 구하는 함수 만들기.
//// 오버로딩을 사용하여 만들기.


// 리듬게임 만들기.