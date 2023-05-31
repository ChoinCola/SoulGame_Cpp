#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;
/*
	컨테이너에 접속하여 출력할 수 있는방법들.
*/
int main()
{
	{
		vector<int> container;
		for (int i = 0; i < 10; i++)
			container.push_back(i);

		vector<int>::iterator iter;
		iter = container.begin(); // 첫번째 값을 반환 iter에

		while (iter != container.end())
		{
			cout << *iter << " ";
			++iter;
		}
		cout << endl;

		for (vector<int>::iterator iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";

		cout << endl << endl;
		// 위 for문 두개는 auto 이냐 아니면 iterator 이냐에 따라 달라지는것이지 코드 자체는 같다고 봐도된다.
	}

	{
		list<int> container;

		for (int i = 0; i < 10; i++)
			container.push_back(i);

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";
		cout << endl << endl;
	}

	{
		set<int> container;
		for (int i = 0; i < 10; i++)
			container.insert(i);

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << *iter << " ";
		cout << endl << endl;
	}

	{
		map<int, char> container;
		for (int i = 0; i < 10; i++)
			container.insert(make_pair(i, i + 32));

		for (auto iter = container.begin(); iter != container.end(); iter++)
			cout << iter->first << ":" << iter->second << " ";
		cout << endl << endl;

		int answer;
		for (auto iter = container.begin(); iter != container.end(); iter++)
		{
			cin >> answer;
			if (container.find(answer) != container.end())
				cout << container.find(answer)->first << " " << container.find(answer)->second;
			else
				break;
		}
			
	}
	return 0;
}