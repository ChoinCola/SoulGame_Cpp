#pragma once

//TODO ���⿡�ٰ� ���� �����־��.
class Math
{

public:
	static const int Random(const int& min, const int& max);
	static const float Random(const float& min, const float& max);
private:

	static std::random_device rd;
	static std::mt19937 mt;
	// static = ���������� ����Ͽ� ����Ǹ� ��� �Լ����� ����� �� �ִ�. �׷���
	// CLass���� ����Ǿ �������� �ʱ�ȭ ���־�� �Ѵ�.
};

