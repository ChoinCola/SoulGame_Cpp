#include <iostream>

using namespace std;
// 일반화 프로그래밍, 다양한 프로그램에 동일한 알고리즘을 넣어야 할 때 사용한다.

//int GetMax(int x, int y) { return x > y ? x : y; }
//short GetMax(short x, short y) { return x > y ? x : y; }
//double GetMax(double x, double y) { return x > y ? x : y; }
//float GetMax(float x, float y) { return x > y ? x : y; }

// 템플릿 선언시 다음과 같이 선언해주면 된다.
template <typename T>
T GetMax(T x, T y) { return x > y ? x : y; }

class Won
{
	int value = 0;
public:
	Won(int value = 0) : value(value) {}

	bool operator > (const Won& rhs)
	{
		return value > rhs.value;
	}

	friend ostream& operator << (ostream& out, const Won& won)
	{
		cout << won.value;
		return out;
	}
};

int main()
{
	cout << GetMax(1, 2) << endl;
	cout << GetMax(1.1f, 2.0f) << endl;
	cout << GetMax(1.2, 2.3) << endl;
	cout << GetMax(1u, 2u) << endl;
	cout << GetMax(1ll, 2ll) << endl;

	// cout << GetMax(1, 2.0f) << endl; 이경우에는 오류가 난다. T가 같은 Type 이기 때문에.

	cout << GetMax<int>(1, 2.0f) << endl;

	cout << GetMax(Won(6), Won(2)) << endl;
	return 0;
}