#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <random>

using namespace std;

random_device rd;
mt19937_64 mt(rd());

int main()
{
	vector<int> container;

	for (int i = 0; i < 10; i++)
		container.push_back(i);

	shuffle(container.begin(), container.end(), mt);

	for (auto iter = container.begin(); iter != container.end(); iter++) // 전부 섞기
		cout << *iter << " ";
	cout << endl;

	auto iter = min_element(container.begin(), container.end()); // 최솟값 출력
	cout << *iter << endl;

	iter = max_element(container.begin(), container.end()); // 최대값 출력
	cout << *iter << endl;

	iter = find(container.begin(), container.end(), 7); // 원하는 위치의 값 출력
	cout << *iter << endl;

	sort(container.begin(), container.end()); // 최소값 정렬. 퀵정렬 해주는 알고리즘이다. 퀵정렬 알아보기 찾아보기 정리하기.

	for (auto iter = container.begin(); iter != container.end(); iter++)
		cout << *iter << " ";
	cout << endl;

	return 0;
}