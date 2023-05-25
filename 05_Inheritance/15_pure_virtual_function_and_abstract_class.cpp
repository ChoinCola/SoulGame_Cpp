#include <iostream>

// pure_virtual_function

// abstract_class ��������ȭ class

// Interface ����� ������ ���� ����� �߻��� ����

// ��������� �˸��� ���� ��κ� i�� �ٿ��� ����ϴ� ��찡 ����.

using namespace std;

#pragma region abstract class
//class animal abstract // �߻�Ŭ������ ���鶧��  ���� abstract ���δ�.
//{
//	string name;
//
//public:
//	animal(const string& name) : name(name) {}
//
//	auto getname()const { return name; }
//
//	virtual void sleep() const final
//	{
//		cout << "sleep" << endl;
//	} // ����� Ư���̱� ������ ���� vitrual�� ���� �ʿ䰡 ������, ��ΰ� ����ǰ� sleep�Ұ� �̱� ������, final�� �����ش�.
//
//	virtual void speak() const abstract = 0;
//};
//
//class cat : public animal
//{
//public:
//	cat(string name) : animal(name) {}
//
//	void speak() const { cout << "�߿�" << endl; }
//};
//
//class dog : public animal
//{
//public:
//	dog(string name) : animal(name) {}
//
//	void speak() const { cout << "�۸�" << endl; }
//};
//
//class fox : public animal
//{
//public:
//	fox(string name) : animal(name) {}
//};
//
//int main()
//{
//	//animal ani("asdfa"); // �����Լ��� ��üȭ �Ұ� ������ ��Ÿ����.
//
//	cat c("cc");
//	dog d("dd");
//	//fox f("ff"); // ����ȭ�Լ��� �ν��Ͻ�ȭ ������ �ʾұ� ������ ����� �� ����.
//
//	c.sleep();
//	d.sleep();
//	c.speak();
//	d.speak();
//	return 0;
//}
#pragma endregion

#pragma region Interface
class IErrorLog // ���� �����Լ��θ� �̷���� �������̽� �̴�.
{
public:
	virtual ~IErrorLog() = default;
	virtual bool ReportError(const char* const error) abstract; // ���� ����ȭ ����
};

class FileErrorlog : public IErrorLog
{
public:
	virtual bool ReportError(const char* const error) override
	{
		cout << "writting error to a file" << endl;
		return true;
	}
};

class ConsoleErrorlog : public IErrorLog
{
public:
	virtual bool ReportError(const char* const error) override
	{
		cout << "Console error to a input" << endl;
		return true;
	}
};

void DoSomething(IErrorLog& log)
{
	log.ReportError("Error");
}

int main()
{
	//IErrorLog f;
	FileErrorlog fileLog;
	ConsoleErrorlog consoleLog;

	DoSomething(fileLog);
	DoSomething(consoleLog);
	return 0;
}
#pragma endregion

/*

	å �θ�Ŭ����
	- ����å, ebook �� ��ӹ޾Ƽ� ��

	å �̸�, å ��ȣ, å ���� ����Լ� ��
	ebook�� ��쿣 �Ǹ� ����Ʈ ��� �Լ�

	����å�� ��� 5�� �̻� ���������, å���� �� á���ϴ�. ���

*/