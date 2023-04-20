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
		// 같은 클래스 는 프라이빗 이어도 접근이 가능하다.
	}
	
	int GetHp() { return hp; }
	int GetAttack() { return attack; }
	// 클래스 기반의 프로그래밍은 객체지향이기 때문에, 절차지향형 과 다르게 private 코드는 그 자체에서 내부처리만 짜게 만들어야한다.
	// 오버헤드가 발생할 수 있지만 감안하더라도 오류를 줄이는 것 이 더 중요하다고 여기는것 이 객체지향의 원칙이다.

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
		cout << "남은 사과 : " << numofApple << endl;
		cout << "판매 수익 : " << Mymoney << endl;
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
		cout << "현재 잔액 : " << Mymoney << endl;
		cout << "사과 개수 : " << numofApples << endl;
	}
};

int main()
{
	FruitSeller seller;
	seller.InitMembers(1000, 20, 0);

	FruitBuyer buyer;
	buyer.InitMemebers(5000);

	buyer.BuyApples(seller, 2000);

	cout << "과일 판매자 현황" << endl;
	seller.ShowsaleResult();

	cout << "과일 구매자 현황" << endl;
	buyer.ShowBuyResult();

	return 0;
}