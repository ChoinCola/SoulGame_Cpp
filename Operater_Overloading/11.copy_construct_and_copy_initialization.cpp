#include <iostream>

using namespace std;

class Test
{
	int num1;
	int num2;

public:
	// Ŭ������ ��������� �� �⺻���� ���� ��
	// �⺻
	// ����
	// �̵�
	// ���� ����
	// �̵� ����
	// �Ҹ�
	
	// �⺻������. �� ��޵Ǿ� �⺻�����ڴ� �������.
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
	
	// ���� ������
	// �̰� ���������� ������ ���� �� �̴�.
	/*explicit*/ Fraction(const Fraction& fraction)
	{
		cout << "copy constructor" << endl;
	}

	// ���� ���� ������
	Fraction& operator = (const Fraction& rhs)
	{
		cout << "copy assignment operator" << endl;
		return *this;
	}
};

Fraction CreateFraction()// �̸� �ִ� ��ü
{
	Fraction temp(5, 2);
	return temp;
}

int main()
{
	Test t1(1, 2);
	Test t2 = t1; // �̷���� ��������ڰ� �ȴ�.
	// �ƹ��͵� ���� �ʾ��� �� ����Ʈ ��������ڰ� ���� �����ǰ� �ȴ�.

	Fraction frac(3, 5);
	Fraction copy1(frac); // ���� ������. ���� �ʱ�ȭ
	Fraction copy2 = frac; // ���� ������.

	copy2 = frac; // = operator= �̴�. ������� ������.

	int a = 5; // ����
	int b = a; // ���� ���Կ�����.

	int a(5); // ���� �ʱ�ȭ�� �̿� ����.

	CreateFraction();

	return 0;
}