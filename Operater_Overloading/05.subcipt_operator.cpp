#include <iostream>
// ÷�� ������ []
using namespace std;

class IntArray
{
	int list[3];

public:
	//int Get(int index) { return list[index]; }
	//void Set(int index, int value) { this->list[index] = value; }
	
	//int* GetList() { return list; }

	int& operator[] (int index)
	{
		if (index < 0 || index >= 10)
		{
			cout << "Array index out of bound exception" << endl;
		}

		return this->list[index];
	}

};

int main()
{
	int arr[3] = { 1, 2, 3 };
	cout << arr[-1] << endl;
	cout << arr[3] << endl;
	// ������ �����, ���˻縦 ���� �ʱ� ������ �������� �ȴ�. �̷��� ���׸� ��� ���� �� �ִ�.
	// �̷��� ���� ���� ���� �迭�� class�� ���� ���� ����Ѵ�.

	IntArray list;

	//list.Set(0, 1);
	//list.Set(1, 2);
	//list.Set(2, 3);
	//// �̷��� ����� �ſ� ����������. �̰� �����ڷ� �ٽ� ������.

	//auto arr = list.GetList();
	//// ��, �̷��� ����ϸ� �迭�� �ִ� ����� �� �� ���� ������, ���ٿ����� �� �� �ִ�.
	//arr[0] = 1;
	//arr[1] = 2;
	//arr[2] = 3;

	list[0] = 1;
	list[1] = 2;
	
	cout << list[0] << endl;
	cout << list[1] << endl;
	cout << list[20] << endl;

	return 0;
}