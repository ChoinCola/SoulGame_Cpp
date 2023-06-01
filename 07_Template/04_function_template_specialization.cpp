#include <iostream>

using namespace std;

// 템플릿 특수화
// 템플릿은 어떠한 자료형이 들어가든 동작하도록 넣는건데,
// 특정한 자료형에 대해 예외처리를 하기 위해 만들어지는 것.

template<typename T>
T GetMax(T x, T y)
{
	return (x > y) ? x : y;
}

template<>
char GetMax(char x, char y)
{
	cout << "Warning : comparing chars" << endl;
	return (x > y) ? x : y;
}

template<class T>
class Storage
{
	T value;
public:
	Storage(T value)
		:value(value)
	{}

	void Print()
	{
		cout << value << endl;
	}
};

 // 이와 같은 경우로 template 또한 다형성의 형태 중 하나임 을 알 수 있다.
template <>
void Storage<double>::Print()
{
	cout << "double : " << value << endl;
}

int main()
{
	cout << GetMax<int>(1, 2) << endl;
	cout << GetMax<float>(1.1f, 2.2f) << endl;
	cout << GetMax<char>(1, 2) << endl;
	cout << GetMax('a', 'b') << endl;

	Storage<int> s1(5);
	s1.Print();

	Storage<double> s2(5.5);
	s2.Print();

	return 0;
}