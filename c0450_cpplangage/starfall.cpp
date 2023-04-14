#include <iostream>
#include <Windows.h>
#include <random>

#define WIDTH 15
#define HEIGTH 20

std::random_device rd;
std::mt19937 messenne(rd());
std::uniform_int_distribution<> randNUJm(1, WIDTH); // 동일한 확률로 1에서 10까지 나타나겠다는 의미

typedef struct Star
{
	int x;
	int y;
	bool isStar;

}Star;

typedef struct Player
{
	int x;
	int y;

}Player;

void gotoxy(int x, int y)
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

Star star[100];
Player player;

void init()
{
	for (int i = 0; i < WIDTH; i++)
		star[i].isStar = false;

	player.x = WIDTH / 2;
	player.y = HEIGTH;
}

void createStar()
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar == false)
		{
			star[i].x = randNUJm(messenne);
			star[i].y = 0;
			star[i].isStar = true;
			return;
		}
	}
}

void shoothingStar()
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar)
		{
			star[i].y++;
		}
	}
}

int score = 0;

void destoryStar()
{
	for (int i = 0; i < WIDTH; i++)
	{
		if (star[i].isStar && star[i].y > HEIGTH)
		{
			star[i].isStar = false;
			score += 100;
			printf("점수 : %d\n", score);
		}
	}
}

bool collidPlayer()
{
	for (int i = 0; i < WIDTH; i++) {
		if (star[i].isStar && star[i].y == player.y && star[i].x == player.x)
		{
			printf("\n\n점수 : %d\n", score);
			printf("게임 종료");
			return true;
		}
	}
	return false;
}

int isKeyDown(int key)
{
	return ((GetAsyncKeyState(key) & 0x8000) != 0);
}

void movePlayer()
{
	if (isKeyDown(VK_LEFT))
		player.x--;
	if (isKeyDown(VK_RIGHT))
		player.x++;
	if (isKeyDown(VK_UP))
		player.y--;
	if (isKeyDown(VK_DOWN))
		player.y++;
	
	if (player.x < 1)
		player.x = 1;
	if (player.x > WIDTH - 1)
		player.x = WIDTH - 1;
	if (player.y < 1)
		player.y = 1;
	if (player.y > HEIGTH)
		player.y = HEIGTH;
}

void printGame()
{
	system("cls");

	for (int i = 0; i < WIDTH; i++) {
		if (star[i].isStar)
		{
			gotoxy(star[i].x, star[i].y);
			printf("☆");
		}
	}
	gotoxy(player.x, player.y);
	printf("△");

	for (int i = 0; i < WIDTH + 1; i++)
	{
		gotoxy(i, 0);
		printf("■");
		for (int j = 1; j < HEIGTH + 1; j++)
		{
			gotoxy(i, j);
			if (i == 0 || i == WIDTH) {
				printf("■");
			}
		}
		gotoxy(i, HEIGTH + 1);
		printf("■");
	}
	
	
}

int main()
{
	init();

	while (!(collidPlayer()))
	{
		createStar();
		shoothingStar();
		destoryStar();

		movePlayer();

		printGame();

		Sleep(30);
	}
	return 0;
}