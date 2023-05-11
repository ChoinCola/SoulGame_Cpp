#include <iostream>

using namespace std;

class Test
{
	int num1;
	int num2;

public:
	// 클래스가 만들어졌을 때 기본으로 들어가는 것
	// 기본
	// 복사
	// 이동
	// 복사 대입
	// 이동 대입
	// 소멸
	
	// 기본생성자. 로 취급되어 기본생성자는 사라진다.
	/*Test(int n1, int n2) : num1(n1), num2(n2)
	{}*/

	
	Test(int n1, int n2) : num1(n1), num2(n2)
	{}
};

class Fraction
{
	int numerator;
	int denominator;
public:
	Fraction(int num = 0, int den = 0)
		: numerator(num), denominator(den)
	{
		cout << "constructor" << endl;
	}
	
	// 복사 연산자
	// 이건 임의적으로 동작을 막는 것 이다.
	/*explicit*/ Fraction(const Fraction& fraction)
	{
		cout << "copy constructor" << endl;
	}

	// 복사 대입 연산자
	Fraction& operator = (const Fraction& rhs)
	{
		cout << "copy assignment operator" << endl;
		return *this;
	}
};

Fraction CreateFraction()// 이름 있는 객체
{
	Fraction temp(5, 2);
	return temp;
}

int main()
{
	Test t1(1, 2);
	Test t2 = t1; // 이럴경우 복사생성자가 된다.
	// 아무것도 넣지 않았을 때 디폴트 복사생성자가 들어가서 생성되게 된다.

	Fraction frac(3, 5);
	Fraction copy1(frac); // 복사 생성자. 복사 초기화
	Fraction copy2 = frac; // 복사 생성자.

	copy2 = frac; // = operator= 이다. 복사대입 생성자.

	int a = 5; // 복사
	int b = a; // 복사 대입연산자.

	int a(5); // 복사 초기화는 이와 같다.

	CreateFraction();

	return 0;
}