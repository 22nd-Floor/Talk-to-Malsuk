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
#define Enter system("title ���͸� �Է��Ͻÿ�"); while (1){ enter = getch(); if (enter == 13) break;} system("cls"); system("title Talk To Mirim")

// Ŀ�� ���� �Լ� 
typedef enum { NOCURSOR, SOLIDCURSOR, NORMALCURSOR } CURSOR_TYPE;
void setcursortype(CURSOR_TYPE c);
// ��� ���� �ڽ�
void Left_Box(char str[]);

// ��� ������ �ڽ�
void Right_Box(char str[]);

// ���̽��� ��ȭâ �Լ�
void msg(int a);

// ���� �Լ�
void NewLine(int a);

// �ȳ� �Լ�
void intro(char str[], int time);

// ���ϱ� �Լ� 
void say(char str[], int time);

// ���� ���ϱ� �Լ� 
void n_say(char str[], int time);

// ũ���� �Լ�
void credit();

// ���� �Լ�
void help(int time);