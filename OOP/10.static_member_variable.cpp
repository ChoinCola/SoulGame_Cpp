#include <iostream>

using namespace std;
// static������ ���� �� ���� �������� ��޵ȴ�. �������� ����.


class Test
{
public:
	int value = 1;
	// �� ������ �ν��Ͻ��� ����Ǳ� �� ������ ������ ������ �������� ����.
	static int count;
	// �� ������ ����Ǳ� ������ �������� �̱� ������, ������ ������ �Ҵ�����ش�. �׷��� �������� �̱� ������, class �������� �ʱ�ȭ�� �ȵǰ�
	// �������� �̱� ������ ���ι��� �ִ� ���α׷��� ���ۺ� ���� �ʱ�ȭ�� ���־�� �Ѵ�.
	static const int test = 10;
	// ������ �Ǿ ���� �� �ʱ�ȭ�� �����ϴ�.
};

int Test::count = 10;

int main()
{
	Test t1, t2;

	t1.value = 10;
	t2.value = 20;

	t1.count = 30;
	t2.count = 40;

	cout << &t1.count << " " << t1.count << endl;
	cout << &t2.count << " " << t2.count << endl;
	// �������� ����̱� ������ ��� class�� �ش� �����͸� �����ϰ� �ȴ�.
	
	cout << &Test::count << " " << Test::count << endl;
	// ��ü�� �������� �ʾƵ� ����� �� �ִ�. const �̱� ������ ������ �޾Ƽ�.
	return 0;
}