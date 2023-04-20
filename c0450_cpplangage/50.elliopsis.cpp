#include <iostream>
#include <cstdarg>

using namespace std;
// 가변함수

double fineAverage(int count, ...) // 가변인자 함수.
{
	double sum = 0;

	va_list lists;
	va_start(lists, count); // 임의의 가변인자의 전체개수와 리스트를 넣어서 시작부분을 돌린다.

	for (int arg = 0; arg < count; arg++) {
		sum += va_arg(lists, int);
	}

	va_end(lists); // 임의의 가변인자를 넣은 리스트를 free해준다.

	return sum / count;
}

int main()
{
	cout << fineAverage(3, 1, 2, 3) << endl;
	cout << fineAverage(5, 1, 2, 3, 4, 5) << endl;
	cout << fineAverage(3, 1, 2, 3, 4, 5) << endl; // 카운트 값에 맞게 해당되는 데이터만 결과가 연산된다는걸 알 수 있다.

	return 0;
}