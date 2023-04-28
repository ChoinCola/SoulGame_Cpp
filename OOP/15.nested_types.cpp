#include <iostream>

using namespace std;
// 자료형을 중첩하여 사용할 때 사용하는 방법이다.

class Character
{
public:
	Character(string&& name)
		:name(name)
	{}

	enum class Movement
	{
		idle = 0,
		walk,
		Run,

		Count
	};

	void SetCharacterMovement(enum class Movement inMove) {
		movementState = inMove;
		speed = movementSpeed[static_cast<int>(inMove)];
	}

	void PrintCurrentMovementState()
	{
		switch(movementState)
		{
		case Character::Movement::idle:
			cout << name << "의 현재 이동 상태 : idle, 현재 속도 : " << speed << endl;
			break;
		case Character::Movement::walk:
			cout << name << "의 현재 이동 상태 : walk, 현재 속도 : " << speed << endl;
			break;
		case Character::Movement::Run:
			cout << name << "의 현재 이동 상태 : Run, 현재 속도 : " << speed << endl;
			break;
		}
	}

private:
	const int movementSpeed[static_cast<int>(Movement::Count)] =
	{
		0,
		200,
		500
	};

	enum class Movement movementState = Movement::idle;

	int speed = movementSpeed[static_cast<int>(Movement::idle)];

	string name;
};

int main()
{
	Character player(string("Player"));
	player.PrintCurrentMovementState();
	player.SetCharacterMovement(Character::Movement::walk);
	player.PrintCurrentMovementState();
	cout << endl;

	return 0;
}