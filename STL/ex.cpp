#include <iostream>
#include <list>

using namespace std;
// ����Ʈ�� ���� ������ �ſ� ����, �迭�� ���������� �����ϰԵȴ�.
// �ڷᱸ���� �������̺귯��
int main()
{
	list<int> list;

	for (int i = 0; i < 10; i++)
		list.push_back(i);

	// ������� for�� �� ����ϸ� ���ϰ� �̿��� �� �ִ�.
	for (const auto& ele : list)
		cout << ele << " ";

	return 0;
}