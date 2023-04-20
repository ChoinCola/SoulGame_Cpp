#include <iostream>
#include <cstdarg>

using namespace std;
// �����Լ�

double fineAverage(int count, ...) // �������� �Լ�.
{
	double sum = 0;

	va_list lists;
	va_start(lists, count); // ������ ���������� ��ü������ ����Ʈ�� �־ ���ۺκ��� ������.

	for (int arg = 0; arg < count; arg++) {
		sum += va_arg(lists, int);
	}

	va_end(lists); // ������ �������ڸ� ���� ����Ʈ�� free���ش�.

	return sum / count;
}

int main()
{
	cout << fineAverage(3, 1, 2, 3) << endl;
	cout << fineAverage(5, 1, 2, 3, 4, 5) << endl;
	cout << fineAverage(3, 1, 2, 3, 4, 5) << endl; // ī��Ʈ ���� �°� �ش�Ǵ� �����͸� ����� ����ȴٴ°� �� �� �ִ�.

	return 0;
}