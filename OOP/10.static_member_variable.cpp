#include <iostream>

using namespace std;
// static변수는 선언 시 부터 전역변수 취급된다. 그전에는 없음.


class Test
{
public:
	int value = 1;
	// 위 변수는 인스턴스가 선언되기 전 까지는 데이터 영역을 차지하지 않음.
	static int count;
	// 위 변수는 선언되기 전에도 전역변수 이기 때문에, 데이터 영역을 할당시켜준다. 그러나 전역변수 이기 때문에, class 내에서는 초기화가 안되고
	// 전역변수 이기 때문에 메인문이 있는 프로그램의 동작부 에서 초기화를 해주어야 한다.
	static const int test = 10;
	// 상수취급 되어서 선언 시 초기화가 가능하다.
};

int Test::count = 10;

int main()
{
	Test t1, t2;

	t1.value = 10;
	t2.value = 20;

	t1.count = 30;
	t2.count = 40;

	cout << &t1.count << " " << t1.count << endl;
	cout << &t2.count << " " << t2.count << endl;
	// 전역변수 취급이기 떄문에 모든 class는 해당 데이터를 공유하게 된다.
	
	cout << &Test::count << " " << Test::count << endl;
	// 객체가 잡혀있지 않아도 사용할 수 있다. const 이기 때문에 상수취급 받아서.
	return 0;
}