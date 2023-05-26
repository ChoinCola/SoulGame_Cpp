/*
	STL : Standard Template Library
	다양한 타입을 사용할 수 있게 만드는것

	- 컨테이너(container) [ 타입을 보관하는 공간 ]
	- 반복자(iterator) [ 컨테이너들의 원소를 가리키고, 그 원소를 이용해서 다음 원소를 가리키게 하는것  접근?]
	- 알고리즘(algorithm) [ 정렬, 검색, 등 을 사용하는 알고리즘 ]
	- 함수자(functor) [ 객체를 함수처럼 사용할 수 있는 펑션 이다 ]
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
	Container 종류
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
	// 문자열을 정수형으로 바꿀 때 사용함.
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
	- 데이터를 배열처럼 '선형' 으로 저장하는 컨테이너
*/
void SequnceContainer()
{
	/*
		Vector 크기예측이 가능, 삽입삭제 별로없고, 연속적인 데이터처리가 필요할 때 사용하는게 좋음
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

	// Deque 벡터랑 비슷하지만, 원소가 메모리공간에 연속적으로 존재하지 않는다.
	// 메모리를 재할당 할 때 추가로 공간을 만든다음 이어붙인다.
	// 그러나, 서로 떨어진 메모리 공간의 데이터를 보관해야함 으로, vector보다 추가적인 메모리가 필요하다.
	// 중간에 값을 넣는것은 vector보다 훨씬 빠르다.

	{
		cout << "Deque" << endl;

		deque<int> deq;

		for (int i = 0; i < 10; i++)
		{
			deq.push_back(i);
			deq.emplace_front(i);// vector와 다르게, 더 효율적으로 동작한다. vector는 하나하나 다 밀어야하는데 이건 아님.
		}

		for (const auto& ele : deq)
			cout << ele << ' ';
		cout << endl << endl;
	}

	// list
	// 시작원소와 마지막원소만을 기억해서 서로가 자신의 앞과 뒤를 가리키는 배열형태이다.
	// 삽입삭제가 빈번하게 이루어지는 상황에서 사용하기 좋다. 더 빠르게 작업이 가능하기 때문.
	{
		cout << "List" << endl;
		list<int> list;

		for (int i = 0; i < 10; i++)
			list.push_back(i);

		for (const auto& ele : list)
			cout << ele << ' ';
		cout << endl << endl;
	}
	// 사용복잡도에 따라 list -> deque -> vector 로 간다.
}

/*
	associative container
	- 키(key) - 값(value) 구조를 가진다.
*/

void AssociativeContainer()
{
	/*
		set / multiset

		set = 저장하는 데이터 값 자체를 키로 사용한다.
		데이터의 존재 유무만 확인하는 경우가 많다.
		그리하여 중복값을 허용하지 않는다.

		multiset = 저장하는 데이터 이외의 값을 키로 사용한다.
		데이터의 존재 유무 를 참조하지 않기 때문에 중복값을 허용하는 경우가 많다.
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
		
		이 또한 마찬가지로,
		map은 중복을 허용하지 않는다. key = value이기 때문
		multimap은 중복을 허용한다. key와 value는 다르기 때문

		map은 여러개의 값의 주소를 가지는 하나의 공간이 있고, 그곳에서 주소값을 타고 들어가는것.
		key값을 기준으로 이진트리 구분을 해놓고, key 기준으로 sort한것.
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
		// ele의 첫번째 요소,				ele의 두번째 요소
	}
	{
		cout << "Multimap" << endl;

		multimap<char, int> multimap;
		multimap.insert(pair<char, int>('a', 10000));
		multimap.insert(pair<char, int>('b', 100));
		//multimap.insert(pair('b', 100)); // C++ 17이후부터는 이렇게 써도 오류가 안난다.

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
		
		해시 테이블 조사
	*/
}
/*

	AdapterContainer
	반복자를 지원하지 않는다. 안에 알고리즘 사용이 안된다.
	구조로 만들어진 컨테이너


*/
void AdapterContainer()
{
	/*
		Stack [ 벡터를 변형해서 statc으로 만든 컨테이너 ]
		선형으로 데이터를 저장해준다.
		- LIFO 후입선출 구조를 따른다.
	*/
	{
		cout << "Stack" << endl;

		stack<int> stack;

		stack.push(1); // push adds a copy 복사되어 넣는다.
		stack.emplace(2); // emplace constructs a new object 새로운 객체를 생성해서 넣는 형태.
		stack.emplace(3); // 둘다 큰 차이는 없으나, push는 복사ㅡ emplace는 원본ㅡ 넣는 형태.

		cout << stack.top() << endl;
		stack.pop();
		cout << stack.top() << endl << endl;
	}
}

/*
	내가 입력한 단어 개수와 출력할 수 m, n 만들기
	단어 개수 m 에 맞게 단어를 입력.
	정답 개수 n에 따라 정답을 맞힐 것

	단어를 입력하면 숫자가 출력
	숫자를 입력하면 단어가 출력
*/

