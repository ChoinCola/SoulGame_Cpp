#include <iostream>

using namespace std;

/*
	. .* :: ?: # ## ���� ������
	�̷��� �����ڸ� ������ ���� ��� �����ε��� �����ϴ�.

	& �Ѵ� 1�� ���� �� 1111 1001 -> 1001
	| �Ѵ� 0�� ���� �� 1111 1001 -> 0000 
	^ ���� �ٸ� ���� 1 1111 1001 -> 0110 
	���� �����ڴ� �ʹ� ������ ���Ƽ� ���� �����ε��� ó�� �ؾ��Ѵ�.
*/

class Number
{
public:
	Number(int num)
		:num(num)
	{}

	void SetNum(int num)
	{
		this->num = num;
	}
	int GetNum() {
		return num;
	}

	auto operator+(Number& def) -> Number&
	{
		this->num + def.num;
		return *this;
	}

private:
	int num;
};

int main()
{
	Number a(10), b(20);

	//int result = a + b;

	int result = a.GetNum() + b.GetNum();
	a.SetNum(result);

	Number c = a + b;
	// ���� ������ �ùٸ��� �ҷ��� 40��° ���� �´� �����̴�.
	// �׷���, �̷��� �����ڸ� �����Ϸ��� �ʹ� �����ϰ� Get�� Set�� ��ü�������� �ڵ��� ����� �ȴ�.
	// �׶� ����ϴ� �� �� ������ �����ε��̴�.

	return 0;
}