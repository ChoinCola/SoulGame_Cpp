#include <iostream>

using namespace std;
// �ڷ����� ��ø�Ͽ� ����� �� ����ϴ� ����̴�.

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
			cout << name << "�� ���� �̵� ���� : idle, ���� �ӵ� : " << speed << endl;
			break;
		case Character::Movement::walk:
			cout << name << "�� ���� �̵� ���� : walk, ���� �ӵ� : " << speed << endl;
			break;
		case Character::Movement::Run:
			cout << name << "�� ���� �̵� ���� : Run, ���� �ӵ� : " << speed << endl;
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