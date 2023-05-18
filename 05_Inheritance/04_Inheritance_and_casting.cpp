#include <iostream>

using namespace std;

/*
	Up castirng
	자식클레스가 더 크다. 그렇지만 개념적으로, 부모클래스의 것을 물려받기 때문에 부모클래스가 더 크다고 본다.
	개념적으로 더 큰 개념으로 가는것 이기 때문에, 자식 -> 부모 쪽으로 가는것 을 UP casting이라고 한다.

	Down casting
	부모클래스의 포인터가 가르키는 객체를 자식클래스의 포인터로 가르키게 된다.
	부모클래스의 포인터가 부모의 객체를 가르킬때에는, 자식클래스의 값을 가르킬 수 없게된다.
*/

class Snack {};

class Chitos : public Snack {};
class ChocoChip : public Snack {};
class Homerunball : public Snack {};

int main()
{
	Snack* chocochip = new ChocoChip(); // 업케스팅(Up casting)
	Snack* chitos = new Chitos();

	Snack* sneck[2] = { chitos, chocochip }; // 업케스팅을 사용해서 배열로 사용이 가능하다. 접근이 가능하다. 관련이 있는것 끼리 묶어야한다.

	Chitos* test = static_cast<Chitos*>(chitos); // 다운케스팅 많이 사용하지는 않는다.

	// Chitos* cc = new Snack(); // error이 된다. 아래에서 위로만 케스팅이 된다.

	return 0;
}