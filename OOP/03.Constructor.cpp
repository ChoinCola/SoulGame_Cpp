#include <iostream>
// 생산자. 
using namespace std;

class Fraction
{
public:
	Fraction() { // 생성자. 객체가 생성되면 자동으로 실행된다.
		cout << "Constructor!" << endl;
	}
	Fraction(int a, int b) // 다른 생성자를 만들게 되면 기존 생성자는 무시된다.
	{
		cout << "Constructor2!" << endl;
	}// 이 또한 함수 오버로딩이 가능하여 여러개 생성이 가능하다.

	Fraction(const Fraction& data) // 복사 생성자. 자신을 그대로 복사하여 다시 재선언 할 수 있다.
	{ // 외부 원본이 있을 경우, 외부원본을 받아와야 하기 때문에, const를 사용한다.
		cout << "COnstructor3!!" << endl;
	}
	Fraction(Fraction&& data) noexcept// 이동 생성자. 원본 그대로를 가져오기 때문에
	{ // const선언 하면 안된다.
		cout << "Constructor4!!" << endl;
	}
private:
	int numerator = 10;
	int denominator = 10;

};

int main()
{
	Fraction frac;
	Fraction frac1(1, 2); 
	Fraction frac11(1.0, 3);
	//fraction frac111{ 1.0, 3 };

	Fraction frac2(frac1);

	Fraction frac3(std::move(frac1));

	return 0;
}