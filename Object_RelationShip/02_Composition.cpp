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
		// 이렇게 쓰면 강력한 연관관계가 되어버린다.
		// 이는 Point2D가 없어지면 Monster가 동작하지 않기 때문,
	}
	
	// Aggregation
	Monster(Point2D* point)
	{
		this->Position2 = point;
		// 종료되더라도 포인터의 원본값은 사라지지 않는다.
	}
};

int main()
{
	Monster mon1(10, 20);

	Point2D point;
	Monster mon2(&point);


	return 0;
}