#include <iostream>

using namespace std;

#define PLUS(a, b) a + b
// define������ �Լ��� ��ũ�η� �����Ͽ� ����� �� �ִ�.
// ��ũ�� �Լ��� �����ϸ�, CODE �������� �Լ��� �����Ͽ� �����ϱ⿡ �� ���� ����ó���� �����ϴ�.

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
// �ִ밪�� ���ϴ� ��ũ�� �Լ�.
inline int max(int a, int b)
{
	return (a + b);
}

int main()
{
	cout << PLUS(1, 2) << endl;
	cout << PLUS(1, 2) * PLUS(1, 2) << endl;
	// �Լ��� ��ũ�η� ��ȯ�Ͽ� ����ϴ°��� ��ȣ�� ���� �ʾƼ�, 1 + 2 * 1 + 2 �� ���� ��µǱ⿡
	// 5�� ��Ÿ���� �ȴ�.

	cout << (PLUS(1, 2)) * (PLUS(1, 2)) << endl;
	// ���� ���� ��� 9 �� ��Ÿ����.
	cout << MAX(1, 2) << endl;

	return 0;
}