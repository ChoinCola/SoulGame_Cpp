#include <iostream>

using namespace std;
// 범위 기반 for문
int main()
{
	int finbonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	for (int i = 0; i < sizeof(finbonacci) / sizeof(int); i++)
		cout << finbonacci[i] << endl;

	for (const auto& number : finbonacci)
		cout << number << endl;

	for (const auto& number : { 0,1,1,2,3,5,8,13,21,34,55,89 })
		cout << number << endl;
	// 배열의 전체범위를 단순순환 시키는데 사용할 수 있다.
	int* test = new int[10];
	//for (auto t : test); // 범위가 없기 때문에 이것과 같이 접근은 안된다.
	
	return 0;
}