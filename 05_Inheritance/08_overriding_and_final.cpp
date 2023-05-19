#include <iostream>

using namespace std;

class A //final
	// final = 클래스를 상속시킬 수 없게 제한하는 키워드 이다. 이걸 붙이면 
	// 나는 더이상 이 함수를 상속하지 않겠다. 라는 의미이다.
{
public:
	virtual void Print(int x) { cout << "A" << endl; }
	// virtual = 가상함수 라는 의미로, 하위클레스에서 이 함수를 재정의 해줄 수 있음을 명시해주는 것.

	int i = 0;
};

class B /*final*/ : public A
	// B옆에 붙이면, B를 이후에 상속시키지 않겠다. 라는 의미.
{
public:
	void Print(int x) override /*final*/ { cout << "B" << endl; }
	// override 는 이 함수가 부모의 함수를 덮어씌워즈는 역활 이라는 것 을 명시해주는것.

	// 이때 인자값 과 반환형은 언제나 같아야 한다.
	// 함수에 final을 붙이면, 함수 한정해서 상속을 시키지 않을 수 있다.
};

class C : public B
{
public:
	void Print(int x) override { cout << "C" << endl; }
};

int main()
{
	A a;
	B b;
	C c;

	a.Print(1);
	b.Print(2);
	c.Print(3);

	A* aptr = new B();
	// B* bptr = aptr;

	B* bb = new B();
	A* aa = bb; // A포인터가 B를 가리킬때 A것이 출력되고 B가 출력되지 않는다.
	// 이는 오버라이딩 기준이 호출자 기준으로 정해지기 때문이다.

	return 0;
}