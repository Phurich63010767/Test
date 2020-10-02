#include<iostream>
#include<conio.h>
#include<Windows.h>
using namespace std;

void gotoxy(int x, int y)
{
	COORD c = { x, y };
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void draw_ship()
{
	cout << "YEEET";
}

void erase_ship(int x, int y)
{
	gotoxy(x, y);
	cout << "     ";
}

void setcursor(bool visible)
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = 20;
	SetConsoleCursorInfo(console, &lpCursor);
}

void setcolor(int fg, int bg)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, bg * 16 + fg);
}

void draw_bullet(int x, int y)
{
	setcolor(2, 0);
	gotoxy(x, y);
	cout << "^";
}
void clear_bullet(int x, int y)
{
	setcolor(2, 0);
	gotoxy(x, y);
	cout << " ";
}

int main()
{
	char ch = '.';
	int x = 38, y = 20;
	int bx[5], by[5];
	int i = 0;
	int bullet[5];
	setcursor(false);
	setcolor(2, 7);
	gotoxy(x, y);
	draw_ship();
	for (int i = 0; i < 5; i++)
	{
		bullet[i] = 0;
	}
	do 
	{
		setcolor(2, 0);
		if (_kbhit())
		{
			ch = _getch();
			if ((ch == 97) && (x > 0))
			{
				erase_ship(x, y);
				setcolor(2, 7);
				gotoxy(--x, y);
				draw_ship();
			}
			if ((ch == 100) && (x < 80))
			{
				erase_ship(x, y);
				setcolor(2, 7);
				gotoxy(++x, y);
				draw_ship();
			}
			if (ch == 32)
			{
				for (int i = 0; i < 5; i++)
				{
					if (bullet[i] == 0)
					{
						bullet[i] = 1;
						bx[i] = x + 2;
						by[i] = y - 1 ;
						draw_bullet(bx[i], by[i]);
						break;
					}
				}
			}
			fflush(stdin);
		}
		for (int i = 0; i < 5; i++) 
		{
				if (bullet[i] > 0)
				{
					clear_bullet(bx[i], by[i]);
					if (by[i] == 0)
					{
						bullet[i] = 0;
					}
					else
					{
						draw_bullet(bx[i], --by[i]);
					}
				}
		}
		Sleep(100);
	} while (ch != 'x');
	system("pause");
	return 0;
}
