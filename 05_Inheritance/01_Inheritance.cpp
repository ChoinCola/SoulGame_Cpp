#include <iostream>

using namespace std;

// 
// 
// 다형성 
//		오버로딩  : 같은 함수이름을 같이 사용하는것.
//		오버라이딩 : 부모클레스 에서 받은걸 자식클레스에서 재정의하는것

// 부모클래스와 자식클래스로 책이라는 묶음에 자식이라는 책 내용이 있는격.

class Mother
{
private:
	int a;
	// 상속되어도 private은 물려받아 사용할 수 없게된다.
public:

	auto GetA() const
	{
		cout << "Mother" << endl;
		return a;
	}
	void SetA(const int& a) { this->a = a; }
protected:
	int b;
	int c;
	// 여기서 만들어지는 애들은 자식과 내 클레스에서만 사용할 수 있다.
};

class Chiled : public Mother
{
	int b;
	// 자식과 부모가 겹친다면, 자식의 것이 먼저 우선시된다.
public:
	auto GetA() const
	{
		c;
		b; // chiled
		Mother::b; // Mother

		cout << "chiled" << endl;
		return Mother::GetA();
	}
};
int main()
{
	Chiled c;

	c.SetA(1);
	c.GetA();
	c.Mother::GetA();
	// Mohter이 생성되지 않아도 Mother의 함수를 사용할 수 있다.
	return 0;
}