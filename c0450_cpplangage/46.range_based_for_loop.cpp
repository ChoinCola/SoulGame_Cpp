#include <iostream>

using namespace std;
// ���� ��� for��
int main()
{
	int finbonacci[] = { 0,1,1,2,3,5,8,13,21,34,55,89 };

	for (int i = 0; i < sizeof(finbonacci) / sizeof(int); i++)
		cout << finbonacci[i] << endl;

	for (const auto& number : finbonacci)
		cout << number << endl;

	for (const auto& number : { 0,1,1,2,3,5,8,13,21,34,55,89 })
		cout << number << endl;
	// �迭�� ��ü������ �ܼ���ȯ ��Ű�µ� ����� �� �ִ�.
	int* test = new int[10];
	//for (auto t : test); // ������ ���� ������ �̰Ͱ� ���� ������ �ȵȴ�.
	
	return 0;
}