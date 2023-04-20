#include <iostream>

using namespace std;

struct person
{
	void Print() {
		cout << age << endl;
	} // 원래 그냥 void Print() 만 써도 위와같은 값이 들어가있는것 과 같다고 볼 수 있다.


	void __thiscall Print(/* person* */) {
		cout << age << endl;
	} // 원래 그냥 void Print() 만 써도 위와같은 값이 들어가있는것 과 같다고 볼 수 있다.

	int age;
	float weight = 50.0f;
	string name = "Jiwon";
};

int main()
{
	person p1;
	// person::Print(); 로는 접근을 할 수 없다. 구조체의 메모리 안에 잡히지 않기 떄문,
	p1.Print();
	//호출이 가능하다.
	return 0;
}

/*
	함수 호출 규약(function calling convension) 알아보기
*/