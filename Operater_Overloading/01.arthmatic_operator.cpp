#include <iostream>

using namespace std;

#pragma region 전역함수에 의한 연산자 오버로딩
//class Won
//{
//public:
//	Won(int value) : value(value) {}
//
//	int Getvalue() const { return value; }
//
//private:
//	int value;
//
//	friend int operator+(const Won& lhs, const Won& rhs); // 들어오는 인자값의 이름을 정해줌.
//
//	friend Won operator-(const Won& lhs, const Won& rhs) // 자체도 오버로딩 이라고 생각하면 된다.
//	{
//		return lhs.value - rhs.value;
//		// 연산자 오버로딩을 통해 계산된것 이기 떄문에, 18번째 줄 자체가 함수 오버로딩처럼 사용되어, Won이라는 이름없는 변수가 생성되고, value 가 빼진 값만을 가진 class가 된다.
//	}
//};
//
//int main()
//{
//	Won l(10), r(20);
//
//	int result = l + r;
//	cout << result << endl;
//
//	Won result2(1 - r);
//	cout << result2.Getvalue() << endl;
//
//	return 0;
//}
//
//int operator+(const Won& lhs, const Won& rhs)
//{
//	return lhs.value + rhs.value;
//}
//
///*
//	operator+ 라는 함수가 선언이 되었고, 코드 자체에 return이 써진것 이라고 생각하면 된다.
//*/

#pragma endregion

#pragma region 2. 멤버 함수에 의한 연산자 오버로딩
class Won
{
public:
	Won(int value) : value(value) {}

	int Getvalue() const { return value; }


	// l.operator+(r) 처럼 되는 형태이다.
	int operator+(const Won& rhs)
	{
		return value + rhs.value;
	}

	Won operator-(const Won& rhs)
	{
		return value + rhs.value;
	}

private:
	int value;
};

int main()
{
	Won l(10), r(10);

	int result = l + r;
	cout << result << endl;

	Won result2 = l - r;
	cout << result2.Getvalue() << endl;

	return 0;
}
#pragma endregion

/*
	과제.

	단항 연산자 +, +vector = vector, - vector = -vector
	이항 연산자 +, vector + vector = 2vector 이외에도 + - * / 가 있다.
	이항 연산자 *, vector * 3
	증감 연산자
	- 전위 ++vector
	- 후위 vector++
*/

#pragma region 산술 연산자 오버로딩
class Vector
{
public:
	Vector(int x, int y, int z) : x(x), y(y), z(z) {}

	auto operator+() const -> Vector
	{
		//return Vector{ x, y, z };
		return *this;
	}

	// 전위, 후위
	auto operator++() const -> Vector&
	{
		x += 1;
		++y;
		++z;

		return *this;
	}
	// 후위와 전위를 구분하기 위해 int를 넣게된다. 의미없는 값 인데 구분하기 위해 넣는다.
	auto operator++(int) const -> Vector&
	{
		Vector temp = *this;
		++(*this);
		return temp;
	}

private:
	int x;
	int y;
	int z;
	// 상대좌표 연산 제작.
};
// TODO 지렁이 게임을 만들 때, 리스트를 활용하는 것 이 좋다.
#pragma endregion