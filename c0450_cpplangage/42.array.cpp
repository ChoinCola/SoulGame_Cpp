#include <iostream>
#include <array>

int main()
{
	using namespace std;
	
	int arr1[] = { 1, 2, 3, 4, 5 }; // c���� �ʱ�ȭ �ϴ� ���
	int arr2[]{ 1, 2,3, 4, 5 }; // C++ ���� �߰��� �ʱ�ȭ ���
	// int arr3[](1,2,3,4,5); �� ���Ƴ��Ҵ�.

	/*
		STL : Standard Template Libraries
	*/
	// �迭�� �� �����ϰ� STL�� ����Ͽ� ������ �� �ִ�.

	//<> : templete
	std::array<int, 5> arr4; //int�� 5�� ������ array ����
	array<int, 5> arr5{ 1,2,3,4,5 }; // ���������� �ʱ�ȭ�ϱ�

	cout << arr5[0] << endl; // ������ ���� ���� ���� �����ϴ�.
	cout << arr5[1] << endl;
	cout << arr5.at(2) << endl; // ���� [] �� ���� ������� ������, ����ó���� �ϱ⶧����, ������ �� ���ɼ��� �� ����.
	cout << arr5.at(3) << endl; // ������ ����� ������ ������ ���ϰ� ���´�.
	cout << arr5.at(4) << endl;
	cout << arr5.size() << endl; // �迭�� ����� ������ �� �ִ�.

	cout << arr5[5] << endl;
	cout << arr5.at(5) << endl; // ��Ʈ���� ���´�.


	return 0;
}