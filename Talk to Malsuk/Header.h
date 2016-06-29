#pragma once
#pragma warning (disable:4996)
#pragma warning (disable:4566)

#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <wincon.h>

// 말 속도
#define SLOW 75		// 천천히
#define NORMAL 50	// 보통
#define FAST 25		// 빠르게
// 타이틀 화면 설정 매크로
#define TITLECOLOR SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15)		// 검은 배경 흰 글씨
#define MAINCOLOR  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 240)	// 흰 배경 검은 글씨
// 시간 설정 매크로 함수 - 삭제 예정
#define SetTime1 time(&t); pt = localtime(&t); Hour[0] = pt->tm_hour; Min[0] = pt->tm_min
#define SetTime2(i, x) Hour[i] = Hour[i-1]; Min[i] = Min[i-1] + x; if (Min[i] >= 60){Min[i] -= 60; Hour[i]++;}
#define SetTime3(i, x, y) Hour[i] = Hour[i-1] + x; Min[i] = Min[i-1] + y; if (Min[i] >= 60){Min[i] -= 60; Hour[i]++;}

// 시간 구조체
typedef struct tm TIME;

// TTM 데이터 구조체
typedef struct filedata { char speed; char name[20]; } DATA;

// 커서 타입
typedef enum cursor { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR;

// 메세지
typedef enum message { NAME, FIRSTMSG, SECONDMSG, THIRDMSG, FOURTHMSG, FIFTHMSG, SIXTHMSG } MESSAGE;

// 데이터
DATA Data;

// 속도
int Speed;

// 이름
char *Name;

// 시간
int Hour[4]; 

// 분
int Min[4];

// 함수들 - 설명은 C파일에
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