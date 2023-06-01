#include <iostream>

using namespace std;
// �ڷ����� �ƴ� �Ű������� �޾ƿ��� ���ø�

template<typename T, unsigned int SIZE>
class MyArray
{
public:
	MyArray() = default;
	~MyArray() {}

	T& operator[](int index) {
		return arr2[index];
	}
private:
	T arr1[10]; // ����� ���鼭 ���¸� ����ִ°�.
	T arr2[SIZE];
};

int main()
{
	MyArray<int, 30> arr1;
	MyArray<float, 30u> arr2;

	for (int i = 0; i < 30; i++)
		arr1[i] = i;

	for (int i = 0; i < 30; i++)
		arr2[i] = i;

	for (int i = 0; i < 30; i++)
		cout << arr1[i] << ' ';
	std::cout << std::endl;

	for (int i = 0; i < 30; i++)
		cout << arr2[i] << ' ';
	std::cout << std::endl;

	return 0;
}

/*
	code ----> prePocess -----> compile -----> assemble -----> link -----> load -----> cpu
	03_.cpp			.i			.asm/.s			 .obj		  .exe
*/