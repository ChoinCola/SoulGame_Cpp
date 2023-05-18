#pragma once
#include "02_Person.h"

class Teacher : public Person
{
public:
	Teacher(const std::string& name)
		: Person(name)
	{}
	void Teach() {}
};