#include <iostream>

using namespace std;

// 
// 
// ������ 
//		�����ε�  : ���� �Լ��̸��� ���� ����ϴ°�.
//		�������̵� : �θ�Ŭ���� ���� ������ �ڽ�Ŭ�������� �������ϴ°�

// �θ�Ŭ������ �ڽ�Ŭ������ å�̶�� ������ �ڽ��̶�� å ������ �ִ°�.

class Mother
{
private:
	int a;
	// ��ӵǾ private�� �����޾� ����� �� ���Եȴ�.
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
	// ���⼭ ��������� �ֵ��� �ڽİ� �� Ŭ���������� ����� �� �ִ�.
};

class Chiled : public Mother
{
	int b;
	// �ڽİ� �θ� ��ģ�ٸ�, �ڽ��� ���� ���� �켱�õȴ�.
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
	// Mohter�� �������� �ʾƵ� Mother�� �Լ��� ����� �� �ִ�.
	return 0;
}