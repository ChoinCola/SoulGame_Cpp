#include <iostream>

using namespace std;

int add(int a, int b) { return a + b; }
short add(short a, short b) { return a + b; }
float add(float a, float b) { return a + b; }
// 타입이 여러개. 함수 오버로딩 을 이야기한다.

/*
	template
*/
// 오버로딩을 하지 않아도
template <typename T>
T add(T a, T b)
{
	return a + b;
}
// template으로 여러개를 사용할 수 있다. 다음과 같은 실행 예시를 살펴보자.

int main()
{
	add(10, 20);
	add(10.0f, 20.0f);
	add(20.1, 50.2);

	return 0;
}