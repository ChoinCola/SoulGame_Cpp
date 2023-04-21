#include <iostream>

using namespace std;


class Data
{
public : 
	Data(int aData, int bData, int cData)
		:a(aData), b(bData), c(cData) // 생성과 동시에 값을 초기화 할 수 있다.
	{
		/*a = aData;
		b = bData;
		c = cdata;*/
	}
	void print()
	{
		cout << a << endl;
		cout << b << endl;
		cout << c << endl;
	}
private:
	const int a = 10;
	const int b = 10;
	const int c = 10;
};
int main()
{
	Data data1(20, 20, 20);
	data1.print();
	return 0;
}