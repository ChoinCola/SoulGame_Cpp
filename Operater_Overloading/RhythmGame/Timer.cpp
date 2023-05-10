#include "stdafx.h"
#include "Timer.h"


Timer::Timer()
{
}

bool Timer::Initalize()
{
	previous_time = std::chrono::high_resolution_clock::now(); // 가장 높은 해상도로 돌려준다. 
	return true;
}

void Timer::Update()
{
	auto current_time = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> ms = current_time - previous_time; // 얼마나 진행되었는지 체크한다.
	previous_time = current_time; // 현재 시간 받아옴.

	delta_time_ms = ms.count(); // 얼마나 지났는지 가져오려고 가져온것.
}


Stopwatch::Stopwatch()
{
	Start();
}

void Stopwatch::Start()
{
	start_time = std::chrono::high_resolution_clock::now(); // 현재 시간을 가져오는 함수.
}

const float Stopwatch::GetElapsedTimeSec()
{
	std::chrono::duration<double, std::milli> ms = std::chrono::high_resolution_clock::now() - start_time;
	return static_cast<float>(ms.count() / 1000.0);
}

const float Stopwatch::GetElapsedTimeMs()
{
	std::chrono::duration<double, std::milli> ms = std::chrono::high_resolution_clock::now() - start_time;
	return static_cast<float>(ms.count());
}
