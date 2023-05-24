#include <iostream>

// pure_virtual_function

// abstract_class ��������ȭ class

// Interface ����� ������ ���� ����� �߻��� ����

// ��������� �˸��� ���� ��κ� i�� �ٿ��� ����ϴ� ��찡 ����.

using namespace std;

class animal abstract // �߻�Ŭ������ ���鶧��  ���� abstract ���δ�.
{
	string name;

public:
	animal(const string& name) : name(name) {}

	auto getname()const { return name; }

	virtual void sleep() const final
	{
		cout << "sleep" << endl;
	} // ����� Ư���̱� ������ ���� vitrual�� ���� �ʿ䰡 ������, ��ΰ� ����ǰ� sleep�Ұ� �̱� ������, final�� �����ش�.

	virtual void speak() const abstract = 0;
};

class cat : public animal
{
public:
	cat(string name) : animal(name) {}

	void speak() const { cout << "�߿�" << endl; }
};

class dog : public animal
{
public:
	dog(string name) : animal(name) {}

	void speak() const { cout << "�۸�" << endl; }
};

class fox : public animal
{
public:
	fox(string name) : animal(name) {}
};

int main()
{
	//animal ani("asdfa"); // �����Լ��� ��üȭ �Ұ� ������ ��Ÿ����.

	cat c("cc");
	dog d("dd");
	//fox f("ff"); // ����ȭ�Լ��� �ν��Ͻ�ȭ ������ �ʾұ� ������ ����� �� ����.

	c.sleep();
	d.sleep();

	c.speak();
	d.speak();
	return 0;
}