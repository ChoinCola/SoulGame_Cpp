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
	
	// �����ڸ� ó�������°� �� �ƴ� ���� ���ƹ�����.
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

	Fraction frac4('A'); // int������ �ڵ� ����ȯ�� �Ͼ�� int������ ����.
	Fraction frac5(3.14f); // flaot���� int�� �ٲ��.

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