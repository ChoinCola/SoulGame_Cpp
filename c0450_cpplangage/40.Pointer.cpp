#include <iostream>

int main()
{

	int* ptr = NULL; // c����� ��� ������ �ʱ�ȭ
	int* ptr1 = nullptr;
	int* ptr2(nullptr);
	int* ptr3{ nullptr }; // C++����� ������ �ʱ�ȭ

	std::nullptr_t  nptr; // �ʱ�ȭ ���� �ʾ������� ������ NULL�� �޴� ������.



	return 0;
}