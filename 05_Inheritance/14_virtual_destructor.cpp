#include <iostream>

using namespace std;

class Base
{
public:
	Base() { cout << "Base()" << endl; }
	virtual ~Base() { cout << "~Base()" << endl; }
	// 업케스팅 하게되면 자식클래스의 소멸자가 발생하지 않는다.
	// 그걸 방지하기 위해 소멸자에 vitrual을 넣어주는것 이 더 안전한 코딩이다.
};

class Derived : public Base
{
	int* arr = nullptr;

public:
	~Derived()
	{
		//TODO : 동적해제
		cout << "~Derived()" << endl;
	}
};

int main()
{
	Base b;
	Base* base = new Derived; // 업케스팅 해줌.
	// 업케스팅 하게되면 자식클래스의 소멸자가 발생하지 않음.
	delete base;

	return 0;
}