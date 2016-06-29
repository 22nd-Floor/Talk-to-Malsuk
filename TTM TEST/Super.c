#include "Super.h"

// Ŀ�� ���� �Լ� 
void SetCursorType(CURSOR c)
{
	CONSOLE_CURSOR_INFO CurInfo;
	switch (c) {
	case NOCURSOR:
		CurInfo.dwSize = 1;
		CurInfo.bVisible = FALSE;
		break;
	case SOLIDCURSOR:
		CurInfo.dwSize = 100;
		CurInfo.bVisible = TRUE;
		break;
	case NORMALCURSOR:
		CurInfo.dwSize = 20;
		CurInfo.bVisible = TRUE;
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CurInfo);
}

// ���� Ŀ�� ��ǥ ã�� �Լ�
COORD GetCursorPosition()
{
	CONSOLE_SCREEN_BUFFER_INFO buffInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &buffInfo);

	return buffInfo.dwCursorPosition;
}

// Ŀ�� �̵� �Լ�
void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

// �ѱ��ھ� ��� �Լ� 
void printLetter(char *str, int time)
{
	int i = 0;

	while (str[i] != '\0'){
		if (str[i] < 0){
			Sleep(time);
			printf("%c%c", str[i], str[i + 1]);
			i += 2;
		}
		else{
			Sleep(time);
			printf("%c", str[i]);
			i++;
		}
	}
}

// �߰� �� �˾Ƴ��� private
int GetConsoleMiddle(int length)
{
	if (length % 2 == 0){
		return (80 - length) / 2;
	}
	else{
		return (80 - length - 1) / 2;
	}
}

// �߾� ���� ��� �Լ�
void printMiddle(char *str, int lineNum)
{
	gotoxy(GetConsoleMiddle(strlen(str)), lineNum); puts(str);
}

// ���� �Լ�
void Enter(int x, int y, int flag)
{
	if ((x < 0 || x >= 80) || (y < 0 || y >= 25)) return;
		 
	switch (flag){
	case 0:
		gotoxy(x, y); printLetter("<Enter>", SPEED);
		Sleep(500);
		gotoxy(x, y); printf("       ");
		Sleep(500);
		break;
	case 1:
		gotoxy(x, y); printf("<Enter>");
		Sleep(500);
		gotoxy(x, y); printf("       ");
		Sleep(500);
		break;
	}
	
	while (1){
		if (kbhit() == 1 && getch() == 13)
			break;
		
		gotoxy(x, y); printf("<Enter>");
		Sleep(500);
		gotoxy(x, y); printf("       ");
		Sleep(500);
	}
}