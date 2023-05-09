#include <iostream>

using namespace std;

// << ��� 
// >> �Է�
// ���ε� ���۷����� �� �� �� �ִ�.

class Point
{
	int x;
	int y;
public:
	Point(int x = 0, int y = 0) : x(x), y(y) {}

	auto Getx()const { return x; }
	auto Gety()const { return y; }

	void Print()
	{
		cout << "(" << x << ", " << y << ")" << endl;
	}
	
	friend ostream& operator << (ostream& out, const Point& p) 
	{
		out << "(" << p.x << ", " << p.y << ")" << endl;
		return out;
	}

	friend istream& operator >> (istream& in, Point& p)
	{
		in >> p.x >> p.y;
		return in;
	}


};

int main()
{

	Point p1(0, 1), p2(5, 5);
	p1.Print();

	cout << p1 << ", " << p2 << endl;

	cin >> p1;

	return 0;
}