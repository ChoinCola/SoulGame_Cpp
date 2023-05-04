#include <iostream>

using namespace std;

class Point
{
	int xpos, ypos;

public:
	Point(int x = 0, int y = 0) : xpos(x), ypos(y)
	{}

	friend ostream& operator <<(ostream& os, const Point& pos)
	{
		os << "[" << pos.xpos << ", " << pos.ypos << "]" << endl;
		return os;
	}

	void* operator new(size_t size)
	{
		void* adr = new char[size];
		return adr;
	} // 그냥 공간을 잡아주는 역활.

	void operator delete (void* adr)
	{
		delete[] adr;
	}
};

int main()
{
	// new 는 항상 생성자를 실행하면서 만들게된다.

	Point* ptr = new Point(3, 4); // static 인지 아닌지 알 수 없지만, new 가 함수 오버로딩 형태로 동작하게 된다.


	return 0;
}