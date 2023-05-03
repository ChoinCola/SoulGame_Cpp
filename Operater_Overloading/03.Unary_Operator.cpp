#include <iostream>

using namespace std;
// 단항 연산자 도 만들 수 있다.
//+ - !

class Won
{
	int value;

public:
	Won(int value = 0) : value(value) {}

	//!
	bool operator!() const
	{
		return (value == 0) ? true : false; // 삼항 연산자
	}

	friend ostream& operator << (ostream & out, const Won & won)
	{
		out << won.value;
		return out;
	}
};

int main()
{
	const Won w1(10);
	const Won w2(0);

	cout << !w1 << endl; // 0이 찍힌다.

	cout << boolalpha; // 알파벳으로 true와 false를 나타내준다.
	cout << !w2 << endl;

	return 0;
}