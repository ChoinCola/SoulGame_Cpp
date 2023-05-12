#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
// 의존관계 특정한 클래스가 다른 클래스를 잠깐 사용하는 형태.

class Timer
{
	time_point<high_resolution_clock> start_time;

public:
	Timer()
	{
		start_time = high_resolution_clock::now();
	}

	void Elapsed()
	{
		auto current_time = high_resolution_clock::now();
		duration<double, std::milli> delta = current_time - start_time;

		cout << "Second : " << delta.count()/1000 << endl;
	}
};

class Worker
{
public:
	void DoSomething()
	{
		Timer timer;
		for (int i = 0; i < 100'000'000; i++);
		timer.Elapsed();
	}
};

int main()
{
	Worker w;
	w.DoSomething();

	return 0;
}

/*
	과제.
	class를 활용해서, 은행 계좌 시스템을 만들어보자.

	1. 계좌 개설
	2. 입금
	3. 출금
	4. 계좌정보 전체 출력

	복사 생성자
	복사 대입 생성자 로 제작해보기.
*/