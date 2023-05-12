#include <iostream>
#include <vector>
using namespace std;
// 특정 클래스가 다른 클래스의 맴버 를 선언한 경우.
// 서로 연계가 되는 관계. 의사와 환자 의 경우.
// 커플링 관계

class Patient
{
	string name;
	friend class Doctor;
	vector<class Doctor*> doctors;
public:
	Patient(const string& name)
		:name(name)
	{}
	void AddDoctor(class Doctor* const doctor)
	{
		doctors.push_back(doctor);
	}

	void MeetDoctor();
};

class Doctor
{
	string name;
	friend class Patient;
	vector<class Patient*> patients;
public:
	Doctor(const string& name)
		:name(name)
	{}

	void AddPatient(class Patient* const patient)
	{
		patients.push_back(patient);
	}

	void MeetPatient()
	{
		for (const auto& patient : patients)
			cout << "Meet Patient : " << patient->name << endl;
	}
};

void Patient::MeetDoctor()
{
	for (const auto& doctor : doctors)
		cout << "Meet Patient : " << doctor->name << endl;
}

int main()
{
	Patient* p1 = new Patient("Kim");
	Patient* p2 = new Patient("Lee");
	Patient* p3 = new Patient("Park");

	Doctor* d1 = new Doctor("Doc. Lee");
	Doctor* d2 = new Doctor("Doc. Kim");

	p1->AddDoctor(d1);
	d1->AddPatient(p1);

	p2->AddDoctor(d2);
	d2->AddPatient(p2);
	
	p3->AddDoctor(d2);
	d2->AddPatient(p3);

	 // 서로가 서로에게 영향을 끼치기 때문에, 하나가 수정되면 오류가 폭팔할 수 있다. 그래서 별로 좋은 코드가 아니다.

	delete d2;
	delete d1;
	delete p3;
	delete p2;
	delete p1;


	// 선언된 클래스들은 후입선출 방식으로 해제해주어야 한다. 처음 선언된 클래스는 얼마나 엮여있을지 알 수 없기 때문.
	return 0;
}


