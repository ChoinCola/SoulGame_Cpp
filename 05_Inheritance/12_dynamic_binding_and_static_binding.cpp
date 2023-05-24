#include <iostream>

// static binding(Early binding)
// binding 이 실행 이후에 결정됨 전역바인딩 [ 컴파일 타임 때 호출할 함수가 정해짐 ]
// Dynamic binding(late binding)
// binding 이 실행 도중에 결정됨 도중바인딩 [ 런타임 도중 중 호출할 함수가 정해짐 ]
// 함수 포인터로 정하는느낌

using namespace std;

int add(int x, int y) { return x + y; }
int subract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }

int main()
{
	int x, y;
	cin >> x >> y;

	int op;
	cout << "0 : add, 1 : subtract, 2 : multiply" << endl;
	cin >> op;

	// 정적 바인딩
	int result;
	switch (op)
	{
	case 0: result = add(x, y); break;
	case 1: result = subract(x, y); break;
	case 2: result = multiply(x, y); break;
	}

	cout << result << endl;

	// 동적 바인딩
	// 포인터 형태로 조금더 객체지향적으로 나눌 때 사용하게 된다.
	int(*funcPtr)(int, int) = nullptr;

	switch (op)
	{
	case 0: funcPtr = add; break;
	case 1: funcPtr = subract; break;
	case 2: funcPtr = multiply; break;
	}

	cout << result << endl;

	return 0;
}