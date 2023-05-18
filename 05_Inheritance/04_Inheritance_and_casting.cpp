#include <iostream>

using namespace std;

/*
	Up castirng
	�ڽ�Ŭ������ �� ũ��. �׷����� ����������, �θ�Ŭ������ ���� �����ޱ� ������ �θ�Ŭ������ �� ũ�ٰ� ����.
	���������� �� ū �������� ���°� �̱� ������, �ڽ� -> �θ� ������ ���°� �� UP casting�̶�� �Ѵ�.

	Down casting
	�θ�Ŭ������ �����Ͱ� ����Ű�� ��ü�� �ڽ�Ŭ������ �����ͷ� ����Ű�� �ȴ�.
	�θ�Ŭ������ �����Ͱ� �θ��� ��ü�� ����ų������, �ڽ�Ŭ������ ���� ����ų �� ���Եȴ�.
*/

class Snack {};

class Chitos : public Snack {};
class ChocoChip : public Snack {};
class Homerunball : public Snack {};

int main()
{
	Snack* chocochip = new ChocoChip(); // ���ɽ���(Up casting)
	Snack* chitos = new Chitos();

	Snack* sneck[2] = { chitos, chocochip }; // ���ɽ����� ����ؼ� �迭�� ����� �����ϴ�. ������ �����ϴ�. ������ �ִ°� ���� ������Ѵ�.

	Chitos* test = static_cast<Chitos*>(chitos); // �ٿ��ɽ��� ���� ��������� �ʴ´�.

	// Chitos* cc = new Snack(); // error�� �ȴ�. �Ʒ����� ���θ� �ɽ����� �ȴ�.

	return 0;
}