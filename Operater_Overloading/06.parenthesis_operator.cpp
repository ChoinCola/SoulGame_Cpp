#include <iostream>

// () 는 묶는 느낌으로 사용할 수 있지만, 함수를 호출하는 방식으로 사용할 수 있다.
// 이것으로 오버로딩을 하는 이유는, 객체를 함수처럼 사용하기 위해서 사용한다.

using namespace std;

class Counter
{
	int count = 0;
public:
	int operator()(int i) { return count += i; }
};

class Point
{
	int xpos, ypos;
public:

	Point(int x = 0, int y = 0) : xpos(x), ypos(y) {}

	Point operator + (const Point & pos) const
	{
		return Point(xpos + pos.xpos, ypos + pos.ypos);
	}

	friend ostream& operator <<(ostream& os, const Point& pos)
	{
		os << "[" << pos.xpos << ", " << pos.ypos << "]" << endl;
		return os;
	}
};

class Adder
{
public:
	int operator() (const int& n1, const int& n2)
	{
		return n1 + n2;
	}
	double operator() (const double& n1, const double& n2)
	{
		return n1 + n2;
	}
	Point operator() (const Point& n1, const Point& n2)
	{
		return n1 + n2;
	}
};

int main()
{
	Counter ct;

	cout << ct(10) << endl; // 이런식으로 사용하는 방법을 Functor, Function Object 라고 한다.
	cout << ct(20) << endl;
	cout << ct(30) << endl;

	cout << endl;

	Adder adder;

	cout << adder(1, 2) << endl;
	cout << adder(3, 4) << endl;
	cout << adder(Point(1, 2), Point(3, 4)) << endl;
	return 0;
}