#include <iostream>

using namespace std;

class Point2D
{
public:
	int x;
	int y;
};

class Monster
{
	string name;
	Point2D Position1;
	Point2D* Position2;

public:
	// composition
	Monster(int x, int y)
	{
		Position1.x = x;
		Position1.y = y;
		// �̷��� ���� ������ �������谡 �Ǿ������.
		// �̴� Point2D�� �������� Monster�� �������� �ʱ� ����,
	}
	
	// Aggregation
	Monster(Point2D* point)
	{
		this->Position2 = point;
		// ����Ǵ��� �������� �������� ������� �ʴ´�.
	}
};

int main()
{
	Monster mon1(10, 20);

	Point2D point;
	Monster mon2(&point);


	return 0;
}