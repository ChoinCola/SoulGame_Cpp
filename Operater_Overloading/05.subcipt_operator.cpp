#include <iostream>
// 첨자 연산자 []
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
	// 범위를 벗어나나, 경계검사를 하지 않기 때문에 컴파일은 된다. 이래서 버그를 잡기 힘들 수 있다.
	// 이러한 것을 막기 위해 배열을 class로 만들어서 많이 사용한다.

	IntArray list;

	//list.Set(0, 1);
	//list.Set(1, 2);
	//list.Set(2, 3);
	//// 이렇게 만들면 매우 불편해진다. 이걸 생성자로 다시 만들어보자.

	//auto arr = list.GetList();
	//// 단, 이렇게 사용하면 배열의 최대 사이즈를 알 수 없기 때문에, 접근오류가 날 수 있다.
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