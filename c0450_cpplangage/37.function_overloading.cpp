#include <iostream>

int add(int a, int b) { return a + b; }
// C++������ �Լ��� �̸��� �ߺ��Ͽ� ����ϴ°��� �����ϴ�.
float add(float a, float b) { return a + b; }
// �׷���, �Ű������� �ٸ��� ����Ͽ� �����ؾ߸� �Ѵ�.
int add(int a) { return a + 1; }
int add(int a, int b, int c) { return a + b + c; }
// ������ ������ �ٸ��� ������ ���� ���� ��� ���� �����ϴ�.

// c���� �Լ��� �̸��� �߽����� ã�´�.
// c++�� ��ü���� �̱� ������ �Լ��� �̸��� �ƴ� �Լ��� �μ��� �������� ã�´�. �׷��� �Լ��� �̸���
// ��ø�Ǿ �����Ѵ�.

using integer = int;
// integer add(integer a, integer b) { return a + b; } �� �Ұ����ϴ�. �����Ϸ��� ���⿡�� 3���� ���� ���� ����,
using namespace std;

void output(int value) {}
void output(unsigned int value) {}
void output(float value) {}

int main()
{
	auto result1 = add(10, 20);
	auto result2 = add(10.1f, 20.1f);
	auto result2 = add(10, 20, 30);
	// add��� �Լ��� ���ϰ��� �پ������� auto�� ������ �������� �ʾƵ� �Ǳ� ������ �� ���ϴ�.

	output(1); // ��ȣ���� �߻��ߴ�.  int�� unsigned int�� �Ѵ� �ش�Ǳ� ����,
	output(1.0f); // ��ȣ���� �߻����� �ʴ´�, float�� ȣ���߱� ����,

	output('c'); // �ڱ�� ��ġ���� �ʴ� ������ ã�� ������ ���,���� ��ġ�ϴ� ������ ����ȯ�ϸ� ã�´�.
	// char, usigned char, short, int �̷� �� ����.
	

	return 0;
}