#include <iostream>

using namespace std; 
// 위임 생성자. 어떤 특정 맴버 변수만 다른값으로 초기화 하고 싶을 때 사용한다.

class Student
{
public:
	Student(const int& id, const string& name)
		:id(id), name(name)
	{}

	Student(const string& name)
		:Student(0, name) // 위임 생성자. 한개만 초기화하는 방법이다.
	{}
private:
	int id;
	string name;
};

class Student2
{
public:
	Student2(const int& id, const string& name)
	{
		Initialize(id, name); // 다양한 방법을 사용할 수 있지만, 단 한개만 동일하게 사용하는것이 좋을것 이다.
	}
	void Initialize(const int& id, const string& name)
	{
		//TODO : 나중에 초기화해주기 TODO는 주석을 바로 갈 수 있게 북마크를 추가하는것이다.

private:
	int id;
	string name;
};
int main()
{


	return 0;
}