/*
	STL : Standard Template Library
	�پ��� Ÿ���� ����� �� �ְ� ����°�

	- �����̳�(container) [ Ÿ���� �����ϴ� ���� ]
	- �ݺ���(iterator) [ �����̳ʵ��� ���Ҹ� ����Ű��, �� ���Ҹ� �̿��ؼ� ���� ���Ҹ� ����Ű�� �ϴ°�  ����?]
	- �˰���(algorithm) [ ����, �˻�, �� �� ����ϴ� �˰��� ]
	- �Լ���(functor) [ ��ü�� �Լ�ó�� ����� �� �ִ� ��� �̴� ]
*/

#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
using namespace std;


/*
	Container ����
	- sequnce , associative, adapter

*/
// sequnce
void SequnceContainer();
void AssociativeContainer();
void AdapterContainer();

int main()
{
	SequnceContainer();
	AssociativeContainer();
	AdapterContainer();
	// stoi => stirng to int
	// ���ڿ��� ���������� �ٲ� �� �����.
	//string str1 = "123";
	//string str2 = "456";
	//cout << str1 + str2 << endl;

	//int i1 = stoi(str1);
	//int i2 = stoi(str2);

	//cout << i1 + i2;

	return 0;
}


/*
	Sequnce Container
	- �����͸� �迭ó�� '����' ���� �����ϴ� �����̳�
*/
void SequnceContainer()
{
	/*
		Vector ũ�⿹���� ����, ���Ի��� ���ξ���, �������� ������ó���� �ʿ��� �� ����ϴ°� ����
	*/
	{
		cout << "Vector" << endl;

		vector<int> vec;
		
		for (int i = 0; i < 10; i++)
			vec.push_back(i);

		for (const auto& ele : vec)
			cout << ele << ' ';
		cout << endl << endl;

	}

	// Deque ���Ͷ� ���������, ���Ұ� �޸𸮰����� ���������� �������� �ʴ´�.
	// �޸𸮸� ���Ҵ� �� �� �߰��� ������ ������� �̾���δ�.
	// �׷���, ���� ������ �޸� ������ �����͸� �����ؾ��� ����, vector���� �߰����� �޸𸮰� �ʿ��ϴ�.
	// �߰��� ���� �ִ°��� vector���� �ξ� ������.

	{
		cout << "Deque" << endl;

		deque<int> deq;

		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);
			deq.emplace_front(i);// vector�� �ٸ���, �� ȿ�������� �����Ѵ�. vector�� �ϳ��ϳ� �� �о���ϴµ� �̰� �ƴ�.
		}

		for (const auto& ele : deq)
			cout << ele << ' ';
		cout << endl << endl;
	}

	// list
	// ���ۿ��ҿ� ���������Ҹ��� ����ؼ� ���ΰ� �ڽ��� �հ� �ڸ� ����Ű�� �迭�����̴�.
	// ���Ի����� ����ϰ� �̷������ ��Ȳ���� ����ϱ� ����. �� ������ �۾��� �����ϱ� ����.
	{
		cout << "List" << endl;
		list<int> list;

		for (int i = 0; i < 10; i++)
			list.push_back(i);

		for (const auto& ele : list)
			cout << ele << ' ';
		cout << endl << endl;
	}
	// ��뺹�⵵�� ���� list -> deque -> vector �� ����.
}

/*
	associative container
	- Ű(key) - ��(value) ������ ������.
*/

void AssociativeContainer()
{
	/*
		set / multiset

		set = �����ϴ� ������ �� ��ü�� Ű�� ����Ѵ�.
		�������� ���� ������ Ȯ���ϴ� ��찡 ����.
		�׸��Ͽ� �ߺ����� ������� �ʴ´�.

		multiset = �����ϴ� ������ �̿��� ���� Ű�� ����Ѵ�.
		�������� ���� ���� �� �������� �ʱ� ������ �ߺ����� ����ϴ� ��찡 ����.
	*/

	{
		cout << "Set" << endl;

		set<string> strset1;

		strset1.insert("Hello");
		strset1.insert("World");
		strset1.insert("Hello");

		cout << strset1.size() << endl;

		for (const auto& ele : strset1)
			cout << ele << ' ';
		cout << endl << endl;
	}

	{
		cout << "Multiset" << endl;

		multiset<string> strset2;

		strset2.insert("Hello");
		strset2.insert("World");
		strset2.insert("Hello");

		cout << strset2.size() << endl;

		for (const auto& ele : strset2)
			cout << ele << ' ';
		cout << endl << endl;
	}

	/*
		map / multimap
		
		�� ���� ����������,
		map�� �ߺ��� ������� �ʴ´�. key = value�̱� ����
		multimap�� �ߺ��� ����Ѵ�. key�� value�� �ٸ��� ����

		map�� �������� ���� �ּҸ� ������ �ϳ��� ������ �ְ�, �װ����� �ּҰ��� Ÿ�� ���°�.
		key���� �������� ����Ʈ�� ������ �س���, key �������� sort�Ѱ�.
	*/

	{
		cout << "Map" << endl;

		map<char, int> map;
		map['c'] = 50; // mapping
		map['a'] = 10;
		map['d'] = 40;
		map['b'] = 20;
	
		cout << map['a'] << endl;

		map['a'] = 100;
		cout << map['a'] << endl;

		for (const auto& ele : map)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl << endl;
		// ele�� ù��° ���,				ele�� �ι�° ���
	}
	{
		cout << "Multimap" << endl;

		multimap<char, int> multimap;
		multimap.insert(pair<char, int>('a', 10000));
		multimap.insert(pair<char, int>('b', 100));
		//multimap.insert(pair('b', 100)); // C++ 17���ĺ��ʹ� �̷��� �ᵵ ������ �ȳ���.

		multimap.insert(make_pair('a', 1000));

		cout << multimap.count('a') << endl;

		for (const auto& ele : multimap)
			cout << ele.first << ' ' << ele.second << ' ';
		cout << endl << endl;
	}

	/*
		unordered associative container

		- unordered_set
		- unordered_map
		
		�ؽ� ���̺� ����
	*/
}
/*

	AdapterContainer
	�ݺ��ڸ� �������� �ʴ´�. �ȿ� �˰��� ����� �ȵȴ�.
	������ ������� �����̳�


*/
void AdapterContainer()
{
	/*
		Stack [ ���͸� �����ؼ� statc���� ���� �����̳� ]
		�������� �����͸� �������ش�.
		- LIFO ���Լ��� ������ ������.
	*/
	{
		cout << "Stack" << endl;

		stack<int> stack;

		stack.push(1); // push adds a copy ����Ǿ� �ִ´�.
		stack.emplace(2); // emplace constructs a new object ���ο� ��ü�� �����ؼ� �ִ� ����.
		stack.emplace(3); // �Ѵ� ū ���̴� ������, push�� ����� emplace�� ������ �ִ� ����.

		cout << stack.top() << endl;
		stack.pop();
		cout << stack.top() << endl << endl;
	}
}

/*
	���� �Է��� �ܾ� ������ ����� �� m, n �����
	�ܾ� ���� m �� �°� �ܾ �Է�.
	���� ���� n�� ���� ������ ���� ��

	�ܾ �Է��ϸ� ���ڰ� ���
	���ڸ� �Է��ϸ� �ܾ ���
*/

