#include <iostream>

using namespace std;
// 클래스를 인스턴스화 하지 않고 그냥 사용하려고 할 때

class A
{
public:
	void print()
	{
		cout << "print" << endl;
	}
};

int main()
{
	A().print(); // 익명개체로 사용하는 법.

	return 0;
}