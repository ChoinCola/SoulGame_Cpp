#include <iostream>

using namespace std; 
// ���� ������. � Ư�� �ɹ� ������ �ٸ������� �ʱ�ȭ �ϰ� ���� �� ����Ѵ�.

class Student
{
public:
	Student(const int& id, const string& name)
		:id(id), name(name)
	{}

	Student(const string& name)
		:Student(0, name) // ���� ������. �Ѱ��� �ʱ�ȭ�ϴ� ����̴�.
	{}
private:
	int id;
	string name;
};

class Student2
{
public:
	Student2(const int& id, const string& name)
	{
		Initialize(id, name); // �پ��� ����� ����� �� ������, �� �Ѱ��� �����ϰ� ����ϴ°��� ������ �̴�.
	}
	void Initialize(const int& id, const string& name)
	{
		//TODO : ���߿� �ʱ�ȭ���ֱ� TODO�� �ּ��� �ٷ� �� �� �ְ� �ϸ�ũ�� �߰��ϴ°��̴�.

private:
	int id;
	string name;
};
int main()
{


	return 0;
}