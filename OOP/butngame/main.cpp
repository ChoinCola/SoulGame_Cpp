#include "stdafx.h"

#define ARROWNUM 10
#define SUCCESS 5
#define TIMELIMIT 10

void Start();
void ReSet();
bool Update();
void Render();

Stopwatch current_time;

int main()
{
	Start();
	ReSet();
	while (Update())
	{
		Render();
	}

	return 0;
}
enum class Arrow
{
	UP = 72,
	Left = 75,
	Right = 77,
	Down = 80
};

Arrow answer[ARROWNUM];

int curSuccess = 0;
int curArrow = 0;

void Start()
{
	system("title TypingGame"); // 콘솔창의 타이틀을 띄운다.
	system("mode con:cols=60 lines=30");// 콘솔창의 크기를 제한한다.
	{
		HANDLE hConsole;
		CONSOLE_CURSOR_INFO ConsoleCursor;

		hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		ConsoleCursor.bVisible = 0; // 커서 를 없앤다.
		ConsoleCursor.dwSize = 1;

		SetConsoleCursorInfo(hConsole, &ConsoleCursor); // 설정값을 대입한다.
	}

	cout << "######### 화살표 타이핑 게임!!#########" << endl;

	system("pause"); // 다른 키를 누르면 시작하게 만듬.
	system("cls");
}

void ReSet()
{
	current_time.Start();
	curArrow = 0;

	for (int i = 0; i < ARROWNUM; i++) {
		int arrow = Math::Random(0, 3);

		switch (arrow)
		{
		case 0:
		{
			answer[i] = Arrow::UP;
			break;
		}
		case 1:
		{
			answer[i] = Arrow::Down;
			break;
		}
		case 2:
		{
			answer[i] = Arrow::Left;
			break;
		}
		case 3:
		{
			answer[i] = Arrow::Right;
			break;
		}
		default: break;
		}
	}
}

bool Update()
{
	if (_kbhit())
	{
		int key;

		key = _getch();

		if (key == 224)
		{
			key = _getch();

			if (answer[curArrow] == static_cast<Arrow>(key)) // Static_cast 에 대해 정리하기.
			{
				++curArrow;

				if (ARROWNUM <= curArrow) {
					ReSet();
					++curSuccess;

					if (SUCCESS <= curSuccess)
					{
						cout << "승리!!" << endl;
						return false;
					}
				}
			}
			else
			{
				curArrow = 0;
			}
		}
	}

	if (TIMELIMIT <= current_time.GetElapsedTimeSec())
	{
		cout << "패배!!" << endl;
		return false;
	}

	return true;
}

void Render()
{
	system("cls");

	cout << "TIME : ";
	for (int i = 0; i < TIMELIMIT; i++) {
		if (current_time.GetElapsedTimeSec() < i)
			cout << "■";
	}
	cout << endl;

	for (int i = 0; i < ARROWNUM; i++) {
		if (curArrow <= i)
		{
			switch (answer[i])
			{
			case Arrow::UP:
			{
				cout << "↑";
				break;
			}
			case Arrow::Down:
			{
				cout << "↓";
				break;
			}
			case Arrow::Left:
			{
				cout << "←";
				break;
			}
			case Arrow::Right:
			{
				cout << "→";
				break;
			}
			}
		}
		else
		{
			cout << "☆";
		}
	}
	cout << endl;

	cout << "남은 횟수 : " << SUCCESS - curSuccess << endl;
}
