#include <iostream>

using namespace std;

struct person
{
	void Print() {
		cout << age << endl;
	} // ���� �׳� void Print() �� �ᵵ ���Ͱ��� ���� ���ִ°� �� ���ٰ� �� �� �ִ�.


	void __thiscall Print(/* person* */) {
		cout << age << endl;
	} // ���� �׳� void Print() �� �ᵵ ���Ͱ��� ���� ���ִ°� �� ���ٰ� �� �� �ִ�.

	int age;
	float weight = 50.0f;
	string name = "Jiwon";
};

int main()
{
	person p1;
	// person::Print(); �δ� ������ �� �� ����. ����ü�� �޸� �ȿ� ������ �ʱ� ����,
	p1.Print();
	//ȣ���� �����ϴ�.
	return 0;
}

/*
	�Լ� ȣ�� �Ծ�(function calling convension) �˾ƺ���
*/