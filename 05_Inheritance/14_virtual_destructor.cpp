#include <iostream>

using namespace std;

class Base
{
public:
	Base() { cout << "Base()" << endl; }
	virtual ~Base() { cout << "~Base()" << endl; }
	// ���ɽ��� �ϰԵǸ� �ڽ�Ŭ������ �Ҹ��ڰ� �߻����� �ʴ´�.
	// �װ� �����ϱ� ���� �Ҹ��ڿ� vitrual�� �־��ִ°� �� �� ������ �ڵ��̴�.
};

class Derived : public Base
{
	int* arr = nullptr;

public:
	~Derived()
	{
		//TODO : ��������
		cout << "~Derived()" << endl;
	}
};

int main()
{
	Base b;
	Base* base = new Derived; // ���ɽ��� ����.
	// ���ɽ��� �ϰԵǸ� �ڽ�Ŭ������ �Ҹ��ڰ� �߻����� ����.
	delete base;

	return 0;
}