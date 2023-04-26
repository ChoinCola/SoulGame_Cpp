#pragma once
class Calcu
{
	int value;

public:
	Calcu(int value);

	Calcu& Add(int value);// 참조값을 반환하게 된다. 나의 메모리 자체를 접근하는것.
	Calcu& Sub(int value);// 응용이라고 생각하면 된다.
	Calcu& Mul(int value);
	Calcu& Div(int value);
	Calcu& Mod(int value);
};

