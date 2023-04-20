#include <iostream>

using namespace std;

class Data
{

public:
	void SetData(int hpData, int attackData, float expData)
	{
		hp = hpData;
		attack = attackData;
		exp = expData;
	}

	void setData2(Data data)
	{
		hp = data.hp;
		attack = data.attack;
		exp = data.exp;
		// ���� Ŭ���� �� �����̺� �̾ ������ �����ϴ�.
	}
	
	int GetHp() { return hp; }
	int GetAttack() { return attack; }
	// Ŭ���� ����� ���α׷����� ��ü�����̱� ������, ���������� �� �ٸ��� private �ڵ�� �� ��ü���� ����ó���� ¥�� �������Ѵ�.
	// ������尡 �߻��� �� ������ �����ϴ��� ������ ���̴� �� �� �� �߿��ϴٰ� ����°� �� ��ü������ ��Ģ�̴�.

private:
	int hp;
	int attack;
	float exp;

};

class FruitSeller
{
	int applePrice;
	int numofApple;
	int Mymoney;

public:
	void InitMembers(int price, int num, int money) {
		applePrice = price;
		numofApple = num;
		Mymoney = money;
	}

	int SaleApples(int money) {
		int num = money / applePrice;
		numofApple -= num;
		Mymoney += money;
		return num;
	}

	void ShowsaleResult() {
		cout << "���� ��� : " << numofApple << endl;
		cout << "�Ǹ� ���� : " << Mymoney << endl;
	}
};

class FruitBuyer
{
	int Mymoney;
	int numofApples;

public:
	void InitMemebers(int money) {
		Mymoney = money;
		numofApples = 0;
	}

	void BuyApples(FruitSeller& seller, int money) {
		numofApples += seller.SaleApples(money);
		Mymoney -= money;
	}

	void ShowBuyResult()
	{
		cout << "���� �ܾ� : " << Mymoney << endl;
		cout << "��� ���� : " << numofApples << endl;
	}
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);

	FruitBuyer buyer;
	buyer.InitMemebers(5000);

	buyer.BuyApples(seller, 2000);

	cout << "���� �Ǹ��� ��Ȳ" << endl;
	seller.ShowsaleResult();

	cout << "���� ������ ��Ȳ" << endl;
	buyer.ShowBuyResult();

	return 0;
}