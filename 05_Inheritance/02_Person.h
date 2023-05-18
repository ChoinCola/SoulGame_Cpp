#pragma once
#include <string>

class Person
{
protected:
	std::string name;
public:
	
	Person() = default; // 기본생성자 기본값을 넣어라.
	// 기본생성자가 없다면, 컴퓨터가 생성할 때 문제가 발생할 수 있기 때문,

	Person(const std::string& name)
		:name(name)
	{}
	auto Getname() const { return name; }
	void SetName(const std::string& name) { this->name = name; }
};