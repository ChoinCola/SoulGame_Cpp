#include <iostream>

using namespace std;

auto add(int x, int y) -> int; // ���� ��ȯŸ�� ������, �˾ƺ��� ������ ���� ����Ѵ�. int�� auto�Ѵٴ� �ǹ��̴�.

int main()
{
	int a = 10;
	float b = 3.14f;
	double c = 45.0;

	//float result = a + b;
	// ������ ���ϸ� �˾Ƽ� Ÿ���� �����ؼ� int�� float�� �ٲ� �� �������� ��µȴ�.

	auto result = a + b;
	// �� ������ �����ϸ� a �� b�� �� ���� �� ���� ������ ���� ������ ���·� ��ȯ�ؼ� ������ش�.
	// float�� ���� �������� float ���� ��ȯ�Ͽ� �����.




	return 0;
}

auto add(int x, int y) -> int
// �ް������� auto�� �� �� ����. �̴� ������ ���� �ڵ����� Ÿ���� ��ȯ�� �� ���� �����̴�.
{
	return x + y;
}
