#pragma once

class timer
{
};

class Stopwatch
{
public:
	Stopwatch();

	void Start();

	const float GetElapsedTimeSec();
	const float GetElapsedTimeMs();

private:	
	std::chrono::time_point<std::chrono::high_resolution_clock> start_time;
	//TODO �ð��� �����ϴ� �Լ� ����
};
