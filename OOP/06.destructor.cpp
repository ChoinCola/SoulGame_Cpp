#include <iostream>

using namespace std;

//소멸자. 소멸자는 동적할당된 메모리를 해제해주는 역활을 한다.

class Test
{
public:
	Test() // class가 시작될 때 자동으로 실행되는 함수
	{
		cout << "Constructor" << endl;
	}
	~Test() // class가 없어질 때 자동으로 실행되는 함수
	{
		cout << "Destructor" << endl;
	}
};

class IntArray
{
public:
	IntArray(const int& inLength)
	{
		length = inLength;
		arr = new int[length];
		cout << "constructor" << endl;
	}

	~IntArray()
	{
		delete[] arr;
		cout << "destructor" << endl;
	}

private:
	int* arr = nullptr;
	int length = 0;
};

int main()
{
	Test test1;

	cout << "####################1" << endl;
	{
		cout << "####################2" << endl;
		Test test2;
		cout << "####################3" << endl;
	}
	cout << "####################4" << endl;

	while (true)
	{
		IntArray myArr(1000);
	}

	return 0;
}