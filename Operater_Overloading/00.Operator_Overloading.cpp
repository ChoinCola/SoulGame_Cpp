#include <iostream>

using namespace std;

/*
	. .* :: ?: # ## 접근 연산자
	이러한 연산자를 제외한 것은 모두 오버로딩이 가능하다.

	& 둘다 1일 때만 참 1111 1001 -> 1001
	| 둘다 0일 때만 참 1111 1001 -> 0000 
	^ 서로 다를 때만 1 1111 1001 -> 0110 
	위의 연산자는 너무 순위가 낮아서 따로 오버로딩을 처리 해야한다.
*/

class Number
{
public:
	Number(int num)
		:num(num)
	{}

	void SetNum(int num)
	{
		this->num = num;
	}
	int GetNum() {
		return num;
	}

	auto operator+(Number& def) -> Number&
	{
		this->num + def.num;
		return *this;
	}

private:
	int num;
};

int main()
{
	Number a(10), b(20);

	//int result = a + b;

	int result = a.GetNum() + b.GetNum();
	a.SetNum(result);

	Number c = a + b;
	// 위의 연산을 올바르게 할려면 40번째 줄이 맞는 형식이다.
	// 그러나, 이러한 연산자를 생성하려면 너무 불편하고 Get과 Set은 객체지향적인 코딩을 벗어나게 된다.
	// 그때 사용하는 것 이 연산자 오버로딩이다.

	return 0;
}