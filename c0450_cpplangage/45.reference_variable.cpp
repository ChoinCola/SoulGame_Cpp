#include <iostream>

using namespace std;

/*
	L-value R-value

	왼쪽에 있으면 L 오른쪽에 있으면 R

	int a = 10;
	L-value : a
	R-value : 10

	L-value : 식이 끝나도, 나중에 다시 접근이 가능한 값
	R-value : 식이 끝나면, 나중에 다시 접근이 불가능한 값
*/

int Test1(int& a) // 카피
{
	return a;
}

int Test2(int&& a) // move 라고 생각한다.
{
	return a;
}

int main()
{
	int val = 5;

	int& r = val;
	// 자료형 옆에 붙은 & 는 L-value 레퍼런스. 변수의 별명 이라고 생각하면 된다.
	// 위는 
	int* ptr = &val;
	// 과 같은 효과를 가진다.
	// 포인터는 주소값을 가지는 데이터공간이 추가적으로 할당된다.
	// 그러나 변수별명 을 선언하게 되면, 데이터공간이 따로 할당되는 것 이 아닌, 레퍼런스 자체가 해당 자료를 가리키게 된다.

	r = 10;

	cout << val << endl;
	cout << r << endl;
	// 단, r을 초기화 할 때 에는 NULL값 같은것 이 아닌 변수로 초기화를 해주어야 한다. 메모리공간이 안잡히기 때문,
	/*
	int& r2;
	int& r3 = 10;
	*/
	// 위의 초기화는 불가능하다. 메모리공간이 없기 때문

	const int& r4 = 10;
	// 은 가능하다. 상수화 시키기 때문에, 하나의 변수 처럼 활용하기 때문.

	int&& rr = 10; // const int rr 과 같은 역활을 한다. 프로그래머의 의도만 전달하기 때문이다.
	return 0;
}