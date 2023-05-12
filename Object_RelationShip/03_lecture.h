#pragma once

#include <iostream>
#include <vector>
#include "03_student.h"
#include "03_teacher.h"

class Lecture
{
	std::string name;

	Teacher* teacher;
	std::vector<Student*> students;
public:
	Lecture(const std::string& name)
		: name(name)
	{}

	void AssignmentTeacher(Teacher* teacher)
	{
		this->teacher = teacher;
	}

	void AssignmentStudent(Student* student)
	{
		students.push_back(student);
	}

	void Print()
	{
		std::cout << "teacher : " << teacher << std::endl;

		for (const auto& student : students)
			std::cout << "student : " << student << std::endl;

		std::cout << std::endl;
	}
};