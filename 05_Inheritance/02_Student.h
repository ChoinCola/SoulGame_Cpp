#pragma once
#include "02_Person.h"

class Student : public Person
{
public:
	Student(const std::string& name)
		: Person(name)
	{
		// this->name = name;
	}
	void Study() {} // »Æ¿Â
};