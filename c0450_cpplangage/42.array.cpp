#include <iostream>
#include <array>

int main()
{
	using namespace std;
	
	int arr1[] = { 1, 2, 3, 4, 5 }; // c에서 초기화 하는 방법
	int arr2[]{ 1, 2,3, 4, 5 }; // C++ 에서 추가된 초기화 방법
	// int arr3[](1,2,3,4,5); 는 막아놓았다.

	/*
		STL : Standard Template Libraries
	*/
	// 배열을 더 간단하게 STL을 사용하여 생성할 수 있다.

	//<> : templete
	std::array<int, 5> arr4; //int를 5개 가지는 array 생성
	array<int, 5> arr5{ 1,2,3,4,5 }; // 직접적으로 초기화하기

	cout << arr5[0] << endl; // 각각의 원소 접근 또한 가능하다.
	cout << arr5[1] << endl;
	cout << arr5.at(2) << endl; // 위의 [] 와 같은 방법으로 들어가지만, 예외처리를 하기때문에, 오류가 날 가능성이 더 적다.
	cout << arr5.at(3) << endl; // 범위를 벗어나기 때문에 접근을 못하게 막는다.
	cout << arr5.at(4) << endl;
	cout << arr5.size() << endl; // 배열의 사이즈를 측정할 수 있다.

	cout << arr5[5] << endl;
	cout << arr5.at(5) << endl; // 터트려서 막는다.


	return 0;
}