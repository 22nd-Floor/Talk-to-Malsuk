#pragma once
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

#define TIME 200
#define SLOW 75
#define NORMAL 50
#define FAST 25
#define Enter system("title 엔터를 입력하시오"); while (1){ enter = getch(); if (enter == 13) break;} system("cls"); system("title Talk To Mirim")

// 커서 변경 함수 
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c);
// 페메 왼쪽 박스
void Left_Box(char str[]);

// 페메 오른쪽 박스
void Right_Box(char str[]);

// 페이스북 대화창 함수
void msg(int a);

// 개행 함수
void NewLine(int a);

// 안내 함수
void intro(char str[], int time);

// 말하기 함수 
void say(char str[], int time);

// 다음 말하기 함수 
void n_say(char str[], int time);

// 크레딧 함수
void credit();

// 헬프 함수
void help(int time);