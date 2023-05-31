#include <iostream>
#include "02_myArray.h"
#include "02_myArray.inl"
using namespace std;

int main()
{
	myArray<int> myArr(10);

	myArr.Print();

	return 0;
}