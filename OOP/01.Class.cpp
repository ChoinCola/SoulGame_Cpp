#include <iostream>

using namespace std;

// Class�� �������� ����ü�� ����. Class�� ���°� ��ü�� ĸ��ȭ ��� �� �� �ִ�.

typedef struct person
{
	string name;
	int age;
	float height;
	float wight;
	bool favorite;
};

class Person
{

	string name;
	int age;
	float height;
	float wight;
	bool favorite;

public: // ��ο��� ������ �Ѵ� ��� ��
	void work()
	{
	}

	void Sleep()
	{
	}
	

protected: // �� �ڽŸ� ����� �� �ִٴ� ��, Class ���ο����� �� ������ Ȱ���� �� �ִٴ°�.

private: // ���� �ڽ��� �ڼ�Ŭ���� ������ ����� �����ϴٴ� ��.
	// ���� 3������ ���� ���� ������ ��� �Ѵ�.

	
	
};

/*
	Ŭ������ ���������ڰ� �����ȴٸ� �⺻������ private�� �����ȴ�.
	
	����ü�� Ŭ������ �������� �⺻������ ���̰� �ִ�.
	Ŭ���� �� �⺻ private�� �����ǰ�
	����ü�� �⺻������ public ���� �����ȴ�. ��� ���̰� �ִ�.
	�Լ��� �׳� �⺻������ �ȴ�. struct�� �����Լ��� �ѹ� �⺻�ʱ�ȭ �ؾ�������,
	Class�� �⺻�ʱ�ȭ�� ������ �ʾƵ� �ڵ����� �ν��Ͽ� �ʱ�ȭ ���ִ� ������ �ִ�.

*/
int main()
{
	Person p;
	person p1;

	p.Sleep();
	p1.favorite;


	return 0;
}