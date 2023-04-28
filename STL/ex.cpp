#include <iostream>
#include <list>

using namespace std;
// 리스트는 삽입 삭제가 매우 쉽고, 배열을 순차적으로 접근하게된다.
// 자료구조의 구현라이브러리
int main()
{
	list<int> list;

	for (int i = 0; i < 10; i++)
		list.push_back(i);

	// 범위기반 for문 을 사용하면 편하게 이용할 수 있다.
	for (const auto& ele : list)
		cout << ele << " ";

	return 0;
}