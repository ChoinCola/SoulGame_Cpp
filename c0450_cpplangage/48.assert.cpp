#include <iostream>
#include <cassert> // assert�� ����ϱ� ���� ���̺귯��

using namespace std;
// �ܿ���
// ����� ��忡�� ����üũ�� �ϱ� ���� ����.
int main()
{
	int x;
	cin >> x;

	// ���� ���ڰ� 0�� ��� ��Ʈ����ʹ�.
	// ���� if���� ���������, assert�� ����ϸ� ���� ��Ʈ�� �� �ִ�.

	assert(x != 0);
	// Ư�� ������ ���� ������ üũ�Ͽ� ��Ʈ�� �� �ִ�.
	// ��, ����� ��忡���� ���۵ȴ�. ���κ� ����׸� ����Ʈ�� �ٲٸ� �������� �ʴ´�.

	//static_assert(false); // ������ ������ ������ ���鼭 ������. 
	
	const int x1 = 6;
	const int y1 = 7;
	static_assert(x1 > y1, "x1 is bigger than y1"); // ������ ���� üũ�� �� �ִ�. C++���� �̸� ������ ����ش�.

	return 0;
}