#include <iostream>

using namespace std;
// �Ϲ�ȭ ���α׷���, �پ��� ���α׷��� ������ �˰����� �־�� �� �� ����Ѵ�.

//int GetMax(int x, int y) { return x > y ? x : y; }
//short GetMax(short x, short y) { return x > y ? x : y; }
//double GetMax(double x, double y) { return x > y ? x : y; }
//float GetMax(float x, float y) { return x > y ? x : y; }

// ���ø� ����� ������ ���� �������ָ� �ȴ�.
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

	// cout << GetMax(1, 2.0f) << endl; �̰�쿡�� ������ ����. T�� ���� Type �̱� ������.

	cout << GetMax<int>(1, 2.0f) << endl;

	cout << GetMax(Won(6), Won(2)) << endl;
	return 0;
}