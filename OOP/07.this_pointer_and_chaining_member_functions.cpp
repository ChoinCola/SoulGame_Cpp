//#include <iostream>
//
//using namespace std;
//
///*
//	this pointer : ��ü �ڽ��� ����Ű�� �뵵�� ���Ǵ� ������
//	this �� �����͸� �����ִ� �ڵ� ��� �����ϸ�ȴ�.
//*/
//
//class Test
//{
//	int num;
//
//public:
//	Test(int n) : num(n)
//	{
//		cout << "num = " << num << endl;
//		cout << "num address : " << &num << endl;
//		cout << "this address : " << this << endl;
//	}
//
//	void ShowTestData()
//	{
//		cout << num << endl;
//	}
//
//	Test* GetThisPionter()
//	{
//		return this;
//	}
//};
//
//class Test2
//{
//	int a;
//	int b;
//	int c;
//
//public:
//	Test2() {}
//	~Test2() {}
//
//	auto GetA()
//	{
//		cout << this << endl;
//		return a;
//	}
//
//	//void SetA(const int& a) { a = a; } // �̷� ������δ� ����� �� ����. ��ȣ������
//	void SetA(const int& a) {this-> a = a; } // �ּҰ� ������ ����Ͽ�. ��ȣ�� ������ ��Ÿ���� �ʴ´�.
//};
//
//int main()
//{
//	Test t1(100);
//	Test* ptr1 = t1.GetThisPionter();
//	cout << ptr1 << endl;
//	ptr1->ShowTestData();
//
//	Test t2(200);
//	Test* ptr2 = t2.GetThisPionter();
//	cout << ptr2 << endl;
//	ptr2->ShowTestData();
//	return 0;
//}


#pragma region chaining member function
class Calc
{
	int value;

public:
	Calc(int value) : value(value) {}

	//void Add(int value) { this->value += value; }
	//void Sub(int value) { this->value -= value; }
	//void Mul(int value) { this->value *= value; }
	//void Div(int value) { this->value /= value; }
	//void Mod(int value) { this->value %= value; }
	// ���� ���۷��� ���·� ���Ͻ�Ű�°�. ���� �ڱ� �ڽ��� �Ǵ°��̴�.

	Calc& Add(int value) { this->value += value; return *this; } // �������� ��ȯ�ϰ� �ȴ�. ���� �޸� ��ü�� �����ϴ°�.
	Calc& Sub(int value) { this->value += value; return *this; } // �����̶�� �����ϸ� �ȴ�.
	Calc& Mul(int value) { this->value += value; return *this; }
	Calc& Div(int value) { this->value += value; return *this; }
	Calc& Mod(int value) { this->value += value; return *this; }




};

int main()
{
	Calc calc(10);
	calc.Add(5);
	calc.Div(2);

	//ananimous object
	Calc(20).Add(1).Add(2);
	cout << "a" << "b" << "c" << "d" << "e" << endl; // ü���� �� ��������� �ʴ´�.

	return 0;
}

#pragma endregion

// ȭ��ǥ Ÿ�̹� ���� �����. �ð����� ĭ�� ���ݾ� �޾�����, ȭ��ǥ�� �ð��ȿ� ���� �������Ѵ�.