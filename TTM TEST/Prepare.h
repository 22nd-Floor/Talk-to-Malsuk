#include "Super.h"

// Ÿ��Ʋ ȭ�� ���� ��ũ��
#define TITLECOLOR SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)		// ���� ��� �� �۾�
#define MAINCOLOR  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240)	// �� ��� ���� �۾�

#define PATH "C:\\Temp\\ttm.txt"

void Title(char *ver);	// system printMiddle TITLECOLOR MAINCOLOR kbhit Sleep getch
void Setting();			// SetCursorType system srand
void makeFiles(char *name);	// PATH
void readFiles();	// gotoxy printLetter checkName system makeFiles PATH SPEED
void printName();	// gotoxy printLetter system PATH SPEED
void setName();		// gotoxy printLetter checkName Enter GetCursorPosition system SPEED PATH
void checkName(char *name);	// strlen
void Modify();	// gotoxy printLetter getch system system