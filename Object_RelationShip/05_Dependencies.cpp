#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;
// �������� Ư���� Ŭ������ �ٸ� Ŭ������ ��� ����ϴ� ����.

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
	����.
	class�� Ȱ���ؼ�, ���� ���� �ý����� ������.

	1. ���� ����
	2. �Ա�
	3. ���
	4. �������� ��ü ���

	���� ������
	���� ���� ������ �� �����غ���.
*/