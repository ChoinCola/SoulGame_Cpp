#include <iostream>

using namespace std;

/*
	다이아몬드 상속 문제
	A
   / \
  B   C
   \ /
    D

	class A {};
	class B : public A {};
	class C : public A {};
	class D : pulbic B, public C {};

	위와같이 상속이 되면, D는 B와 C중 어떤걸 사용해야 할 지 알수가 없어져서 모호성 문제가 발생함.
*/

class PoweredDevice
{
public:
	PoweredDevice(int power) { cout << "PowerdDevice" << power << endl; }
	int i;
};

class Scanner : virtual public PoweredDevice
{
public:
	Scanner(int scanner, int power)
		: PoweredDevice(power)
	{
		cout << "Scanner : " << scanner << endl;
	}
};

class Printer : virtual public PoweredDevice
{
public:
	Printer(int printer, int power)
		: PoweredDevice(power)
	{
		cout << "Printer : " << printer << endl;
	}
};

class Copier : public Scanner, public Printer
{
public:
	Copier(int scanner, int printer, int power1, int power2, int power3)
		: Scanner(scanner, power1)
		, Printer(printer, power2)
		, PoweredDevice(power3)
	{}
};

int main()
{
	Copier copier(1, 2, 3, 4, 5);

	cout << &copier.Scanner::PoweredDevice::i << endl;
	cout << &copier.Printer::PoweredDevice::i << endl;

	copier.i; // abiguous 모호성 문제가 생겨난다.
	// 이걸 막기 위해 virtual을 사용해서 가상상속을 해줄 수 있다.
	return 0;
}