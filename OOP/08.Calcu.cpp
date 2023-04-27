#include "08.Calcu.h"

Calcu::Calcu(int value) : value(value) {}

Calcu& Calcu::Add(int value) // inline 이 선언된 것과 같은 경우이다. 일반적인 함수에 비해 실행속도게 더 이득이 있는것.
// 함수가 호출되면 정의구바 그대로 들어감. 일반적인 함수에 비해 호출속도에 지연이 없다.
// 요즘 컴파일러는 함수의 코드가 적을 경우, 자동으로 inline화 시켜버린다. 그래서 자동으로 inline화 되는경우가 많다.
{
	{ this->value += value; return *this; }
	// TODO: 여기에 return 문을 삽입합니다.
}

Calcu& Calcu::Sub(int value)
{
	{ this->value -= value; return *this; }
	// TODO: 여기에 return 문을 삽입합니다.
}

Calcu& Calcu::Mul(int value)
{
	{ this->value *= value; return *this; }
	// TODO: 여기에 return 문을 삽입합니다.
}

Calcu& Calcu::Div(int value)
{
	{ this->value /= value; return *this; }
	// TODO: 여기에 return 문을 삽입합니다.
}

Calcu& Calcu::Mod(int value)
{
	{ this->value %= value; return *this; }
	// TODO: 여기에 return 문을 삽입합니다.
}
	