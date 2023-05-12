#pragma once

class Student
{
	std::string name;
	int count;

public:
	Student(const std::string name, int count = 0)
		:name(name), count(count)
	{}

	auto GetName() const { return name; }
	void SetName(const std::string& name) { this->name = name; }

	auto Getcount() const { return count; }
	void Setcount(const int& count) { this->count = count; }

};