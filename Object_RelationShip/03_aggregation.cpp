#include "03_lecture.h"

int main()
{
	using namespace std;
	
	Teacher t("teacher");
	Student s1("a");
	Student s2("b");
	Student s3("c");

	cout << "t : " << &t << endl;
	cout << "s1 : " << &s1 << endl;
	cout << "s1 : " << &s2 << endl;
	cout << "s1 : " << &s3 << endl;
	cout << endl;

	{
		Lecture lec("C++");
		lec.AssignmentTeacher(&t);
		lec.AssignmentStudent(&s1);
		lec.AssignmentStudent(&s2);
		lec.AssignmentStudent(&s3);
		lec.Print();
	}

	cout << "t : " << &t << endl;
	cout << "s1 : " << &s1 << endl;
	cout << "s1 : " << &s2 << endl;
	cout << "s1 : " << &s3 << endl;
	return 0;
	// lecture는 집합관계이다.
}