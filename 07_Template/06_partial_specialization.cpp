#include<iostream>

using namespace std;
// 부분만 특수화 시키고 싶을 때 사용한다.
// 함수에 대한 부분 특수화를 진행한다.
#pragma region 1.일반 함수 부분 특수화
//template<class T, int size>
//class StaticArray
//{
//	T arr[size];
//
//public:
//	T* GetArray() { return arr; }
//
//	T& operator[](int index)
//	{
//		return arr[index];
//	}
//
//	void Print1()
//	{
//		for (int i = 0; i < size; i++)
//		{
//			cout << (*this)[i] << ' ';
//		}
//		cout << endl;
//	}
//};
//
//template<typename T, int size>
//void Print2(StaticArray<T, size>& arr)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i] << ' ';
//	}
//	cout << endl;
//}
//
//template<int size>
//void Print2(StaticArray<char, size>& arr)
//{
//	for (int i = 0; i < size; i++)
//	{
//		cout << arr[i];
//	}
//	cout << endl;
//}
#pragma endregion
#pragma region 2.클래스 멤버 함수 부분 특수화
template<class T, int size>
class StaticArray_Base
{
	T arr[size];

public:
	T* GetArray() { return arr; }

	T& operator[](int index)
	{
		return arr[index];
	}

	virtual void Print1()
	{
		for (int i = 0; i < size; i++)
		{
			cout << (*this)[i] << ' ';
		}
		cout << endl;
	}
};

template<class T, int size>
class StaticArray : public StaticArray_Base<T, size>
{

};

template<int size>
class StaticArray<char, size> : public StaticArray_Base<char, size>
{
public:
	void Print1() override
	{
		for (int i = 0; i < size; i++)
		{
			cout << (*this)[i];
		}
		cout << endl;
	}
};
#pragma endregion
int main()
{
	StaticArray<int, 4> int4;
	int4[0] = 1;
	int4[1] = 2;
	int4[2] = 3;
	int4[3] = 4;

	int4.Print1();
	//Print2(int4);

	StaticArray<char, 6> char6;
	char6[0] = 'H';
	char6[1] = 'E';
	char6[2] = 'L';
	char6[3] = 'L';
	char6[4] = 'O';
	char6[5] = '\n';

	char6.Print1();
	//Print2(char6);

	return 0;
}