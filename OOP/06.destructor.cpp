#include <iostream>

using namespace std;

//�Ҹ���. �Ҹ��ڴ� �����Ҵ�� �޸𸮸� �������ִ� ��Ȱ�� �Ѵ�.

class Test
{
public:
	Test() // class�� ���۵� �� �ڵ����� ����Ǵ� �Լ�
	{
		cout << "Constructor" << endl;
	}
	~Test() // class�� ������ �� �ڵ����� ����Ǵ� �Լ�
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