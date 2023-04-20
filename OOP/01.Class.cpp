#include <iostream>

using namespace std;

// Class의 선언방법은 구조체와 같다. Class로 묶는것 자체가 캡슐화 라고 할 수 있다.

typedef struct person
{
	string name;
	int age;
	float height;
	float wight;
	bool favorite;
};

class Person
{

	string name;
	int age;
	float height;
	float wight;
	bool favorite;

public: // 모두에게 공개를 한다 라는 뜻
	void work()
	{
	}

	void Sleep()
	{
	}
	

protected: // 나 자신만 사용할 수 있다는 뜻, Class 내부에서만 그 정보를 활용할 수 있다는것.

private: // 나와 자신의 자속클래스 에서만 사용이 가능하다는 뜻.
	// 위의 3가지는 전부 접근 지정자 라고 한다.

	
	
};

/*
	클래스는 접근지정자가 생략된다면 기본적으로 private로 지정된다.
	
	구조체와 클래스의 차이점은 기본제공의 차이가 있다.
	클래스 는 기본 private로 지정되고
	구조체는 기본적으로 public 으로 지정된다. 라는 차이가 있다.
	함수도 그냥 기본제공이 된다. struct는 내부함수를 한번 기본초기화 해야하지만,
	Class는 기본초기화를 해주지 않아도 자동으로 인식하여 초기화 해주는 장점이 있다.

*/
int main()
{
	Person p;
	person p1;

	p.Sleep();
	p1.favorite;


	return 0;
}