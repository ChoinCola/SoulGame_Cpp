#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Won
{
	int value;
	//int value1;
public:

	Won(int value = 0) : value(value) {}

	auto Getvalue() const { return value; }
	void Setvalue(const int& value) { this->value = value; }

	friend ostream& operator << (ostream& out, const Won& won)
	{
		out << won.value;
		return out;
	}

	// == != < >
	bool operator==(const Won& rhs) const
	{
		return value == rhs.value;// && value1 == rhs.value1;
	}
	// ���� �Ѱ��� �����ͼ� ���ϴ°� �� ���� operator�� ������� �ǹ�( class ���� �� ) �� �������� �ʱ� ������, �Ѱ��� ������ ���ϴ� �� ���δ� ������ �ʴ´�.
	bool operator!=(const Won& rhs) const
	{
		return !(*this == rhs);
	}

	bool operator < (const Won& rhs) const
	{
		return value < rhs.value;
	}

	friend bool test(const Won& lhs, const Won& rhs);
};

bool test(const Won& lhs, const Won& rhs)
{
	return lhs.Getvalue() > rhs.Getvalue();
}

int main()
{
	Won w1(10), w2(20);

	if (w1 == w2)
		cout << "����" << endl;
	else if (w1 != w2)
		cout << "�ٸ���" << endl;

	// vector = heap ������ ���� ���� �迭.
	// �迭ó�� ���ӵ� �޸� ������ ������ �ȴ�.

	std::vector<Won> wons(20);

	int i = 1;

	for (auto& won : wons)
	{
		won.Setvalue(i);
		i++; // ������ �Է�
	}

	for (const auto& won : wons)
		cout << won << " "; // ������ ���
	cout << endl;

	random_shuffle(wons.begin(), wons.end()); // �˰��� ���̺귯���� ���� �˰��� vector�� ���۰� ���� �־����.

	for (const auto& won : wons)
		cout << won << " "; // ������ ���
	cout << endl;

	sort(wons.begin(), wons.end());

	for (const auto& won : wons)
		cout << won << " "; // ������ ���
	cout << endl;

	sort(wons.begin(), wons.end(), test);

	for (const auto& won : wons)
		cout << won << " "; // ������ ���
	cout << endl;

	// ���ٽ� �Լ� ( ª�� �ڵ带 ĸ��ȭ �ϴµ� ����Ѵ� ) �񵿽� �Լ�.
	sort(wons.begin(), wons.end(), [](const Won& lhs, const Won& rhs)
		{
			return lhs.Getvalue() < rhs.Getvalue();
		});

	return 0;
}


