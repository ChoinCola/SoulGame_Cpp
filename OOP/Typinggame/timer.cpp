#include "stdafx.h"
#include "timer.h"

Stopwatch::Stopwatch()
{
	Start();
}

void Stopwatch::Start()
{
	start_time = std::chrono::high_resolution_clock::now(); // ���� �ð��� �������� �Լ�.
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
