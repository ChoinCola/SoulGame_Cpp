#pragma once
#include <iostream>

template <class T>
class myArray
{
public:
	myArray(int length)
		: length(length)
	{
		arr = new T[length];
	}
	~myArray()
	{
		delete[] arr;
	}
	void Print();

private:
	T* arr = nullptr;
	int length = 0;
};

