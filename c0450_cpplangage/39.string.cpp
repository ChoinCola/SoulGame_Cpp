#include <iostream>
#include <string>
using namespace std;



int main()
{
	char myStr[] = "Hello C";
	// C������ ���ڿ��� �迭�� �ϳ��ϳ� �����Ͽ� ������ �����Ͽ���.
	//char* myStr2 = "Hello C"; // c�� ��쿡�� ����� �Ǵ� ����̴�.
	// ������ �ϸ� ���ڿ��� ������ �� ���� ������, readonly �޸� �̱� ������, �����ϰ� const�� �ٿ���
	// C++���� ����� �����ϴ�.
	const char* myStr2 = "Hello C";

	string str = "Hello c++";

	cout << str.size() << endl; // ������ ������
	cout << str.length() << endl; // ���ڿ��� ������

	string a("Hello, ");
	string b("C++!!");

	string C = a + b; // ������ �ٿ��� ���̴� ������ �����ϴ�.

	cout << C << endl;
	C += ", good!!"; // ������ ���� ���� ���� �����ϴ�.
	cout << C << endl;

	cout << C[4] << endl; // �迭ó�� ���� ����� �����ϴ�. �̿Ͱ��� ����ϸ� 1���� 4������ 5��° ���ڰ� ��µȴ�.

	return 0;
}