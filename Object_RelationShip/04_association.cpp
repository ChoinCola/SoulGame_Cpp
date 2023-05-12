#include <iostream>
#include <vector>
using namespace std;
// Ư�� Ŭ������ �ٸ� Ŭ������ �ɹ� �� ������ ���.
// ���� ���谡 �Ǵ� ����. �ǻ�� ȯ�� �� ���.
// Ŀ�ø� ����

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

	 // ���ΰ� ���ο��� ������ ��ġ�� ������, �ϳ��� �����Ǹ� ������ ������ �� �ִ�. �׷��� ���� ���� �ڵ尡 �ƴϴ�.

	delete d2;
	delete d1;
	delete p3;
	delete p2;
	delete p1;


	// ����� Ŭ�������� ���Լ��� ������� �������־�� �Ѵ�. ó�� ����� Ŭ������ �󸶳� ���������� �� �� ���� ����.
	return 0;
}


