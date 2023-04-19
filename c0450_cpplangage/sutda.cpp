#include <iostream>
#include <string>
#include <Windows.h>

enum JOKBO
{
	KK_0,
	KK_9 = 9,
	SR,
	JS,
	JB,
	GB,



};

struct Hwatoo
{
	int month;
	std::string shape;
};

struct Player
{
	std::string name;
	int money;
	int jokbo;
	Hwatoo card[2];
};

void Swap(Hwatoo* deck, int sour, int dest)
{
	Hwatoo temp = deck[sour];
	deck[sour] = deck[dest];
	deck[dest] = temp;
}

void Shuffle(Hwatoo* deck)
{
	for (int i = 0; i < 1000; i++)
	{
		int sour = rand() % 20;
		int dest = rand() % 20;
		Swap(deck, sour, dest);
	}
}

void MakeJokbo(int playernum, Player* players)
{
	for (int i = 0; i < playernum; i++) {
		if (players[i].card[0].month == players[i].card[1].month) {
			players[i].jokbo = players[i].card[0].month + (DD_1 - 1)
		}
		else if (players[i].card[0].shape == "ÎÃ" && players[i].card[1].shape == "ÎÃ") {
			players[i].jokbo = KD;
		}
		else {
			players[i].jokbo = KK_0 + (players[i].card[0].month + players[i].card[1].month) % 10;
				if (players[i].card[0].month == 1)
				{
					if (players[i].card[1].month == 2)
					{
						players[i].jokbo = AL;
					}
					else if (players[i].card[1].month = 9)
					{
						players[i].jokbo = GB;
					}
					else if (players[i].card[1].month == 10)
					{
						players[i].jokbo = JB;
					}
				}
				else
				{
					if (players[i].card[0].month == 4)
					{
						if (players[i].card[1].month == 10)
						{
							players[i].jokbo = JS;
						}
						else if (players[i].card[1].month == 6)
						{
							players[i].jokbo = SR;
						}
					}
				}
		}
	}
}


void PrintPlayer(int playernum, Player* players)
{
	for (int i = 0; i < playernum; i++) {
		std::cout << players[i].name << "\t" <<
			players[i].card[0].month << players[i].card[0].shape << "\t" <<
			players[i].card[1].month << players[i].card[1].shape << "\t" <<
			players[i].money << "\t";

		if (players[i].jokbo == KD) {
			std::cout << players[i].card[0].month << players[i].card[1].month << "ÎÃ¶¯"
		}
		else if (players[i].jokbo < DD_1) {
			if (players[i].jokbo == AL) {
				std::cout << "¾Ë¸®" << std::endl;
			}
			else if (players[i].jokbo == DS) {
				std::cout << "µ¶»ç" << std::endl;
			}
			else if (players[i].jokbo == GB) {
				std::cout << "±¸»æ" << std::endl;
			}
			else if (players[i].jokbo == JB) {
				std::cout << "Àå»æ" << std::endl;
			}
			else if (players[i].jokbo == JS) {
				std::cout << "Àå»ç" << std::endl;
			}
			else if (players[i].jokbo == SR) {
				std::cout << "¼¼·ú" << std::endl;
			}
			else
				std::cout << players[i].jokbo << "²ý" << std::endl;
		}
		else
		{
			std::cout << players[i].jokbo - 20 << "¶¯" << std::endl;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));

	int playernum;
	Player* players;
	int bet = 0;

	while (true) {
		std::cout << "ÇÃ·¹ÀÌ¾î ¼ö : ";
		std::cin >> playernum;

		if (playernum > 10) {
			std::cout << "´Ù½Ã ÀÔ·ÂÇÏ¼¼¿ä" << std::endl;
			continue;
		}
		else
			break;
	}

	players = new Player[playernum];

	for (int i = 0; i < playernum; i++) {
		std::string name;
		std::cout << i + 1 << "¹øÂ° ÀÌ¸§ : ";
		std::cin >> name;
		players[i].name = name;
		players[i].money = 10000;
	}

	Hwatoo deck[20];

	for (int i = 0; i < 20; i++) {
		deck[i].month = i % 10 + 1;
		deck[i].shape = "êÅ";
	}
	deck[0].shape = deck[2].shape = deck[7].shape = "ÎÃ";

	int start = 0;
	while (not start) {
		Shuffle(deck);

		for (int i = 0; i < playernum; i++) {
			bet += 500;
			players[i].money -= 500;

			players[i].card[0] = deck[i];
			players[i].card[0] = deck[i + 10];
			
			if (players[i].card[0].month > players[i].card[1].month) {
				Swap(players[i].card, 0, 1);
			}
		}

		MakeJokbo(playernum, players);

		int max = KK_0;
		int winner = 0;

		for (int i = 0; i < playernum; i++) {
			if (players[i].jokbo > max) {
				max = players[i].jokbo;
				winner = 1;
			}
			else if (players[i].jokbo == max)
				winner++;
		}

		for (int i = 0; i < playernum; i++) {
			if (players[i].jokbo == max) {
				players[i].money += bet / winner;
				std::cout << players[i].name << "\t";
			}
		}
		std::cout << "½Â¸®!!" << std::endl;

		PrintPlayer(playernum, players);
		bet = 0;
		std:: cout << std::endl;

		std::cout << "0. °è¼Ó 1. ³ª°¡±â =>";
		std::cin >> start;
		Sleep(1000);
		system("cls");
	}

	return 0;
}