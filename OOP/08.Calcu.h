#pragma once
class Calcu
{
	int value;

public:
	Calcu(int value);

	Calcu& Add(int value);// �������� ��ȯ�ϰ� �ȴ�. ���� �޸� ��ü�� �����ϴ°�.
	Calcu& Sub(int value);// �����̶�� �����ϸ� �ȴ�.
	Calcu& Mul(int value);
	Calcu& Div(int value);
	Calcu& Mod(int value);
};

