#include "08.Calcu.h"

Calcu::Calcu(int value) : value(value) {}

Calcu& Calcu::Add(int value) // inline �� ����� �Ͱ� ���� ����̴�. �Ϲ����� �Լ��� ���� ����ӵ��� �� �̵��� �ִ°�.
// �Լ��� ȣ��Ǹ� ���Ǳ��� �״�� ��. �Ϲ����� �Լ��� ���� ȣ��ӵ��� ������ ����.
// ���� �����Ϸ��� �Լ��� �ڵ尡 ���� ���, �ڵ����� inlineȭ ���ѹ�����. �׷��� �ڵ����� inlineȭ �Ǵ°�찡 ����.
{
	{ this->value += value; return *this; }
	// TODO: ���⿡ return ���� �����մϴ�.
}

Calcu& Calcu::Sub(int value)
{
	{ this->value -= value; return *this; }
	// TODO: ���⿡ return ���� �����մϴ�.
}

Calcu& Calcu::Mul(int value)
{
	{ this->value *= value; return *this; }
	// TODO: ���⿡ return ���� �����մϴ�.
}

Calcu& Calcu::Div(int value)
{
	{ this->value /= value; return *this; }
	// TODO: ���⿡ return ���� �����մϴ�.
}

Calcu& Calcu::Mod(int value)
{
	{ this->value %= value; return *this; }
	// TODO: ���⿡ return ���� �����մϴ�.
}
	