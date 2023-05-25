#include <iostream>

// pure_virtual_function

// abstract_class 순수가상화 class

// Interface 기능을 구현할 것을 약속한 추상의 형식

// 명시적으로 알리기 위해 대부분 i를 붙여서 사용하는 경우가 많다.

using namespace std;

#pragma region abstract class
//class animal abstract // 추상클래스로 만들때를  가정 abstract 붙인다.
//{
//	string name;
//
//public:
//	animal(const string& name) : name(name) {}
//
//	auto getname()const { return name; }
//
//	virtual void sleep() const final
//	{
//		cout << "sleep" << endl;
//	} // 공통된 특성이기 떄문에 궂이 vitrual로 써줄 필요가 없지만, 모두가 공통되게 sleep할것 이기 때문에, final로 막아준다.
//
//	virtual void speak() const abstract = 0;
//};
//
//class cat : public animal
//{
//public:
//	cat(string name) : animal(name) {}
//
//	void speak() const { cout << "야옹" << endl; }
//};
//
//class dog : public animal
//{
//public:
//	dog(string name) : animal(name) {}
//
//	void speak() const { cout << "멍멍" << endl; }
//};
//
//class fox : public animal
//{
//public:
//	fox(string name) : animal(name) {}
//};
//
//int main()
//{
//	//animal ani("asdfa"); // 가상함수는 실체화 불가 오류가 나타난다.
//
//	cat c("cc");
//	dog d("dd");
//	//fox f("ff"); // 가상화함수를 인스턴스화 해주지 않았기 때문에 사용할 수 없다.
//
//	c.sleep();
//	d.sleep();
//	c.speak();
//	d.speak();
//	return 0;
//}
#pragma endregion

#pragma region Interface
class IErrorLog // 순수 가상함수로만 이루어진 인터페이스 이다.
{
public:
	virtual ~IErrorLog() = default;
	virtual bool ReportError(const char* const error) abstract; // 순수 가상화 선언
};

class FileErrorlog : public IErrorLog
{
public:
	virtual bool ReportError(const char* const error) override
	{
		cout << "writting error to a file" << endl;
		return true;
	}
};

class ConsoleErrorlog : public IErrorLog
{
public:
	virtual bool ReportError(const char* const error) override
	{
		cout << "Console error to a input" << endl;
		return true;
	}
};

void DoSomething(IErrorLog& log)
{
	log.ReportError("Error");
}

int main()
{
	//IErrorLog f;
	FileErrorlog fileLog;
	ConsoleErrorlog consoleLog;

	DoSomething(fileLog);
	DoSomething(consoleLog);
	return 0;
}
#pragma endregion

/*

	책 부모클래스
	- 종이책, ebook 이 상속받아서 옴

	책 이름, 책 번호, 책 가격 멤버함수 로
	ebook의 경우엔 판매 사이트 멤버 함수

	종이책의 경우 5권 이상 만들어지면, 책장이 꽉 찼습니다. 출력

*/