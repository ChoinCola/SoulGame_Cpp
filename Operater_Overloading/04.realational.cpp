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
	// 값을 한개만 가져와서 비교하는것 은 원래 operator을 만들려는 의미( class 간의 비교 ) 와 적합하지 않기 때문에, 한개의 변수만 비교하는 식 으로는 사용되지 않는다.
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
		cout << "같다" << endl;
	else if (w1 != w2)
		cout << "다르다" << endl;

	// vector = heap 영역에 들어가는 동적 배열.
	// 배열처럼 연속된 메모리 영역을 가지게 된다.

	std::vector<Won> wons(20);

	int i = 1;

	for (auto& won : wons)
	{
		won.Setvalue(i);
		i++; // 데이터 입력
	}

	for (const auto& won : wons)
		cout << won << " "; // 데이터 출력
	cout << endl;

	random_shuffle(wons.begin(), wons.end()); // 알고리즘 라이브러리의 셔플 알고리즘 vector의 시작과 끝을 넣어야함.

	for (const auto& won : wons)
		cout << won << " "; // 데이터 출력
	cout << endl;

	sort(wons.begin(), wons.end());

	for (const auto& won : wons)
		cout << won << " "; // 데이터 출력
	cout << endl;

	sort(wons.begin(), wons.end(), test);

	for (const auto& won : wons)
		cout << won << " "; // 데이터 출력
	cout << endl;

	// 람다식 함수 ( 짧은 코드를 캡슐화 하는데 사용한다 ) 비동식 함수.
	sort(wons.begin(), wons.end(), [](const Won& lhs, const Won& rhs)
		{
			return lhs.Getvalue() < rhs.Getvalue();
		});

	return 0;
}


