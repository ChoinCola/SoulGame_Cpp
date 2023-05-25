#include <iostream>

using namespace std;

class Vehicle abstract
{
	static int count;
public:
	Vehicle() {
		count++; 
		if (getCount() > 5) 
		{ cout << "�̵����� ��ü ���� 5�� �ʰ�" << endl; }
	}

	virtual void movement() abstract;
	virtual ~Vehicle() { count--; }
	static int getCount() { return count; }

};
int Vehicle::count = 0;

class airplane : public Vehicle
{
public:
	airplane() : Vehicle() {}

	void movement() { cout << "����� �̵�" << endl; }
};

class ship : public Vehicle
{
public:
	ship() : Vehicle() {}

	void movement() { cout << "���� �̵�" << endl; }
};

class car : public Vehicle
{
public:
	car() : Vehicle() {}

	void movement() { cout << "���� �̵�" << endl; }
};

int main()
{
	// Vehicle v;

	ship sh;
	airplane air;
	car car1;
	car car2;
	//car car3;
	//car car4;

	sh.movement();
	air.movement();
	car1.movement();
	//car2.movement();
	//car3.movement();
	//car4.movement();
	return 0;
}