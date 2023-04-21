#include <iostream>
// ������. 
using namespace std;

class Fraction
{
public:
	Fraction() { // ������. ��ü�� �����Ǹ� �ڵ����� ����ȴ�.
		cout << "Constructor!" << endl;
	}
	Fraction(int a, int b) // �ٸ� �����ڸ� ����� �Ǹ� ���� �����ڴ� ���õȴ�.
	{
		cout << "Constructor2!" << endl;
	}// �� ���� �Լ� �����ε��� �����Ͽ� ������ ������ �����ϴ�.

	Fraction(const Fraction& data) // ���� ������. �ڽ��� �״�� �����Ͽ� �ٽ� �缱�� �� �� �ִ�.
	{ // �ܺ� ������ ���� ���, �ܺο����� �޾ƿ;� �ϱ� ������, const�� ����Ѵ�.
		cout << "COnstructor3!!" << endl;
	}
	Fraction(Fraction&& data) noexcept// �̵� ������. ���� �״�θ� �������� ������
	{ // const���� �ϸ� �ȵȴ�.
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