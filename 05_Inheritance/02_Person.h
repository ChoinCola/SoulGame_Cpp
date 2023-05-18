#pragma once
#include <string>

class Person
{
protected:
	std::string name;
public:
	
	Person() = default; // �⺻������ �⺻���� �־��.
	// �⺻�����ڰ� ���ٸ�, ��ǻ�Ͱ� ������ �� ������ �߻��� �� �ֱ� ����,

	Person(const std::string& name)
		:name(name)
	{}
	auto Getname() const { return name; }
	void SetName(const std::string& name) { this->name = name; }
};