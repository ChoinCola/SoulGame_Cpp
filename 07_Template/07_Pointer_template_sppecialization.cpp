#include <iostream>

using namespace std;

template<class T>
class A
{
	T value;
public:
	A(const T& value) : value(value) {}
	void Print()
	{
		cout << value << endl;
	}
};

template<class T>
class A<T*>
{
	T* value;
public:
	A(T* value) : value(value) {}
	void Print()
	{
		cout << *value << endl;
	}
};

int main()
{
	A<int> Aint(123);
	Aint.Print();

	int temp = 456;
	A<int*> Aptr(&temp);
	Aptr.Print();
	return 0;
}