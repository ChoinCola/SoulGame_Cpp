#include <iostream>

// �� ��ȯ ������ ���� operator ���� �� �ִ�.
using namespace std;

class Won
{
	int value = 0; // ������ �ΰ� �̻��� ���, ���� �ʴ� ���� �̴�. ����ؾ��Ѵ�.
public:
	Won(int value = 0) : value(value) {}
	operator int()
	{
		return value;
	}
};

class Point
{
private:
	float x = 0.0f;
	float y = 0.0f;
	float z = 0.0f;
public:
	Point(float x, float y, float z)
		:x(x), y(y), z(z)
	{}

	operator float* () // �̷������� ������ ���·� �޾ƿ��� �����ϴ�.�ֳ��ϸ�, ���ӵ� �ּҰ��� �������� ������ ��ä�� ����°� �̶�� �� �� �ֱ� ����,
	{
		return &x;
	}
};

void PrintPoint(float points[3])
{
	cout << points[0] << endl;
	cout << points[1] << endl;
	cout << points[2] << endl;
}

void Print(int val)
{
	cout << val << endl;
}

int main()
{
	Won w(10);

	Print(w);
	// ������ �� ��ȯ�ڰ� ���ٰ� ��Ÿ����.
	// �׷��� 11�� �� ó�� return value���� ���������� �����ϴ�.

	Point p(1.0f, 1.0f, 1.0f);

	PrintPoint(p);
	return 0;
}

//// �ð� ���ϱ�
//class Hour
//{
//
//};
//
//class Minute
//{
//
//};
//
//class Second
//{
//
//};
//
//class MilliSecond
//{
//
//};
//
//Hour h(1);
//PrintHour(h); 1
//Printminute(h); 60
//PirntSecond(h); 60 * 60
//PrintMilliSecond(h); 60 * 60 * 1000
//// �ð� ���� ���ϴ� �Լ� �����.
//// �����ε��� ����Ͽ� �����.


// ������� �����.