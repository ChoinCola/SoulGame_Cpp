#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>

using namespace std;
/*
	�����̳ʿ� �����Ͽ� ����� �� �ִ¹����.
*/
int main()
{
	{
		vector<int> container;
		for (int i = 0; i < 10; i++)
			container.push_back(i);

		vector<int>::iterator iter;
		iter = container.begin(); // ù��° ���� ��ȯ iter��

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
		// �� for�� �ΰ��� auto �̳� �ƴϸ� iterator �̳Ŀ� ���� �޶����°����� �ڵ� ��ü�� ���ٰ� �����ȴ�.
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