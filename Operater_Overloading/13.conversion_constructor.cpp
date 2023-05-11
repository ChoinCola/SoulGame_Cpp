#include <iostream>

using namespace std;

class Fraction
{
	int numerator;
	int denominator;

public:
	Fraction(int num, int den)
		: numerator(num), denominator(den)
	{
		cout << "constructor" << endl;
	}

	Fraction(const Fraction& other)
		:numerator(other.numerator), denominator(other.denominator)
	{
		cout << "copy constructor" << endl;
	}
	
	// 생성자를 처음에쓰는것 이 아닌 것을 막아버린다.
	explicit Fraction(int a)
		: numerator(a), denominator(1)
	{
		cout << "conversion constructor" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction frac)
	{
		cout << frac.numerator << " /" << frac.denominator << endl;
		return out;
	}
};

void PrintFraction(Fraction frac)
{
	cout << frac << endl;
}

int main()
{
	Fraction frac1(10, 20);
	Fraction frac2(frac1);

	Fraction frac3(1);

	Fraction frac4('A'); // int형으로 자동 형변환이 일어나서 int형으로 들어간다.
	Fraction frac5(3.14f); // flaot에서 int로 바뀐다.

	PrintFraction(frac1);
	PrintFraction(frac2);
	PrintFraction(frac3);
	PrintFraction(frac4);
	PrintFraction(frac5);

	//PrintFraction('A');
	//PrintFraction(3.14);
	//PrintFraction(100);

	return 0;
}