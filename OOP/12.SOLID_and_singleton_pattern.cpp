#include <iostream>
/*
	객체지향 4대 특징
	- 캡슐화	객체의 공통된 항목끼리 묶어서 필요한 항목만 표시하고 나머지는 은닉한다.
	- 추상화	모델링 관심 영역의 특성만 가지고 조합해주는것
	- 상속	부모 클래스의 기능을 물려받는 하위 클레스를 만드는것 확장성을 끼어만듬
	- 다형성	오버로딩 [같은이름을 여러개 호출해서 사용할 수 있음] 오버라이딩 [TODO 조사하기 ]

	객체지향 설계원칙(SOLID)

	- 단일 책임 원칙(Single Responsibility Principle)
		모든 클래스는 하나의 책임만 저야한다.
		사람은 사람만, 몬스터는 몬스터만. 하나의 클래스는 하나의 책임만 져야한다.
		계산기가 사칙연산만 한다면, 사칙연산만. 최대한 간단하게 구조화해야한다.

	- 개방-폐쇄 원칙(Open Closed Principle)
		확장에는 열려있고 수정에는 닫혀있어야 한다.
		기능을 추가할려고 하는 확장에는 열려있어야 하지만, 수정할 때 다른 코드를 수정하지 않으면서 수정할 수 있어야 한다.

	- 리스코프 치환 원칙(Liskov Subsitution Principle)
		자식 클래스는 언제나 부모 클래스를 대체할 수 있어야 한다. 
		부모클래스에 자식을 박아도 동작하게 해야한다.

	- 인터페이스 분리 원칙(Interface Segregation Principle)
		한 클래스 안에 내가 사용하지 않을 인터페이스는 구현하지 말아야 한다.
		사용하지 않는 인터페이스가 있는것 보다 사용할 것만 있는게 낫다.

	- 의존 역전 원칙(Dependency Inversion Principle)
		클레스 끼리 엮여 들어갈 때, 변화하기 어려운것. 변화가 거의 없는 것 에 의존하게 만들어야 한다.

*/

/*
	디자인 패턴
	( 소프트웨어를 설계할 때 계속 생기는 문제가 생긴다.
	전에 이미 만들었던 코드는 다시 재사용할 수 있어야 한다. 라는 것

	- 싱글톤 패턴
		객체의 인스턴스가 하나만 존재하는 패턴. 생성자가 여러번 호출이 되더라도. 실체로 생성되는 객체는 하나 인것이고.
		최초에 생성된 이후 나머지 호출자는 전에 생성된 클레스를 호출하게 되는것.
	엄청나게 많다.
*/
using namespace std;

class Audio
{
public:
	static Audio& GetInstance() {
		static Audio audio;
		return audio;
	}

	void OutSound(string music) {
		cout << "Sound Effect : " << music << endl;
	}
	
	Audio() {} // 생성자를 만들지 않으면 자동으로 만들어지는 것
	Audio(const Audio& audio) = delete; // 복사 생성자도 자동으로 생성된다.
	Audio& operator=(const Audio& audio) {};
};

int main()
{
	string bgm("던전");
	Audio::GetInstance().OutSound(bgm); // 변수 명을 선언하지 않는다.
	// 이벤트를 생성할 때 발생마다 생성하면 메모리를 너무 많이 잡아먹기 때문에, 한개씩만 선언시켜야한다.


	return 0;
}