#include <iostream>

using namespace std;

class Point
{
	int xpos;
	int ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{
		cout << "Point 객체 생성" << endl;
	}
	~Point()
	{
		cout << "Point 객체 소멸" << endl;
	}

	void SetPos(int x, int y)
	{
		xpos = x;
		ypos = y;
	}

	friend ostream& operator << (ostream& os, const Point pos)
	{
		os << '[' << pos.xpos << ", " << pos.ypos << ']' << endl;
		return os;
	}
};

class SmartPtr
{
public:
	SmartPtr(Point* ptr) : posptr(ptr) {}

	Point& operator*() const
	{
		return *posptr;
	}

	Point* operator->() const
	{
		return posptr;
	}

	~SmartPtr() {
		delete posptr;
		// 생성자에 가져온 주소값이 new라는 가정 하에 delete해주는것 이다.
	}

	// 가장 기본적인건 포인터 연산자 오버로딩을 하여야 한다.
private:
	Point* posptr; // 객체 포인터를 받아온다.
};

int main()
{
	Point* ptr = new Point; // 원래 이렇게 해야 새로운 데이터를 생성할 수 있지만,

	SmartPtr sptr1(new Point(1, 2));
	SmartPtr sptr2(new Point(2, 3));
	SmartPtr sptr3(new Point(4, 5));

	cout << *sptr1;
	cout << *sptr2;
	cout << *sptr3;

	sptr1->SetPos(10, 20);
	// 원래 할당 해주어야 하지만, delete를 자동으로 해주기 때문에 상관없다.
	return 0;
}