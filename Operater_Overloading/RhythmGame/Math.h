#pragma once

//TODO 여기에다가 선언 안해주어도됨.
class Math
{

public:
	static const int Random(const int& min, const int& max);
	static const float Random(const float& min, const float& max);
private:

	static std::random_device rd;
	static std::mt19937 mt;
	// static = 전역변수로 취급하여 선언되면 모든 함수에서 사용할 수 있다. 그러나
	// CLass에서 선언되어도 전역에서 초기화 해주어야 한다.
};

