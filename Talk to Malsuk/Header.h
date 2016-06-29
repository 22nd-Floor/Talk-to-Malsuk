#pragma once
#pragma warning (disable:4996)
#pragma warning (disable:4566)

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <wincon.h>

// �� �ӵ�
#define SLOW 75		// õõ��
#define NORMAL 50	// ����
#define FAST 25		// ������
// Ÿ��Ʋ ȭ�� ���� ��ũ��
#define TITLECOLOR SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)		// ���� ��� �� �۾�
#define MAINCOLOR  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240)	// �� ��� ���� �۾�
// �ð� ���� ��ũ�� �Լ� - ���� ����
#define SetTime1 time(&t); pt = localtime(&t); Hour[0] = pt->tm_hour; Min[0] = pt->tm_min
#define SetTime2(i, x) Hour[i] = Hour[i-1]; Min[i] = Min[i-1] + x; if (Min[i] >= 60){Min[i] -= 60; Hour[i]++;}
#define SetTime3(i, x, y) Hour[i] = Hour[i-1] + x; Min[i] = Min[i-1] + y; if (Min[i] >= 60){Min[i] -= 60; Hour[i]++;}

// �ð� ����ü
typedef struct tm TIME;

// TTM ������ ����ü
typedef struct filedata { char speed; char name[20]; } DATA;

// Ŀ�� Ÿ��
typedef enum cursor { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR;

// �޼���
typedef enum message { NAME, FIRSTMSG, SECONDMSG, THIRDMSG, FOURTHMSG, FIFTHMSG, SIXTHMSG } MESSAGE;

// ������
DATA Data;

// �ӵ�
int Speed;

// �̸�
char *Name;

// �ð�
int Hour[4]; 

// ��
int Min[4];

// �Լ��� - ������ C���Ͽ�
void SetCursorType(CURSOR c);
COORD GetCursorPosition();
void gotoxy(int x, int y);
void Setting();
void Enter(int x, int y);
void makeFiles(char *name, char speed);
DATA readFiles();
void printData();
void selectName();
void selectSpeed();
void Modify();
int toSpeed(char speed);
void LeftBox(char *str);
void RightBox(char *str);
void setTime();
void message(MESSAGE m);
void LineFeed(int a);
void printLetter(char *str, int time);
void intro(char *str, int time);
void say(char *str, int time);
void say_(char *str, int time);
void printTime(int hour, int min);
void Title();
void Credit();
void Help(int time);
int GetConsoleMiddle(int length);
void printMiddle(char *str, int lineNum);