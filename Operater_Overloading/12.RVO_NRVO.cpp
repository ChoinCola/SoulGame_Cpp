#include <iostream>

/*
	RVO = Retrun Value Optimization
	생성할 때 이름없는 객체는 자동최적화. 복사가아니라 원본대입
	NRVO = Named Return Value Optimization
	이름있는 이름있는 객체를 RVO처럼 해주는것. 
	최적화 할때 사용하는 방법.

*/

using namespace std;

class Test
{
	int value1;
	int value2;

public:
	static int count;

	Test(int value)
		:value1(value),
		value2(count++) // 생성할 때마다 카운트를 넣어준다.
	{
		cout << "constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	Test(const Test& rhs)
		:value1(rhs.value1), value2(count++)
	{
		cout << "copy constructor : " << this->value1 << ", " << this->value2 << endl;
	}

	~Test()
	{
		cout << "destructor : " << this->value1 << ", " << this->value2 << endl;
	}
};

int Test::count = 1;

Test MakeRVO(int value)
{
	return Test(value);
	// 임시객체의 생성이 이루어지지 않고 그냥 반환만된다.
}

Test MakeNRVO(int value)
{
	Test test(value);
	return test;
	// 임시객체의 생성이 이루어지고 반환된다. 복사생성자가 호출된다.
}

int main()
{
	cout << "---RVO---" << endl;
	Test t1 = MakeRVO(1);

	cout << "---NRVO---" << endl;
	Test t2 = MakeNRVO(1);
	// 컴파일러 에서만 이러한 현상이 나타나고, 릴리즈에서는 나타나지 않는다.
	return 0;
}