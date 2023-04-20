#include <iostream>
#include <functional>

using namespace std;

bool func(const int& x) // L-value 레퍼런스
{
	return x > 0;
}

typedef bool(*funcPtr)(const int&); // 함수 포인터를 정의해줄 수 있다. 

using funcType = bool(*)(const int&); // 이와 같은 방법으로 함수 포인터를 정의해줄 수도 있다.

int main()
{
	bool (*pf)(const int&) = func; // 함수 포인터 제작방식.

	funcPtr f = func; // 함수 포인터를 정의해줘서 사용하는 방식.

	funcType f2 = func;

	std::function<bool(const int&)> f3 = func; // 함수 포인터와 동작원리가 같다. #include <functional> 방식을 사용하여 코딩하는것.


	return 0;
}