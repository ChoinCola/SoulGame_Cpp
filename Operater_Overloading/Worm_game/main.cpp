#include "stdafx.h"

void SetUP();
bool Update();
void Render();
void Food();

void gotoxy(int x, int y)
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	// xy값 갱신하는것.
}

enum Direction
{
	UP = 72,
	LEFT = 75,
	RIGHT = 77,
	DOWN = 80,
};

struct Pos
{
	int x;
	int y;
};

constexpr int boardRowMax = 20;
constexpr int boardColMax = 30;

constexpr float delaySec = 0.2f;

list<Pos> snake;
Direction snakeDir;

Pos foodPos;
Stopwatch currentTime;


int main()
{
	system("pasue");

	SetUP();

	while (Update())
	{
		Render();
	}
	return 0;
}

void SetUP()
{
	{
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		ConsoleCursor.bVisible = 0; // 커서 를 없앤다.
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor); // 설정값을 대입한다.
	}

	{
		Pos startPos = { boardColMax / 2, boardColMax / 2 };
		snake.push_back(Pos{ startPos.x, startPos.y });
		snake.push_back(Pos{ startPos.x - 1, startPos.y });
		snake.push_back(Pos{ startPos.x - 2, startPos.y });

		snakeDir = RIGHT;
	}

	Food();
}

bool Update()
{
	currentTime.Start();

	Pos next = snake.front(); // list 에서 fornt는 리스트의 맨 앞을 반환함.

	while(currentTime.GetElapsedTimeSec() < delaySec)
	{
		if (_kbhit() == true)
		{
			int key = _getch();
			if (key == 224)
			{
				key = _getch();
				switch (key)
				{
				case UP		: snakeDir = UP; break;
				case LEFT	: snakeDir = LEFT; break;
				case RIGHT	: snakeDir = RIGHT; break;
				case DOWN	: snakeDir = DOWN; break;
				}
			}
		}
	}

	switch (snakeDir)
	{
	case UP: next.y--; break;
	case LEFT: next.x--; break;
	case RIGHT: next.x++; break;
	case DOWN: next.y++; break;
	}

	{
		if (next.x <= 0 || next.x > boardColMax - 2) return false;
		if (next.x <= 0 || next.x > boardRowMax - 2) return false;

		for (const auto& body : snake)
		{
			if (next.x == body.x && next.y == body.y) return false;
		}

		if (foodPos.x == next.x && foodPos.y == next.y)
		{
			snake.push_back(snake.back()); // 리스트 맨 뒤를 반환 back();
			Food();
		}
	}

	snake.push_front(next);
	snake.pop_back();

	return true;
}

void Render()
{
	system("cls");

	{
		for (int row = 0; row < boardRowMax; row++)
		{
			gotoxy(0, row);
			cout << "※";
			gotoxy(boardColMax - 1, row);
			cout << "※";
		}

		for (int col = 0; col < boardColMax; col++)
		{
			gotoxy(col, 0);
			cout << "※";
			gotoxy(col, boardRowMax - 1);
			cout << "※";
		}
	}

	{
		for (auto iter = snake.begin(); iter != snake.end(); iter++) {
			gotoxy(iter->x, iter->y);

			if (iter == snake.begin())
				cout << "★";
			else
				cout << "☆";
		}
	}

	{
		static int score = 0;
		score += 100;

		gotoxy(foodPos.x, foodPos.y);
		cout << "＠";

		gotoxy(0, boardRowMax);
		cout << "Score : " << score << endl;
	}
}

void Food()
{
	foodPos.x = Math::Random(1, boardColMax - 2);
	foodPos.y = Math::Random(1, boardRowMax - 2);

	for (auto iter = snake.begin(); iter != snake.end(); iter++)
	{
		if (foodPos.x == iter->x && foodPos.y == iter->y)
		{
			iter = snake.begin();
			foodPos.x = Math::Random(1, boardColMax - 2);
			foodPos.y = Math::Random(1, boardRowMax - 2);
		}
	}
}
