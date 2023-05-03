#include <iostream>

using namespace std;

#pragma region �����Լ��� ���� ������ �����ε�
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
//	friend int operator+(const Won& lhs, const Won& rhs); // ������ ���ڰ��� �̸��� ������.
//
//	friend Won operator-(const Won& lhs, const Won& rhs) // ��ü�� �����ε� �̶�� �����ϸ� �ȴ�.
//	{
//		return lhs.value - rhs.value;
//		// ������ �����ε��� ���� ���Ȱ� �̱� ������, 18��° �� ��ü�� �Լ� �����ε�ó�� ���Ǿ�, Won�̶�� �̸����� ������ �����ǰ�, value �� ���� ������ ���� class�� �ȴ�.
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
//	operator+ ��� �Լ��� ������ �Ǿ���, �ڵ� ��ü�� return�� ������ �̶�� �����ϸ� �ȴ�.
//*/

#pragma endregion

#pragma region 2. ��� �Լ��� ���� ������ �����ε�
class Won
{
public:
	Won(int value) : value(value) {}

	int Getvalue() const { return value; }


	// l.operator+(r) ó�� �Ǵ� �����̴�.
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
	����.

	���� ������ +, +vector = vector, - vector = -vector
	���� ������ +, vector + vector = 2vector �̿ܿ��� + - * / �� �ִ�.
	���� ������ *, vector * 3
	���� ������
	- ���� ++vector
	- ���� vector++
*/

#pragma region ��� ������ �����ε�
class Vector
{
public:
	Vector(int x, int y, int z) : x(x), y(y), z(z) {}

	auto operator+() const -> Vector
	{
		//return Vector{ x, y, z };
		return *this;
	}

	// ����, ����
	auto operator++() const -> Vector&
	{
		x += 1;
		++y;
		++z;

		return *this;
	}
	// ������ ������ �����ϱ� ���� int�� �ְԵȴ�. �ǹ̾��� �� �ε� �����ϱ� ���� �ִ´�.
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
	// �����ǥ ���� ����.
};
// TODO ������ ������ ���� ��, ����Ʈ�� Ȱ���ϴ� �� �� ����.
#pragma endregion